#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int p[2];
    char* str1 = "hello";
    char* str2;
    char buffer[5];
    
    if (pipe(p) < 0) {
        exit(1);
    }
    write(p[1], str1, 5);
    read(p[0],buffer,5);
    str2 = buffer;
    printf("%s\n",str2);
    return 0;
}
