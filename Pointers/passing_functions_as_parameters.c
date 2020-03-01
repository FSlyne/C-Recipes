
#include <stdio.h>

void func(int x) {
	printf("Value of x is %d\n", x);
}

void execfn(void (*fn)(), int n) {
	fn(n);
}

int main() {
	execfn(func, 67);
}
