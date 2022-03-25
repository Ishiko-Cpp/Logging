/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_LOGGING_LOGGINGMACROS_HPP_
#define _ISHIKO_CPP_LOGGING_LOGGINGMACROS_HPP_

// TODO: these macros define a MAX_LOG_LEVEL that allows the complete removal of the logging calls at compilation time
// above a certain level. Individual projects should define a macro defining the max level e.g.
// MY_PROJECT_MAX_LOG_LEVEL and create their own macros that call these macros e.g. MY_PROJECT_LOG_ERROR(...)
// ISHIKO_LOG_ERROR(MY_PROJECT_MAX_LOG_LEVEL, ...)

#define ISHIKO_LOG_ERROR(MAX_LOG_LEVEL, ...)           \
    if (MAX_LOG_LEVEL >= Ishiko::Logger::Level::error) \
    {                                                  \
        logger.error(__VA_ARGS__);                     \
    }

#define ISHIKO_LOG_WARNING(MAX_LOG_LEVEL, ...)           \
    if (MAX_LOG_LEVEL >= Ishiko::Logger::Level::warning) \
    {                                                    \
        logger.warning(__VA_ARGS__);                     \
    }

#define ISHIKO_LOG_INFO(MAX_LOG_LEVEL, ...)           \
    if (MAX_LOG_LEVEL >= Ishiko::Logger::Level::info) \
    {                                                 \
        logger.info(__VA_ARGS__);                     \
    }

#define ISHIKO_LOG_TRACE(MAX_LOG_LEVEL, ...)           \
    if (MAX_LOG_LEVEL >= Ishiko::Logger::Level::trace) \
    {                                                  \
        logger.trace(__VA_ARGS__);                     \
    }

#endif
