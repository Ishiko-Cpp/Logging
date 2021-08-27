/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#include "StreamLoggingSink.h"

namespace Ishiko
{

StreamLoggingSink::StreamLoggingSink(std::ostream& stream)
    : m_stream(stream)
{
}

std::ostream& StreamLoggingSink::stream()
{
    return m_stream;
}

}
