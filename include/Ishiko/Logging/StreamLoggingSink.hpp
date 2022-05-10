/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_LOGGING_STREAMLOGGINGSINK_HPP_
#define _ISHIKO_CPP_LOGGING_STREAMLOGGINGSINK_HPP_

#include "LoggingSink.hpp"
#include <ostream>

namespace Ishiko
{

class StreamLoggingSink : public LoggingSink
{
public:
    StreamLoggingSink(std::ostream& stream);

    void send(const Record& record) override;

    std::ostream& stream();

private:
    std::ostream& m_stream;
};

}

#endif
