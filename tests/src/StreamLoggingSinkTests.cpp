/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#include "StreamLoggingSinkTests.h"

using namespace Ishiko::Tests;

StreamLoggingSinkTests::StreamLoggingSinkTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "StreamLoggingSink tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void StreamLoggingSinkTests::ConstructorTest1(Test& test)
{
}
