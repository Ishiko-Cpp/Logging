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
    const char* stdout_basename = "StandardStreamsLoggingSinkTests_SendTest1_out.txt";
    const char* stderr_basename = "StandardStreamsLoggingSinkTests_SendTest1_err.txt";

    CurrentProcess::RedirectStandardOutputToFile(test.context().getOutputPath(stdout_basename));
    CurrentProcess::RedirectStandardErrorToFile(test.context().getOutputPath(stderr_basename));

    StandardStreamsLoggingSink sink;
    sink.send(LoggingSink::Record(LogLevel::info, "info message"));
    sink.send(LoggingSink::Record(LogLevel::error, "error message"));

    CurrentProcess::RedirectStandardOutputToTerminal();
    CurrentProcess::RedirectStandardErrorToTerminal();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(stdout_basename);
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(stderr_basename);
    ISHIKO_TEST_PASS();
}
