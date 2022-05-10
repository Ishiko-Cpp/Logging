/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_LOGGING_STANDARDSTREAMSLOGGINGSINK_HPP_
#define _ISHIKO_CPP_LOGGING_STANDARDSTREAMSLOGGINGSINK_HPP_

#include "LoggingSink.hpp"

namespace Ishiko
{

 class StandardStreamsLoggingSink : public LoggingSink
{
public:
    void send(const std::string& record) override;
};

}

#endif
