/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_LOGGING_LOGLEVEL_HPP_
#define _ISHIKO_CPP_LOGGING_LOGLEVEL_HPP_

#include <string>

namespace Ishiko
{

class LogLevel
{
public:
    enum Value
    {
        always = 0x00,
        fatal = 0x20,
        error = 0x40,
        warning = 0x60,
        info = 0x80,
        verbose = 0xA0,
        debug = 0xC0,
        trace = 0xE0
    };

    LogLevel();
    LogLevel(Value value);
    LogLevel FromString(const std::string& level);

    bool operator==(LogLevel::Value level) const;
    bool operator!=(LogLevel::Value level) const;
    bool operator<=(LogLevel::Value level) const;
    bool operator>=(LogLevel::Value level) const;
    bool operator<(LogLevel::Value level) const;
    bool operator>(LogLevel::Value level) const;

    std::string toString();

private:
    Value m_value;
};

}

#endif
