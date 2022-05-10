/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#include "LoggingSink.hpp"

using namespace Ishiko;

LoggingSink::Record::Record(LogLevel level, const std::string& text)
    : level(level), text(text)
{
}
