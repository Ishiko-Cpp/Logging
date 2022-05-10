/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#include "StandardStreamsLoggingSinkTests.hpp"
#include "Ishiko/Logging/StandardStreamsLoggingSink.hpp"
#include <Ishiko/Process.hpp>

using namespace Ishiko;

StandardStreamsLoggingSinkTests::StandardStreamsLoggingSinkTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "StandardStreamsLoggingSink tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("send test 1", SendTest1);
}

void StandardStreamsLoggingSinkTests::ConstructorTest1(Test& test)
{
    StandardStreamsLoggingSink sink;

    ISHIKO_TEST_PASS();
}

void StandardStreamsLoggingSinkTests::SendTest1(Test& test)
{
    StandardStreamsLoggingSink sink;

    CurrentProcess::RedirectStandardOutputToFile();

    sink.send("message");

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "message");
    ISHIKO_TEST_PASS();
}
