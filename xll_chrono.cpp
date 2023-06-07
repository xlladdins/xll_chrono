// xll_chrono.cpp - Wrappers for chrono functions.
#include "xll_chrono.h"

using namespace xll;

std::chrono::system_clock sys_clock{};
XLL_CONST(HANDLEX, CHRONO_SYTEM_CLOCK, safe_handle(&sys_clock), "Handle to a system clock",
	CATEGORY, CPPREF "/system_clock");

auto sys_time = std::chrono::time_point<std::chrono::system_clock>{};
XLL_CONST(HANDLEX, CHRONO_SYS_TIME, safe_handle(&sys_time), "Handle to a system clock",
	CATEGORY, CPPREF "/system_clock");

xll::sys_days xll_sys_days;

XLL_CONST(HANDLEX, CHRONO_SYS_DAYS, safe_handle(&xll_sys_days), "Handle to std::chrono::sys_days", 
	CATEGORY, CPPREF "system_clock");

AddIn xai_chrono_clock_now(
	Function(XLL_HANDLEX, "xll_chrono_clock_now", "CHRONO_CLOCK_NOW")
	.Arguments({
		Arg(XLL_HANDLEX, "clock", "is a handle to a std::chrono::time_point"),
		})
		.FunctionHelp("Return current clock time as time_t.")
	.Category(CATEGORY)
	.Documentation(CPPREF "/time_point/time_since_epoch")
);
double WINAPI xll_chrono_clock_now(HANDLEX pc)
{
#pragma XLLEXPORT
	handle<std::chrono::system_clock> pc_(pc);
	if (!pc) {
		return INVALID_HANDLEX;
	}
	return (double)std::chrono::system_clock::to_time_t(pc_->now());
}

AddIn xai_chrono_time_since_epoch(
	Function(XLL_HANDLEX, "xll_chrono_time_since_epoch", "TIME_SINCE_EPOCH")
	.Arguments({
		Arg(XLL_HANDLEX, "time_point", "is a handle to a std::chrono::time_point"),
	})
	.FunctionHelp("Return time since epoch.")
	.Category(CATEGORY)
	.Documentation(CPPREF "/time_point/time_since_epoch")
);
double WINAPI xll_chrono_time_since_epoch(HANDLEX tp)
{
#pragma XLLEXPORT
	handle<time_point> tp_(tp);
	if (!tp_) {
		return INVALID_HANDLEX;
	}
	return tp_->time_since_epoch();
}