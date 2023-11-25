#ifndef __CUSTOM_EXCEPTIONS_HPP__
#define __CUSTOM_EXCEPTIONS_HPP__

#include <exception>
#include <string>


#define OK                  200
#define BAB_REQUEST         400
#define INTERNAL_ERROR      500


class TableAlredyReserved : public std::exception 
{
    private:
        std::string error_message;

    public:
        TableAlredyReserved(const char* message) : error_message(message) {}

        const char* what() const noexcept override 
        {
            return error_message.c_str();
        }
};



#endif
