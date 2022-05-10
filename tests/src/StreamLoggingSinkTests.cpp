/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#include "StreamLoggingSinkTests.hpp"
#include "Ishiko/Logging/StreamLoggingSink.hpp"
#include <sstream>

using namespace Ishiko;

StreamLoggingSinkTests::StreamLoggingSinkTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "StreamLoggingSink tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("send test 1", SendTest1);
}

void StreamLoggingSinkTests::ConstructorTest1(Test& test)
{
    std::stringstream stream;

    StreamLoggingSink sink(stream);

    ISHIKO_TEST_FAIL_IF_NEQ(&sink.stream(), &stream);
    ISHIKO_TEST_PASS();
}

void StreamLoggingSinkTests::SendTest1(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);

    sink.send(LoggingSink::Record("message"));

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "message");
    ISHIKO_TEST_PASS();
}
