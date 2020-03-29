#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int status;
    void (* out)(void* , int);
    void *typex;
} FUNC;

void func_init(FUNC* self) {
    self->status=0;
}

FUNC* func_create() {
    FUNC* obj=(FUNC*) malloc(sizeof(FUNC));
    func_init(obj);
    return obj;
}

void func_destroy(packet* obj){
    if (obj) {
        free(obj);
    }
}

int func_exec() {
   FUNC* f=func_create()
   
   
}



int add(int a, int b) {

return a+b;

}

void map(int (**func_ptr)()) {

*func_ptr=add;

}

FUN

int fn() {
   return 1+2;
}

void executor(()) {
   void (*func)();
   func=fn;
   int r=0;
   for (int i=0; i<100; i++) {
      r=fn();
      printf("%d\n", r);
   }
}

int main() {

int (*func_ptr)();
int val;
map(&func_ptr);
//func_ptr=add;

val=func_ptr(1,2);
printf("Result is %d\n",val);
}
