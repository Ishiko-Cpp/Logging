/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#include "LogLevel.hpp"

using namespace Ishiko;

LogLevel::LogLevel()
    : m_value(error)
{
}

LogLevel::LogLevel(Value value)
    : m_value(value)
{
}

LogLevel LogLevel::FromString(const std::string& level)
{
    LogLevel result;
    if (level == "always")
    {
        result = always;
    }
    else if (level == "fatal")
    {
        result = fatal;
    }
    else if (level == "error")
    {
        result = error;  
    }
    else if (level == "warning")
    {
        result = warning;
    }
    else if (level == "info")
    {
        result = info;
    }
    else if (level == "verbose")
    {
        result = verbose;
    }
    else if (level == "debug")
    {
        result = debug; 
    }
    else if (level == "trace")
    {
        result = trace;
    }
    else
    {
        // TODO: error
    }
    return result;
}

bool LogLevel::operator==(LogLevel::Value level) const
{
    return (m_value == level);
}

bool LogLevel::operator!=(LogLevel::Value level) const
{
    return (m_value != level);
}

bool LogLevel::operator<=(LogLevel::Value level) const
{
    return (m_value <= level);
}

bool LogLevel::operator>=(LogLevel::Value level) const
{
    return (m_value >= level);
}

bool LogLevel::operator<(LogLevel::Value level) const
{
    return (m_value < level);
}

bool LogLevel::operator>(LogLevel::Value level) const
{
    return (m_value > level);
}

std::string LogLevel::toString()
{
    std::string result;
    switch (m_value)
    {
    case always:
        result = "always";
        break;

    case fatal:
        result = "fatal";
        break;

    case error:
        result = "error";
        break;

    case warning:
        result = "warning";
        break;

    case info:
        result = "info";
        break;

    case verbose:
        result = "verbose";
        break;

    case debug:
        result = "debug";
        break;

    case trace:
        result = "trace";
        break;

    default:
        // TODO: error
        break;
    }
    return result;
}
