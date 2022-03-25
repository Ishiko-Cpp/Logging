/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#include "LoggingMacrosTests.hpp"
#include "Ishiko/Logging/Logger.hpp"
#include "Ishiko/Logging/LoggingMacros.hpp"
#include "Ishiko/Logging/StreamLoggingSink.hpp"
#include <sstream>

using namespace Ishiko;

LoggingMacrosTests::LoggingMacrosTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "Logging macros tests", context)
{
    append<HeapAllocationErrorsTest>("ISHIKO_LOG_ERROR test 1", IshikoLogErrorMacroTest1);
    append<HeapAllocationErrorsTest>("ISHIKO_LOG_ERROR test 2", IshikoLogErrorMacroTest2);
    append<HeapAllocationErrorsTest>("ISHIKO_LOG_ERROR test 3", IshikoLogErrorMacroTest3);
    append<HeapAllocationErrorsTest>("ISHIKO_LOG_WARNING test 1", IshikoLogWarningMacroTest1);
    append<HeapAllocationErrorsTest>("ISHIKO_LOG_WARNING test 2", IshikoLogWarningMacroTest2);
    append<HeapAllocationErrorsTest>("ISHIKO_LOG_INFO test 1", IshikoLogInfoMacroTest1);
    append<HeapAllocationErrorsTest>("ISHIKO_LOG_INFO test 2", IshikoLogInfoMacroTest2);
    append<HeapAllocationErrorsTest>("ISHIKO_LOG_TRACE test 1", IshikoLogTraceMacroTest1);
    append<HeapAllocationErrorsTest>("ISHIKO_LOG_TRACE test 2", IshikoLogTraceMacroTest2);
}

void LoggingMacrosTests::IshikoLogErrorMacroTest1(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink);

#undef MAX_LOG_LEVEL
#define MAX_LOG_LEVEL Logger::Level::error
    ISHIKO_LOG_ERROR(MAX_LOG_LEVEL, "message");
    
    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "message");
    ISHIKO_TEST_PASS();
}

void LoggingMacrosTests::IshikoLogErrorMacroTest2(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink, Logger::Level::fatal);

#undef MAX_LOG_LEVEL
#define MAX_LOG_LEVEL Logger::Level::error
    ISHIKO_LOG_ERROR(MAX_LOG_LEVEL, "message");

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "");
    ISHIKO_TEST_PASS();
}

void LoggingMacrosTests::IshikoLogErrorMacroTest3(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink, Logger::Level::error);

#undef MAX_LOG_LEVEL
#define MAX_LOG_LEVEL Logger::Level::fatal
    ISHIKO_LOG_ERROR(MAX_LOG_LEVEL, "message");

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "");
    ISHIKO_TEST_PASS();
}

void LoggingMacrosTests::IshikoLogWarningMacroTest1(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink);

#undef MAX_LOG_LEVEL
#define MAX_LOG_LEVEL Logger::Level::warning
    ISHIKO_LOG_WARNING(MAX_LOG_LEVEL, "message");

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "message");
    ISHIKO_TEST_PASS();
}

void LoggingMacrosTests::IshikoLogWarningMacroTest2(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink, Logger::Level::error);

#undef MAX_LOG_LEVEL
#define MAX_LOG_LEVEL Logger::Level::warning
    ISHIKO_LOG_WARNING(MAX_LOG_LEVEL, "message");

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "");
    ISHIKO_TEST_PASS();
}

void LoggingMacrosTests::IshikoLogInfoMacroTest1(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink);

#undef MAX_LOG_LEVEL
#define MAX_LOG_LEVEL Logger::Level::info
    ISHIKO_LOG_INFO(MAX_LOG_LEVEL, "message");

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "message");
    ISHIKO_TEST_PASS();
}

void LoggingMacrosTests::IshikoLogInfoMacroTest2(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink, Logger::Level::warning);

#undef MAX_LOG_LEVEL
#define MAX_LOG_LEVEL Logger::Level::info
    ISHIKO_LOG_INFO(MAX_LOG_LEVEL, "message");

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "");
    ISHIKO_TEST_PASS();
}

void LoggingMacrosTests::IshikoLogTraceMacroTest1(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink);

#undef MAX_LOG_LEVEL
#define MAX_LOG_LEVEL Logger::Level::trace
    ISHIKO_LOG_TRACE(MAX_LOG_LEVEL, "message");

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "");
    ISHIKO_TEST_PASS();
}

void LoggingMacrosTests::IshikoLogTraceMacroTest2(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink, Logger::Level::trace);

#undef MAX_LOG_LEVEL
#define MAX_LOG_LEVEL Logger::Level::trace
    ISHIKO_LOG_TRACE(MAX_LOG_LEVEL, "message");

    ISHIKO_TEST_FAIL_IF_NEQ(stream.str(), "message");
    ISHIKO_TEST_PASS();
}
