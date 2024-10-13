/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_LOGGING_LOGGER_HPP_
#define _ISHIKO_CPP_LOGGING_LOGGER_HPP_

#include "LoggingSink.hpp"
#include "LogLevel.hpp"
#include <fmt/format.h>
#include <string>

namespace Ishiko
{

class Logger
{
public:
    struct KeyValue
    {
        const char* key;
        const char* value;
    };

    Logger(LoggingSink& sink);
    Logger(LoggingSink& sink, LogLevel level);

    void setLevel(LogLevel level);

    template <typename... Args>
    void error(const std::string& message, Args&&... args);

    template <typename... Args>
    void warning(const std::string& message, Args&&... args);

    template <typename... Args>
    void info(const std::string& message, Args&&... args);

    template <typename... Args>
    void trace(const std::string& message, Args&&... args);

private:
    LoggingSink& m_sink;
    LogLevel m_level;
};

template <typename... Args>
void Logger::error(const std::string& message, Args&&... args)
{
    if (m_level >= LogLevel::error)
    {
        std::string formattedMessage = fmt::format(message, std::forward<Args>(args)...);
        m_sink.send(LoggingSink::Record(m_level, formattedMessage));
    }
}

template <typename... Args>
void Logger::warning(const std::string& message, Args&&... args)
{
    if (m_level >= LogLevel::warning)
    {
        std::string formattedMessage = fmt::format(message, std::forward<Args>(args)...);
        m_sink.send(LoggingSink::Record(m_level, formattedMessage));
    }
}

template <typename... Args>
void Logger::info(const std::string& message, Args&&... args)
{
    if (m_level >= LogLevel::info)
    {
        std::string formattedMessage = fmt::format(message, std::forward<Args>(args)...);
        m_sink.send(LoggingSink::Record(m_level, formattedMessage));
    }
}

template <typename... Args>
void Logger::trace(const std::string& message, Args&&... args)
{
    if (m_level >= LogLevel::trace)
    {
        std::string formattedMessage = fmt::format(message, std::forward<Args>(args)...);
        m_sink.send(LoggingSink::Record(m_level, formattedMessage));
    }
}

}

template<>
class fmt::formatter<Ishiko::Logger::KeyValue>
{
public:
    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(Ishiko::Logger::KeyValue& kv, FormatContext& ctx) -> decltype(ctx.out()) {
        return format_to(ctx.out(), "{}, {}", kv.key, kv.value);
    }
};

#endif
