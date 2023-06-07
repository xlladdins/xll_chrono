// xll_template.h - common includes
#pragma once
#include <chrono>
#include "xll/xll/xll.h"

#ifndef CATEGORY
#define CATEGORY "Chrono"
#endif

#define CPPREF "!https://en.cppreference.com/w/cpp/chrono"

namespace xll {

	struct time_point {
		time_point() = default;
		time_point(const time_point&) = delete;
		time_point& operator=(const time_point&) = delete;
		virtual ~time_point() = default;
		
		double time_since_epoch() const
		{
			return _time_since_epoch();
		}
	private:
		virtual double _time_since_epoch() const = 0;
	};

	struct sys_days : public time_point {
		static inline const std::chrono::sys_days tp;

		double _time_since_epoch() const override
		{
			auto dur = tp.time_since_epoch();
			auto c = std::chrono::duration_cast<std::chrono::seconds>(dur).count();

			return (double)c;
		}
	};
}
