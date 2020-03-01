#include <stdio.h>
#include <stdlib.h>

void fn1(int *y, int val) {
	*y=val;
}

void fn2(int *v, int val){
	fn1(v, val);
}

void fn3(int **x, int val) {
	**x=val;
}

void fn4(int **x, int val) {
	fn1(*x, val);
}

int main() {
	int w = 30;
	fn1(&w,1);
	printf("w is %d\n",w);
	fn2(&w,2);
	printf("w is %d\n",w);

	int *a;
	a=&w;

	fn1(a,3);
	printf("w is %d\n",w);

	fn2(a,4);
	printf("w is %d\n",w);

	int **b;
	b=&a;

	fn1(*b,5);
	printf("w is %d\n",w);
	
	fn2(*b,6);
	printf("w is %d\n",w);

	fn3(b,7);
	printf("w is %d\n",w);

        fn4(b,8);
        printf("w is %d\n",w);

}
