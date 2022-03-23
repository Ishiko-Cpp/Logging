/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_LOGGING_TESTS_LOGGERTESTS_H_
#define _ISHIKO_CPP_LOGGING_TESTS_LOGGERTESTS_H_

#include <Ishiko/Tests/Core.hpp>

class LoggerTests : public Ishiko::TestSequence
{
public:
    LoggerTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void ErrorTest1(Ishiko::Test& test);
    static void ErrorTest2(Ishiko::Test& test);
    static void ErrorTest3(Ishiko::Test& test);
    static void ErrorTest4(Ishiko::Test& test);
    static void WarningTest1(Ishiko::Test& test);
    static void WarningTest2(Ishiko::Test& test);
    static void WarningTest3(Ishiko::Test& test);
    static void InfoTest1(Ishiko::Test& test);
    static void InfoTest2(Ishiko::Test& test);
    static void InfoTest3(Ishiko::Test& test);
    static void TraceTest1(Ishiko::Test& test);
    static void TraceTest2(Ishiko::Test& test);
    static void TraceTest3(Ishiko::Test& test);
};

#endif
