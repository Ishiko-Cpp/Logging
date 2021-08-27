/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_LOGGING_STREAMLOGGINGSINK_H_
#define _ISHIKO_CPP_LOGGING_STREAMLOGGINGSINK_H_

#include "LoggingSink.h"
#include <ostream>

namespace Ishiko
{

class StreamLoggingSink : public LoggingSink
{
public:
    StreamLoggingSink(std::ostream& stream);

    std::ostream& stream();

private:
    std::ostream& m_stream;
};

}

#endif
