#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "produs.h"

class ValidationException {
private:
    string message;
public:
    ValidationException() = default;

    void addMessage(const string& msg) {
        if (!message.empty()) {
            message += "\n";
        }
        message += msg;
    }

    string getMessage() const {
        return message;
    }
};

class Validator {
    public:
    Validator(const Validator& other) = delete;
    Validator() = default;

    void valideaza(const Produs& produs) const;
};

#endif //VALIDATOR_H
