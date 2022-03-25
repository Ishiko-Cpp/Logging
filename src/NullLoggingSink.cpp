/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#include "NullLoggingSink.hpp"

namespace Ishiko
{

void NullLoggingSink::send(const std::string& record)
{
    // Do nothing
}

}
