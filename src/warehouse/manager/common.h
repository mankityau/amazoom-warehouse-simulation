#ifndef AMAZOOM_WAREHOUSE_SIMULATION_COMMON_H
#define AMAZOOM_WAREHOUSE_SIMULATION_COMMON_H

#include <string>
#include <tuple>

namespace warehouse {
    enum BotInstructionType {
        deliver, restock, poison
    };

    struct Location {
        const int x;
        const int y;
        const int z;

        const Location& operator=(const Location& other) {
            if (this != &other) {
                return other;
            }
            return *this;
        }
    };

    std::string toString(Location l){
        std::string s = "Location: ";
        s.append(std::to_string(l.x)).append(", ").append(std::to_string(l.y)).append(", ").append(std::to_string(l.z));
        return s;
    };

    struct Path{
        const Location init;
        const Location mid0;
        const Location mid1;
        const Location end;
    };

    struct LoadingBay{
        const int id;
    };

    std::string toString(LoadingBay l){
        std::string s = "LoadingBay: ";
        s.append(" id: ").append(std::to_string(l.id));
        return s;
    }

    struct Dimension{
        const int x;
        const int y;
        const int z;
    };

    struct ShelfSpace{
        const int shelfId;
        const int maxWeightCapacity;
        const int row;
        const int col;

        bool operator<(const ShelfSpace& other) const {
            return std::tie(shelfId, row, col, maxWeightCapacity)
                   < std::tie(other.shelfId, other.row, other.col, other.maxWeightCapacity);
        }
    };

    std::string toString(ShelfSpace sh){
        std::string s = "ShelfSpace:";
        s.append(" id: ").append(std::to_string(sh.shelfId));
        s.append(" row: ").append(std::to_string(sh.row));
        s.append(" col: ").append(std::to_string(sh.col));
        return s;
    }

    struct Merchandise{
        const int id;
        const std::string name;
        const int weight;

        bool operator<(const Merchandise& other) const {
            return std::tie(id, name, weight)
                   < std::tie(other.id, other.name, other.weight);
        }
    };

    std::string toString(Merchandise m){
        std::string s = "Merchandise: ";
        s.append(" id: ").append(std::to_string(m.id));
        s.append(" name: ").append(m.name);
        return s;
    };

    struct BotInstructionBase {
        const BotInstructionType botInstructionType ;
        const ShelfSpace targetShelfSpace;
        const Merchandise merchandise;
        const LoadingBay loadingBay;

        const BotInstructionBase& operator=(const BotInstructionBase& other) {
            if (this != &other) {
                return other;
            }
            return *this;
        }
    };

    std::string toString(BotInstructionBase b) {
        std::string s = "BotInstructionBase: ";
        s.append(toString(b.targetShelfSpace));
        s.append(toString(b.merchandise));
        s.append(toString(b.loadingBay));
        return s;
    }

    struct BotInstruction{
        const BotInstructionType botInstructionType ;
        const Path pathToGetItem;
        const Path pathToPutLoad;
        const ShelfSpace shelfSpace;
        const Merchandise merchandise;

        const BotInstruction& operator=(const BotInstruction& other) {
            if (this != &other) {
                return other;
            }
            return *this;
        }
    };
}
#endif //AMAZOOM_WAREHOUSE_SIMULATION_COMMON_H
