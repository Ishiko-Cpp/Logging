/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#include "LoggingMacrosTests.h"
#include "Ishiko/Logging/Logger.h"
#include "Ishiko/Logging/LoggingMacros.h"
#include "Ishiko/Logging/StreamLoggingSink.h"
#include <sstream>

using namespace Ishiko;
using namespace Ishiko::Tests;

LoggingMacrosTests::LoggingMacrosTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "Logging macros tests", environment)
{
    append<HeapAllocationErrorsTest>("ISHIKO_LOG_INFO test 1", IshikoLogInfoMacroTest1);
}

void LoggingMacrosTests::IshikoLogInfoMacroTest1(Test& test)
{
    std::stringstream stream;
    StreamLoggingSink sink(stream);
    Logger logger(sink);

    ISHIKO_LOG_INFO("message");
    
    ISHIKO_FAIL_IF_NEQ(stream.str(), "message");
    ISHIKO_PASS();
}
