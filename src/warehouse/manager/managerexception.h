#ifndef AMAZOOM_WAREHOUSE_SIMULATION_MANAGEREXCEPTION_H
#define AMAZOOM_WAREHOUSE_SIMULATION_MANAGEREXCEPTION_H

namespace warehouse {
    class InitManagerException : public std::exception {
        const char* what() noexcept {
            return "Failed to init Manager";
        }
    };
}
#endif //AMAZOOM_WAREHOUSE_SIMULATION_MANAGEREXCEPTION_H
