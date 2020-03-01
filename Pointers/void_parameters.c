#include <stdio.h>
#include <stdlib.h>

void func(void* n) {
	int *m=(int *) n;
	printf("Value is %d\n", *m);
}

int main() {
	int a=45;
	func(&a);
}
