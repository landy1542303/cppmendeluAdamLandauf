#include "Train.h"

Train::Train(const std::string& code, const std::string& origin, 
             const std::string& destination, const std::string& departureTime)
    : code(code), origin(origin), destination(destination), departureTime(departureTime) {}

std::string Train::getCode() const {
    return code;
}

std::string Train::getOrigin() const {
    return origin;
}

std::string Train::getDestination() const {
    return destination;
}

std::string Train::getDepartureTime() const {
    return departureTime;
}