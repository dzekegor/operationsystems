#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    char x;
    char *string;
    string = (char *) malloc(1*sizeof(char));
    x = getc(stdin);
    string[0] = x;
    int i = 1;
    while (x != '\n') {
        x = getc(stdin);
        i++;
        string = (char *) realloc(string,i*sizeof(char));
        string[i-1] = x;
    }
    for (int j = i-1; j >= 0; j--) {
        printf("%c",string[j]);
    }
    printf("\n");
    return 0;
}
