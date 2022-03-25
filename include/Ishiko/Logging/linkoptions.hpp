/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_LOGGING_LINKOPTIONS_HPP_
#define _ISHIKO_CPP_LOGGING_LINKOPTIONS_HPP_

#ifdef _DEBUG
#pragma comment(lib, "IshikoLogging-d.lib")
#else
#pragma comment(lib, "IshikoLogging.lib")
#endif

#endif
