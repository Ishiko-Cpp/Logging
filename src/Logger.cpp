/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#include "Logger.hpp"

namespace Ishiko
{

Logger::Logger(LoggingSink& sink)
    : m_sink(sink), m_level(LogLevel::info)
{
}

Logger::Logger(LoggingSink& sink, LogLevel level)
    : m_sink(sink), m_level(level)
{
}

void Logger::setLevel(LogLevel level)
{
    m_level = level;
}

}
