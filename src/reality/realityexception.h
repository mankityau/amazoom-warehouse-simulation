#ifndef AMAZOOM_WAREHOUSE_SIMULATION_REALITYEXCEPTION_H
#define AMAZOOM_WAREHOUSE_SIMULATION_REALITYEXCEPTION_H

#include <exception>

namespace reality {
    class ZeroDimensionException : public std::exception {
        const char* what() noexcept {
            return "Dimension cannot be zero";
        }
    };

    class SpaceOccupiedException : public std::exception {
        const char* what() noexcept {
            return "Space is occupied";
        }
    };

    class TooBigDimensionException : public std::exception {
        const char* what() noexcept {
            return "Dimension too big";
        }
    };
}

#endif //AMAZOOM_WAREHOUSE_SIMULATION_REALITYEXCEPTION_H
