/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#include "NullLoggingSinkTests.hpp"
#include "Ishiko/Logging/NullLoggingSink.hpp"

using namespace Ishiko;

NullLoggingSinkTests::NullLoggingSinkTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "NullLoggingSink tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("send test 1", SendTest1);
}

void NullLoggingSinkTests::ConstructorTest1(Test& test)
{
    NullLoggingSink sink;

    ISHIKO_TEST_PASS();
}

void NullLoggingSinkTests::SendTest1(Test& test)
{
    NullLoggingSink sink;

    sink.send(LoggingSink::Record("message"));

    ISHIKO_TEST_PASS();
}
