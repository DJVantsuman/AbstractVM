#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

class Validation
{
public:
    Validation();
    ~Validation();
    int check(std::string str);

private:
    int checkLexical(std::string str);
    int checkType(std::string str);
};

#endif // VALIDATION_H
