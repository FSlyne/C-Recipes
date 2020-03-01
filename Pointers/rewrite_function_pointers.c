#include <stdlib.h>
#include <stdio.h>

int add(int a, int b) {

return a+b;

}

void map(int (**func_ptr)()) {

*func_ptr=add;

}

int main() {

int (*func_ptr)();
int val;
map(&func_ptr);
//func_ptr=add;

val=func_ptr(1,2);
printf("Result is %d\n",val);
}
