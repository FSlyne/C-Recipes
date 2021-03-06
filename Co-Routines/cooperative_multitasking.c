#include <setjmp.h>
#include <stdio.h>

jmp_buf mainTask, childTask;

void call_with_cushion();
void child();

int main() {
    if (!setjmp(mainTask)) {
        call_with_cushion(); // child never returns, yield
    } // execution resumes after this "}" after first time that child yields

    while (1) {
        printf("Parent\n");
        
        if (!setjmp(mainTask))
            longjmp(childTask, 1); // yield - note that this is undefined under C99
    }
}

void call_with_cushion() {
    char space[1000]; // Reserve enough space for main to run
    space[999] = 1; // Do not optimize array out of existence
    child();
}

void child() {
    while (1) {
        printf("Child loop begin\n");
        
        if (!setjmp(childTask))
            longjmp(mainTask, 1); // yield - invalidates childTask in C99

        printf("Child loop end\n");

        if (!setjmp(childTask))
            longjmp(mainTask, 1); // yield - invalidates childTask in C99
    }

    /* Don't return. Instead we should set a flag to indicate that main()
       should stop yielding to us and then longjmp(mainTask, 1) */
}
