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
    append<HeapAllocationErrorsTest>("error test 1", ErrorTest1);
    append<HeapAllocationErrorsTest>("error test 2", ErrorTest2);
    append<HeapAllocationErrorsTest>("warning test 1", WarningTest1);
    append<HeapAllocationErrorsTest>("info test 1", InfoTest1);
    append<HeapAllocationErrorsTest>("trace test 1", TraceTest1);
    append<HeapAllocationErrorsTest>("trace test 2", TraceTest2);
}

void LoggerTests::ConstructorTest1(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);

    Logger logger(sink);

    ISHIKO_PASS();
}

void LoggerTests::ErrorTest1(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink);

    logger.error("message");

    ISHIKO_FAIL_IF_NEQ(stream.str(), "message");
    ISHIKO_PASS();
}

void LoggerTests::ErrorTest2(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink);

    logger.error("message: {}", "data");

    ISHIKO_FAIL_IF_NEQ(stream.str(), "message: data");
    ISHIKO_PASS();
}

void LoggerTests::WarningTest1(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink);

    logger.warning("message");

    ISHIKO_FAIL_IF_NEQ(stream.str(), "message");
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

void LoggerTests::TraceTest1(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink);

    logger.trace("message");

    ISHIKO_FAIL_IF_NEQ(stream.str(), "");
    ISHIKO_PASS();
}

void LoggerTests::TraceTest2(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink, Logger::Level::trace);

    logger.trace("message");

    ISHIKO_FAIL_IF_NEQ(stream.str(), "message");
    ISHIKO_PASS();
}
