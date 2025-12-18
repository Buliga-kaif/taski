#include "Client.h"

Client::Client(const std::string& id, const std::string& name)
    : passportId(id), fullName(name) {}

std::string Client::getPassportId() const {
    return passportId;
}

std::string Client::getFullName() const {
    return fullName;
}
