/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_LOGGING_LOGGINGSINK_HPP_
#define _ISHIKO_CPP_LOGGING_LOGGINGSINK_HPP_

#include <string>

namespace Ishiko
{

class LoggingSink
{
public:
    struct Record
    {
        Record(const std::string& text);

        const std::string& text;
    };

    virtual void send(const Record& record) = 0;
};

}

#endif
