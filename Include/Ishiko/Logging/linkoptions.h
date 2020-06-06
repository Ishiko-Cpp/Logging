/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Logging/blob/master/LICENSE.txt
*/

#ifndef _ISHIKO_LOGGING_LINKOPTIONS_H_
#define _ISHIKO_LOGGING_LINKOPTIONS_H_

#ifdef _DEBUG
#pragma comment(lib, "IshikoLogging-d.lib")
#else
#pragma comment(lib, "IshikoLogging.lib")
#endif

#endif
