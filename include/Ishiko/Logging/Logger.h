/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_LOGGING_LOGGER_H_
#define _ISHIKO_CPP_LOGGING_LOGGER_H_

#include "LoggingSink.h"
#include <fmt/format.h>
#include <string>

namespace Ishiko
{

class Logger
{
public:
    enum class Level
    {
        error = 1,
        warning = 2,
        info = 3,
        trace = 4
    };

    Logger(LoggingSink& sink);
    Logger(LoggingSink& sink, Level level);

    void setLevel(Level level);

    template <typename... Args>
    void error(const std::string& message, Args&&... args);
    void warning(const std::string& message);
    void info(const std::string& message);
    void trace(const std::string& message);

private:
    LoggingSink& m_sink;
    Level m_level;
};

template <typename... Args>
void Logger::error(const std::string& message, Args&&... args)
{
    if (m_level >= Level::error)
    {
        std::string formattedMessage = fmt::format(message, std::forward<Args>(args)...);
        m_sink.send(formattedMessage);
    }
}

}

#endif
