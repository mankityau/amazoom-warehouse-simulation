#include "../jsonconverterinterface.h"
#include "request.cpp"
#include "response.cpp"

namespace api{
    class JsonConverter : public JsonConverterInterface {
    private:
        std::string parseFunctionName(const JSON &json) const {
            return json[FUNCTION_NAME];
        }
        JSON toJSON(const std::vector<int> merchandiseId) const {
            JSON json;
            json[MERCHANDISE_ID] = merchandiseId;
            return json;
        }

        JSON toJSON(const api::OrderRequest orderRequest) const {
            JSON json;
            json[FUNCTION_NAME] = ORDER_FUNCTION;
            json[PARAMETERS] = toJSON(orderRequest.merchandiseId);
            return json;
        }

        JSON toJSON(const api::OrderResponse orderResponse) const {
            JSON json;
            json[FUNCTION_NAME] = ORDER_FUNCTION;
            json[PARAMETERS][SUCCESS] = orderResponse.success;
            json[PARAMETERS][ORDER_ID] = orderResponse.orderId;
            return json;
        }

        std::vector<int> parseMerchandiseId(const JSON &j) const {
            std::vector<int> ids;
            for(const auto &merchandiseId: j[MERCHANDISE_ID]){
                ids.push_back(merchandiseId);
            }
            return ids;
        }

        api::OrderRequest parseOrderRequest(const JSON &jOrder) const {
            std::vector<int> merchandiseId = parseMerchandiseId(jOrder[PARAMETERS]);
            return api::OrderRequest(merchandiseId);
        }

        api::OrderResponse praseOrderResponse(const JSON &jOrderResp) const {
            int orderId = jOrderResp[PARAMETERS][ORDER_ID];
            bool success = jOrderResp[PARAMETERS][SUCCESS];
            return api::OrderResponse(success, orderId);
        }

    public:
        JSON toJSON(const api::RequestInterface &req) const {
            if (req.functionName() == ORDER_FUNCTION) {
                return toJSON((OrderRequest &) req);
            }

        }

        JSON toJSON(const api::ResponseInterface &resp) const {
            if (resp.functionName() == ORDER_FUNCTION){
                return toJSON((OrderResponse &) resp);
            }
        }

        std::unique_ptr<RequestInterface> parseRequest(const JSON &jreq) const{
            std::string functionName = parseFunctionName(jreq);
            if (functionName == ORDER_FUNCTION) {
                return std::unique_ptr<RequestInterface>(new OrderRequest(parseOrderRequest(jreq)));
            }
        }

        std::unique_ptr<ResponseInterface> parseResponse(const JSON &jresp) const{
            std::string functionName = parseFunctionName(jresp);
            if (functionName == ORDER_FUNCTION){
                return std::unique_ptr<ResponseInterface>(new OrderResponse(praseOrderResponse(jresp)));
            }

        }
    };
}