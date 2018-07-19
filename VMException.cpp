//
// Created by Ivan Tsuman on 7/19/18.
//

#include "VMException.h"

VMException::VMException(std::string message){
    errorMessage = message;
}

VMException::~VMException() throw() {
}

VMException::VMException(const VMException &obj) {
    this->errorMessage = obj.errorMessage;
}

VMException &VMException::operator=(VMException &obj) {
    this->errorMessage = obj.errorMessage;
    return (*this);
}

const char* VMException::what() const throw() {
    return (this->errorMessage.c_str());
}