/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#include "Logger.h"

namespace Ishiko
{

Logger::Logger(LoggingSink& sink)
    : m_sink(sink)
{
}

void Logger::info(const std::string& message)
{
    m_sink.send(message);
}

}
