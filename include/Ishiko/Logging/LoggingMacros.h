/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_LOGGING_LOGGINGMACROS_H_
#define _ISHIKO_CPP_LOGGING_LOGGINGMACROS_H_

#define ISHIKO_LOG_ERROR(message)                                     \
    if (ISHIKO_LOG_MIN_DYNAMIC_LEVEL >= Ishiko::Logger::Level::error) \
    {                                                                 \
        logger.error(message);                                        \
    }

#define ISHIKO_LOG_WARNING(message)                                     \
    if (ISHIKO_LOG_MIN_DYNAMIC_LEVEL >= Ishiko::Logger::Level::warning) \
    {                                                                   \
        logger.warning(message);                                        \
    }

#define ISHIKO_LOG_INFO(message)                                     \
    if (ISHIKO_LOG_MIN_DYNAMIC_LEVEL >= Ishiko::Logger::Level::info) \
    {                                                                \
        logger.info(message);                                        \
    }

#define ISHIKO_LOG_TRACE(message)                                     \
    if (ISHIKO_LOG_MIN_DYNAMIC_LEVEL >= Ishiko::Logger::Level::trace) \
    {                                                                 \
        logger.trace(message);                                        \
    }

#endif
