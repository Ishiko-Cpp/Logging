/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#include "StreamLoggingSinkTests.h"
#include "Ishiko/Logging/StreamLoggingSink.h"
#include <sstream>

using namespace Ishiko;
using namespace Ishiko::Tests;

StreamLoggingSinkTests::StreamLoggingSinkTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "StreamLoggingSink tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void StreamLoggingSinkTests::ConstructorTest1(Test& test)
{
    std::stringstream stream;

    StreamLoggingSink sink(stream);

    ISHIKO_FAIL_IF_NEQ(&sink.stream(), &stream);
    ISHIKO_PASS();
}
