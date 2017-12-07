#ifndef AMAZOOM_WAREHOUSE_SIMULATION_JSONOVERSOCKETAPIINTERFACE_H
#define AMAZOOM_WAREHOUSE_SIMULATION_JSONOVERSOCKETAPIINTERFACE_H
#include <cpen333/process/socket.h>

#include "jsonconverterinterface.h"

namespace api{
    class JsonOverSocketApiInterface{
    private:
        cpen333::process::socket socket_;

        // Fixed message type
        //   NOTE: constants like this don't actually have a memory address,
        //         so they can only be passed by value
        static const char JSON_ID = 0x55;

        /**
         * Writes the JSON info to the socket, NOT including the JSON byte
         * indicator (for symmetry with the read operation)
         *
         * @param j JSON content
         * @return true if write successful, false otherwise
         */
        bool sendJSON(const JSON &j) {

            // dump to string
            std::string jsonstr = j.dump();

            // encode JSON size, big endian format
            //   (most-significant byte in buff[0])
            char buff[4];
            size_t size = jsonstr.size() + 1;           // one for terminating zero
            for (int i = 4; i-- > 0;) {
                // cut off byte and shift size over by 8 bits
                buff[i] = (char) (size & 0xFF);
                size = size >> 8;
            }

            // write contents
            bool success = socket_.write(buff, 4);   // contents size
            success &= socket_.write(jsonstr);        // contents

            return success;
        }

        /**
         * Reads a string consisting of exactly size bytes
         * @param str string to append to
         * @param size number of bytes
         * @return true if successful
         */
        bool readString(std::string &str, size_t size) {

            char cbuff[256];

            int remainingSize = size;
            while (remainingSize > 0) {
                int readingSize = remainingSize >= 256 ? 256 : remainingSize;
                if (!socket_.read(cbuff, readingSize)){
                    return false;
                }

                for (int i = 0; i < readingSize; i ++){
                    str += cbuff[i];
                }
                remainingSize -= 256;
            }

            //======================================================
            // TODO: read and append to str in chunks of 256 bytes
            //======================================================

            return true;
        }

        /**
         * Reads and populates a JSON message
         * Assumes the initial JSON indicator byte has already been read, which
         * is why we are now in this method
         *
         * @param jout JSON object to populate
         * @return true if successful, false if error
         */
        bool recvJSON(JSON &jout) {

            // receive 4-byte size
            char buff[4];
            if (!socket_.read_all(buff, 4)) {
                return false;
            }

            //=================================================
            // TODO: Decode 4-byte big-endian integer size
            //=================================================
            int size = 0;
            for (int i = 0; i < 4; ++ i) {
                size_t charValue = (size_t) buff[i] & 0xFF;
                size += charValue * std::pow(32, 3 - i);
            }

            // read entire JSON string
            std::string str;
            if (!readString(str, size)) {
                return false;
            }

            // parse JSON
            jout = JSON::parse(str);

            return true;
        }

    protected:
        virtual api::JsonConverterInterface* jsonConverter() const = 0;
        
    public:
        /**
        * Main constructor, takes ownership of socket
        * @param socket
        */
        JsonOverSocketApiInterface(cpen333::process::socket &&socket) :
                socket_(std::move(socket)) {}

        /**
        * Sends a message by writing the data to the socket
        * @param msg message to write
        * @return true if successful, false if error
        */
        bool sendRequest(const RequestInterface &req) {
            JSON jreq = jsonConverter()->toJSON(req);

            // write single JSON byte
            char id = JSON_ID;
            if (!socket_.write(&id, 1)) {
                return false;
            }
            // write JSON content
            return sendJSON(jreq);
        }

        /**
         * Reads a message from the socket.  The returned message is
         * contained within a smart pointer to preserve polymorphism
         * and automatically handle freeing of memory resources.  The
         * returned smart pointer can be used similarly to a real
         * pointer, except that it cannot be copied.  You can, however,
         * access members by using the -> operator, and dereference it
         * using the * operator.
         *
         * @return parsed message, nullptr if an error occurred
         */
        std::unique_ptr<RequestInterface> receiveRequest() {

            // parse first byte, ensure it is of JSON type
            char id;
            if (!socket_.read_all(&id, 1) || id != JSON_ID) {
                return nullptr;
            }

            // if it is a JSON string, parse into a message
            JSON jreq;
            if (!recvJSON(jreq)) {
                return nullptr;
            }

            return jsonConverter()->parseRequest(jreq);
        }
        
        bool sendResponse(const ResponseInterface &resp) {
            JSON jresp = jsonConverter()->toJSON(resp);

            // write single JSON byte
            char id = JSON_ID;
            if (!socket_.write(&id, 1)) {
                return false;
            }
            // write JSON content
            return sendJSON(jresp);
        }

        std::unique_ptr<ResponseInterface> receiveResp() {

            // parse first byte, ensure it is of JSON type
            char id;
            if (!socket_.read_all(&id, 1) || id != JSON_ID) {
                return nullptr;
            }

            // if it is a JSON string, parse into a message
            JSON jresp;
            if (!recvJSON(jresp)) {
                return nullptr;
            }

            return jsonConverter()->parseResponse(jresp);
        }
    };
}
#endif //AMAZOOM_WAREHOUSE_SIMULATION_JSONOVERSOCKETAPIINTERFACE_H
