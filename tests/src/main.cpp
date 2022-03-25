/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#include "LoggerTests.hpp"
#include "LoggingMacrosTests.hpp"
#include "NullLoggingSinkTests.hpp"
#include "StreamLoggingSinkTests.hpp"
#include "Ishiko/Logging/linkoptions.hpp"
#include <Ishiko/Tests/Core.hpp>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("IshikoLogging");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<NullLoggingSinkTests>();
    theTests.append<StreamLoggingSinkTests>();
    theTests.append<LoggerTests>();
    theTests.append<LoggingMacrosTests>();

    return theTestHarness.run();
}
