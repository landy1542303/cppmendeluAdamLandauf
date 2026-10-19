#ifndef TRAIN_H
#define TRAIN_H

#include <string>

class Train {
private:
    std::string code;
    std::string origin;
    std::string destination;
    std::string departureTime;

public:
    Train(const std::string& code, const std::string& origin, 
          const std::string& destination, const std::string& departureTime);

    std::string getCode() const;
    std::string getOrigin() const;
    std::string getDestination() const;
    std::string getDepartureTime() const;
};

#endif