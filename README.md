# <chrono>

The C++ `<chrono>` library provides a way to deal with 
time and differences of times. Clocks are used to measure time.
A `time_point` is a point in time. A `duration` is a difference
of time points.

Every clock has a static function `now()`
that returns a [`std::chrono::time_point<Clock,Duration>`](https://en.cppreference.com/w/cpp/chrono/time_point)
The duration is the difference between the time point and the epoch of the clock.


Step one in using the C++ <chrono> library is choosing a _clock_.
Use [`std::chrono::system_clock`](https://en.cppreference.com/w/cpp/chrono/system_clock)
if you want to convert to and from the C-style
[`time_t`](https://en.cppreference.com/w/c/chrono/time_t). 
It is possible that `system_clock` can change behind your back.
Use
[`std::chrono::steady_clock`](https://en.cppreference.com/w/cpp/chrono/steady_clock)
if you require non-decreasing time.
Use [`std::chrono::high_resolution_clock`](https://en.cppreference.com/w/cpp/chrono/high_resolution_clock).
if you want the highest resolution clock available.

Every clock has a _representation_ type and _period_. The representation is
usually an integer type, and the period is a 
[`std::ratio`](https://en.cppreference.com/w/cpp/numeric/ratio/ratio) of
integral types. Every clock has a static function `now()`

A [`std::chrono::time_point<Clock,Dur>`](https://en.cppreference.com/w/cpp/chrono/time_point)
is a type determined by a representation and a duration.


In the case of `system_clock` you can convert to and from 
[`time_t`](https://en.cppreference.com/w/c/chrono/time_t)
using 
