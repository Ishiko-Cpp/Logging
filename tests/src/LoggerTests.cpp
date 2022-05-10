/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#include "LoggerTests.hpp"
#include "Ishiko/Logging/Logger.hpp"
#include "Ishiko/Logging/StreamLoggingSink.hpp"
#include <sstream>

using namespace Ishiko;

LoggerTests::LoggerTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "Logger tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("error test 1", ErrorTest1);
    append<HeapAllocationErrorsTest>("error test 2", ErrorTest2);
    append<HeapAllocationErrorsTest>("error test 3", ErrorTest3);
    append<HeapAllocationErrorsTest>("error test 4", ErrorTest4);
    append<HeapAllocationErrorsTest>("warning test 1", WarningTest1);
    append<HeapAllocationErrorsTest>("warning test 2", WarningTest2);
    append<HeapAllocationErrorsTest>("warning test 3", WarningTest3);
    append<HeapAllocationErrorsTest>("info test 1", InfoTest1);
    append<HeapAllocationErrorsTest>("info test 2", InfoTest2);
    append<HeapAllocationErrorsTest>("info test 3", InfoTest3);
    append<HeapAllocationErrorsTest>("trace test 1", TraceTest1);
    append<HeapAllocationErrorsTest>("trace test 2", TraceTest2);
    append<HeapAllocationErrorsTest>("trace test 3", TraceTest3);
}

void LoggerTests::ConstructorTest1(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);

    Logger logger(sink);

    ISHIKO_TEST_PASS();
}

void LoggerTests::ErrorTest1(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink, LogLevel::fatal);

    logger.error("message");

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "");
    ISHIKO_TEST_PASS();
}

void LoggerTests::ErrorTest2(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink);

    logger.error("message");

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "message\n");
    ISHIKO_TEST_PASS();
}

void LoggerTests::ErrorTest3(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink);

    logger.error("message: {}", "data");

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "message: data\n");
    ISHIKO_TEST_PASS();
}

void LoggerTests::ErrorTest4(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink);

    logger.error("message: {}", Logger::KeyValue{ "key1", "value1" });

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "message: key1, value1\n");
    ISHIKO_TEST_PASS();
}

void LoggerTests::WarningTest1(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink, LogLevel::error);

    logger.warning("message");

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "");
    ISHIKO_TEST_PASS();
}

void LoggerTests::WarningTest2(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink);

    logger.warning("message");

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "message\n");
    ISHIKO_TEST_PASS();
}

void LoggerTests::WarningTest3(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink);

    logger.error("message: {}", "data");

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "message: data\n");
    ISHIKO_TEST_PASS();
}

void LoggerTests::InfoTest1(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink, LogLevel::warning);

    logger.info("message");

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "");
    ISHIKO_TEST_PASS();
}

void LoggerTests::InfoTest2(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink);

    logger.info("message");

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "message\n");
    ISHIKO_TEST_PASS();
}

void LoggerTests::InfoTest3(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink);

    logger.error("message: {}", "data");

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "message: data\n");
    ISHIKO_TEST_PASS();
}

void LoggerTests::TraceTest1(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink);

    logger.trace("message");

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "");
    ISHIKO_TEST_PASS();
}

void LoggerTests::TraceTest2(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink, LogLevel::trace);

    logger.trace("message");

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "message\n");
    ISHIKO_TEST_PASS();
}

void LoggerTests::TraceTest3(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink, LogLevel::trace);

    logger.error("message: {}", "data");

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "message: data\n");
    ISHIKO_TEST_PASS();
}
