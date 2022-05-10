/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_LOGGING_LOGLEVEL_HPP_
#define _ISHIKO_CPP_LOGGING_LOGLEVEL_HPP_

namespace Ishiko
{

enum class LogLevel
{
    fatal = 1,
    error = 2,
    warning = 3,
    info = 4,
    trace = 5
};

}

#endif
