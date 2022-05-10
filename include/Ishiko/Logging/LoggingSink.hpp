/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_LOGGING_LOGGINGSINK_HPP_
#define _ISHIKO_CPP_LOGGING_LOGGINGSINK_HPP_

#include "LogLevel.hpp"
#include <string>

namespace Ishiko
{

class LoggingSink
{
public:
    struct Record
    {
        Record(LogLevel level, const std::string& text);

        LogLevel level;
        const std::string& text;
    };

    virtual void send(const Record& record) = 0;
};

}

#endif
