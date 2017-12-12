#ifndef AMAZOOM_WAREHOUSE_SIMULATION_DYNAMICINSTRUCTIONQUEUE_H
#define AMAZOOM_WAREHOUSE_SIMULATION_DYNAMICINSTRUCTIONQUEUE_H

#include <deque>
#include <condition_variable>
#include <mutex>
#include "common.h"

namespace warehouse {
    /**
    * Dynamically-sized Queue Implementation
    *
    * Does not block when adding items
    */
    class DynamicInstructionQueue{
        std::deque<BotInstructionBase> buff_;
        std::mutex mutex_;
        std::condition_variable cv_;

    public:
        /**
         * Creates the dynamic queue
         */
        DynamicInstructionQueue() :
                buff_(), mutex_(), cv_() {}

        void add(const BotInstructionBase &order) {
            {
                std::unique_lock<std::mutex> lock(mutex_);
                buff_.push_back(order);
            }
            cv_.notify_one();


        }

        BotInstructionBase get() {
            // get first item in queue
            {
                std::cout << "BEFORE MUTEX BEFORE MUTEX BEFORE MUTEX BEFORE MUTEX BEFORE MUTEX";
                std::unique_lock<std::mutex> lock(mutex_);
                std::cout << "AFTER MUTEX AFTER MUTEX AFTER MUTEX AFTER MUTEX";
                cv_.wait(lock, [&] () {return !buff_.empty();});

                BotInstructionBase out = buff_.front();
                buff_.pop_front();
                return out;
            }

        }
    };
}
#endif //AMAZOOM_WAREHOUSE_SIMULATION_DYNAMICINSTRUCTIONQUEUE_H
