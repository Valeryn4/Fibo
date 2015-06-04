#include "header.h"

__int64 fib(int n) {
	if (n < 3)
		return 1;
	return fib(n - 2) + fib(n - 1);
}
