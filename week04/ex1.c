#include <stdio.h>
#include <sys/types.h>
int main() {
    int pid = getpid();
    int n;
    printf("Hello from parent %d\n",pid-n);
    fork();
    pid = getpid();
    printf("Hello from child %d\n",pid-n);
    return 0;
    
}
