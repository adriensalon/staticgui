#include <iomanip>
#include <sstream>

#include <bungeegum/glue/time.hpp>

namespace bungeegum {
namespace detail {

    timestamp::timestamp()
    {
        now();
    }

    timestamp::timestamp(const std::chrono::system_clock::time_point& time_point)
    {
        _time = std::chrono::system_clock::to_time_t(time_point);
    }

    void timestamp::now()
    {
        std::chrono::system_clock::time_point _tp = std::chrono::system_clock::now();
        _time = std::chrono::system_clock::to_time_t(_tp);
    }

    std::string timestamp::formatted(const std::string& format) const
    {
        std::ostringstream _sstream;
        const std::tm* _ltime = std::localtime(&_time);
        _sstream << std::put_time(_ltime, format.c_str());
        return _sstream.str();
    }

    stopwatch::stopwatch()
    {
        _last = std::chrono::system_clock::now();
    }
}
}
