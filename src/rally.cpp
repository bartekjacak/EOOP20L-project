#include "rally.hpp"

Rally::Rally(const std::string& name, const std::vector<Driver>& drivers):
    _name(name), _drivers(drivers) {};
Rally::~Rally() = default;

Driver Rally::getDriver(int index) const {
//    if (index < 1 || index > _drivers.size()) {
//        return std::nullopt;
//        throw
//    }

    return _drivers.at(index - 1);
};

RallyEdition Rally::performNextEdition(Simulator simulator) const {
    return simulator.simulateRallyEdition(1, _drivers);
}
