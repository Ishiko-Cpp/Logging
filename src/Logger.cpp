/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#include "Logger.h"

namespace Ishiko
{

Logger::Logger(LoggingSink& sink)
    : m_sink(sink), m_level(Level::info)
{
}

Logger::Logger(LoggingSink& sink, Level level)
    : m_sink(sink), m_level(level)
{
}

void Logger::setLevel(Level level)
{
    m_level = level;
}

void Logger::warning(const std::string& message)
{
    if (m_level >= Level::warning)
    {
        m_sink.send(message);
    }
}

void Logger::info(const std::string& message)
{
    if (m_level >= Level::info)
    {
        m_sink.send(message);
    }
}

void Logger::trace(const std::string& message)
{
    if (m_level >= Level::trace)
    {
        m_sink.send(message);
    }
}

}
