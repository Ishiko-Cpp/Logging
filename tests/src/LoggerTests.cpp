/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#include "LoggerTests.h"
#include "Ishiko/Logging/Logger.h"

using namespace Ishiko::Tests;

LoggerTests::LoggerTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "Logger tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void LoggerTests::ConstructorTest1(Test& test)
{
}
