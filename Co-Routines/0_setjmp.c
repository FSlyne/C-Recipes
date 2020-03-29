#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

void B(jmp_buf Buf, int delay) {
	printf("Delaying %d\n", delay);
        longjmp(Buf,1);
}

void A(void) {
jmp_buf Buf;
int i;
for (i=0; i<10; i++) {
if (setjmp(Buf)==0) {
	printf("Marked\n");
	B(Buf, i);
} else {
	printf("Returned from a long journey\n");
}
}
}

int main() {
A();
}
