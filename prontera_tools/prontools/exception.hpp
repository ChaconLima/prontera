#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <string>

namespace exception
{
    class Exception : public std::exception 
    {
        private:
            std::string className;
            std::string message;
            
        public:
            Exception(const std::string &message, const std::string &className);
            std::string getMessage();
            std::string getClassName();
    };
} 

#endif