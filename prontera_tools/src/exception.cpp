#include "../prontools/exception.hpp"

namespace exception {

    Exception::Exception(const std::string &message, const std::string &className){
        this->className = className;
        this->message = message;
    }

    std::string Exception::getMessage(){
        return this->message;
    }

    std::string Exception::getClassName(){
        return this->className;
    }

}

