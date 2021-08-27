/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#include "LoggingMacrosTests.h"
#include <Ishiko/Tests/Core.h>

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("IshikoLogging");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<LoggingMacrosTests>();

    return theTestHarness.run();
}
