#pragma once
#include "header.h"
long fib(int n) {
	if (n < 3)
		return 1;
	return fib(n - 2) + fib(n - 1);
}
