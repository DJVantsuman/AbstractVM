#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

class Validation
{
public:
    Validation();
    ~Validation();
    int check(std::string type, std::string value);

private:
    int checkInt(std::string value);
    int checkFloat(std::string value);
    int checkDouble(std::string value);
};

#endif // VALIDATION_H
