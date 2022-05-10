/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#include "StandardStreamsLoggingSink.hpp"
#include <iostream>
using namespace Ishiko;

void StandardStreamsLoggingSink::send(const Record& record)
{
    // TODO: allow setting the threshold
    if (record.level > LogLevel::error)
    {
        std::cout << record.text << std::endl;
    }
    else
    {
        std::cerr << record.text << std::endl;
    }
}
