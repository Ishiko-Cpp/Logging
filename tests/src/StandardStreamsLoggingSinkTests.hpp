/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_LOGGING_TESTS_STANDARDSTREAMSLOGGINGSINKTESTS_HPP_
#define _ISHIKO_CPP_LOGGING_TESTS_STANDARDSTREAMSLOGGINGSINKTESTS_HPP_

#include <Ishiko/TestFramework/Core.hpp>

class StandardStreamsLoggingSinkTests : public Ishiko::TestSequence
{
public:
    StandardStreamsLoggingSinkTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void SendTest1(Ishiko::Test& test);
};

#endif
