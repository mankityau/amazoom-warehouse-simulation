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
                std::lock_guard<decltype(mutex_)> lock(mutex_);
                buff_.push_back(order);
            }
            cv_.notify_one();


        }

        BotInstructionBase get() {
            // get first item in queue
            {
                std::unique_lock<decltype(mutex_)> lock(mutex_);
                cv_.wait(lock, [&] () {return !buff_.empty();});

                BotInstructionBase out = buff_.front();
                buff_.pop_front();
                return out;
            }

        }
    };
}
#endif //AMAZOOM_WAREHOUSE_SIMULATION_DYNAMICINSTRUCTIONQUEUE_H
