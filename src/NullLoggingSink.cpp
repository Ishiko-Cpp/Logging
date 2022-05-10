/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#include "NullLoggingSink.hpp"

using namespace Ishiko;

void NullLoggingSink::send(const Record& record)
{
    // Do nothing
}
