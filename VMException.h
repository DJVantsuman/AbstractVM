//
// Created by Ivan Tsuman on 7/19/18.
//

#ifndef VMEXCEPTION_H
#define VMEXCEPTION_H

# include <stdexcept>
# include <string>

class VMException : public std::exception {
private:
    std::string errorMessage;

public:
    VMException();
    VMException(std::string message);
    ~VMException() throw();
    VMException(const VMException &);
    VMException &operator=(VMException &);
    virtual const char* what() const throw();
};


#endif
