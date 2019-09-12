#include <stdio.h>
#include <sys/types.h>
int main() {
    char x[100];
    while (1) {
        scanf("%s",x);
        system(x);
    }
    return 0;
    
}
