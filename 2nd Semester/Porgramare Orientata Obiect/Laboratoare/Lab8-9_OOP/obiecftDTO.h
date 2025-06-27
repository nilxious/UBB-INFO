#ifndef DTO_H
#define DTO_H

#include <string>

class DTO {
private:
    std::string type;
    int count;

public:
    DTO() : type(""), count(0) {}

    DTO(const std::string& type, int count) : type(type), count(count) {}

    const std::string& getType() const {
        return type;
    }

    int getCount() const {
        return count;
    }

    void increment() {
        count++;
    }
};

#endif // DTO_H