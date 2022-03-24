/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_LOGGING_TESTS_LOGGINGMACROSTESTS_H_
#define _ISHIKO_CPP_LOGGING_TESTS_LOGGINGMACROSTESTS_H_

#include <Ishiko/Tests/Core.hpp>

class LoggingMacrosTests : public Ishiko::TestSequence
{
public:
    LoggingMacrosTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void IshikoLogErrorMacroTest1(Ishiko::Test& test);
    static void IshikoLogErrorMacroTest2(Ishiko::Test& test);
    static void IshikoLogErrorMacroTest3(Ishiko::Test& test);
    static void IshikoLogWarningMacroTest1(Ishiko::Test& test);
    static void IshikoLogWarningMacroTest2(Ishiko::Test& test);
    static void IshikoLogInfoMacroTest1(Ishiko::Test& test);
    static void IshikoLogInfoMacroTest2(Ishiko::Test& test);
    static void IshikoLogTraceMacroTest1(Ishiko::Test& test);
    static void IshikoLogTraceMacroTest2(Ishiko::Test& test);
};

#endif
