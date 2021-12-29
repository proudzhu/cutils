// SPDX-License-Identifier: GPL-2.0

#include "catch2/catch_test_macros.hpp"
#include "rational.h"

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(arr)    (sizeof(arr) / sizeof((arr)[0]))
#endif

struct rational_test_param {
	unsigned long num, den;
	unsigned long max_num, max_den;
	unsigned long exp_num, exp_den;

	const char *name;
};

static const struct rational_test_param test_parameters[] = {
	{ 1230,	10,	100, 20,	100, 1,    "Exceeds bounds, semi-convergent term > 1/2 last term" },
	{ 34567,100, 	120, 20,	120, 1,    "Exceeds bounds, semi-convergent term < 1/2 last term" },
	{ 1, 30,	100, 10,	0, 1,	   "Closest to zero" },
	{ 1, 19,	100, 10,	1, 10,     "Closest to smallest non-zero" },
	{ 27,32,	16, 16,		11, 13,    "Use convergent" },
	{ 1155, 7735,	255, 255,	33, 221,   "Exact answer" },
	{ 87, 32,	70, 32,		68, 25,    "Semiconvergent, numerator limit" },
	{ 14533, 4626,	15000, 2400,	7433, 2366, "Semiconvergent, denominator limit" },
};

TEST_CASE("RationalTest", "[rational test]")
{
	SECTION("rational_best_approximation") {
		for (uint32_t i = 0; i < ARRAY_SIZE(test_parameters); i++) {
			const struct rational_test_param *param = (const struct rational_test_param *)&test_parameters[i];
			unsigned long n = 0, d = 0;

			rational_best_approximation(param->num, param->den, param->max_num, param->max_den, &n, &d);
			REQUIRE(n == param->exp_num);
			REQUIRE(d == param->exp_den);
		}
	}
}