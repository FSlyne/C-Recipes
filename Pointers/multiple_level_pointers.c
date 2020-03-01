#include <stdio.h>
#include <stdlib.h>

int main() {
	int var=10;
	int *ptr1=&var;
	*ptr1=20;
	printf("*ptr1 is %d\n",*ptr1);

	int **ptr2=&ptr1;
	**ptr2=30;
	printf("**ptr2 is %d\n", **ptr2);

	int *ptr3;
	int **ptr4;
	ptr3=&var;
        *ptr3=40;
	printf("*ptr3 is %d\m", *ptr3);
	ptr4=&ptr3;
	**ptr4=50;

	printf("**ptr4 is %d\n", **ptr4);
}
