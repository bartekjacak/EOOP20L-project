#include "Rally.hpp"

Rally::Rally(const std::string& name_, const std::vector<Driver>& drivers_):
    name(name_), drivers(drivers_) {};

Driver Rally::getDriver(int index) const {
//    if (index < 1 || index > _drivers.size()) {
//        return std::nullopt;
//        throw
//    }

    return drivers.at(index - 1);
};

RallyEdition Rally::performNextEdition(const Simulator& simulator) const {
    return simulator.simulateRallyEdition(1, drivers);
}
