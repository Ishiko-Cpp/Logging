/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_LOGGING_TESTS_LOGGERTESTS_H_
#define _ISHIKO_CPP_LOGGING_TESTS_LOGGERTESTS_H_

#include <Ishiko/Tests/Core.h>

class LoggerTests : public Ishiko::Tests::TestSequence
{
public:
    LoggerTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void ConstructorTest1(Ishiko::Tests::Test& test);
    static void ErrorTest1(Ishiko::Tests::Test& test);
    static void WarningTest1(Ishiko::Tests::Test& test);
    static void InfoTest1(Ishiko::Tests::Test& test);
    static void TraceTest1(Ishiko::Tests::Test& test);
    static void TraceTest2(Ishiko::Tests::Test& test);
};

#endif
