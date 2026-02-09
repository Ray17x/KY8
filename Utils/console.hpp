#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <stdio.h>
#include <ctime>
#include <string_view>


namespace RC {
    class Colors {
        // Colors ANSI escapes

        // Regular Codes
    public:
        static constexpr const char* BLACK = "\033[0;30m";
        static constexpr const char* RED = "\033[0;31m";
        static constexpr const char* GREEN = "\033[0;32m";
        static constexpr const char* YELLOW = "\033[0;33m";
        static constexpr const char* BLUE = "\033[0;34m";
        static constexpr const char* MAGENTA = "\033[0;35m";
        static constexpr const char* CYAN = "\033[0;36m";
        static constexpr const char* WHITE = "\033[0;37m";

        // Bold
        static constexpr const char* BOLD_BLACK = "\033[1;30m";
        static constexpr const char* BOLD_RED = "\033[1;31m";
        static constexpr const char* BOLD_GREEN = "\033[1;32m";
        static constexpr const char* BOLD_YELLOW = "\033[1;33m";
        static constexpr const char* BOLD_BLUE = "\033[1;34m";
        static constexpr const char* BOLD_MAGENTA = "\033[1;35m";
        static constexpr const char* BOLD_CYAN = "\033[1;36m";
        static constexpr const char* BOLD_WHITE = "\033[1;37m";

        // Reset
        static constexpr const char* RESET = "\033[0m";
    };

    // Get Current Time in HH:MM:SS format
    inline const char* getCurrentTime() {
        static char buffer[9]; // HH:MM:SS + null terminator
        time_t now = time(0);
        struct tm tstruct;
        tstruct = *localtime(&now);
        strftime(buffer, sizeof(buffer), "%H:%M:%S", &tstruct);
        return buffer;
    }

    // Logging functions
    inline void log(const std::string_view& msg) {
        printf("%s[%s] %s%s[LOG]%s %s\n", Colors::CYAN, getCurrentTime(), Colors::RESET, Colors::BOLD_WHITE, Colors::RESET, msg.data());
    }

    inline void warn(const std::string_view& msg) {
        printf("%s[%s] %s%s[WARN]%s %s\n", Colors::CYAN, getCurrentTime(), Colors::RESET, Colors::BOLD_YELLOW, Colors::RESET, msg.data());
    }

    inline void error(const std::string_view& msg) {
        printf("%s[%s] %s%s[ERROR]%s %s\n", Colors::CYAN, getCurrentTime(), Colors::RESET, Colors::BOLD_RED, Colors::RESET, msg.data());
    }
}

#endif // CONSOLE_HPP