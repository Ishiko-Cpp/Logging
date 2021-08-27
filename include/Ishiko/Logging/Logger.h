/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_LOGGING_LOGGER_H_
#define _ISHIKO_CPP_LOGGING_LOGGER_H_

#include "LoggingSink.h"
#include <string>

namespace Ishiko
{

class Logger
{
public:
    Logger(LoggingSink& sink);

    void info(const std::string& message);

private:
    LoggingSink& m_sink;
};

}

#endif
