/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#include "StreamLoggingSink.hpp"

namespace Ishiko
{

StreamLoggingSink::StreamLoggingSink(std::ostream& stream)
    : m_stream(stream)
{
}

void StreamLoggingSink::send(const Record& record)
{
    m_stream << record.text;
}

std::ostream& StreamLoggingSink::stream()
{
    return m_stream;
}

}
