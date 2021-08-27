/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#include "LoggerTests.h"
#include "Ishiko/Logging/Logger.h"
#include "Ishiko/Logging/StreamLoggingSink.h"
#include <sstream>

using namespace Ishiko;
using namespace Ishiko::Tests;

LoggerTests::LoggerTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "Logger tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("info test 1", InfoTest1);
}

void LoggerTests::ConstructorTest1(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);

    Logger logger(sink);

    ISHIKO_PASS();
}

void LoggerTests::InfoTest1(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink);

    logger.info("message");

    ISHIKO_FAIL_IF_NEQ(stream.str(), "message");
    ISHIKO_PASS();
}
