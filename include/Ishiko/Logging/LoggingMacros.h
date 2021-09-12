/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_LOGGING_LOGGINGMACROS_H_
#define _ISHIKO_CPP_LOGGING_LOGGINGMACROS_H_

#define ISHIKO_LOG_ERROR(message) logger.error(message);
#define ISHIKO_LOG_WARNING(message) logger.warning(message);
#define ISHIKO_LOG_INFO(message) logger.info(message);
#define ISHIKO_LOG_TRACE(message) logger.trace(message);

#endif
