#include <stdio.h>

int main() {
    char buffer[21];

    FILE *input = fopen("/dev/random", "r");
    FILE *output = fopen("./ex1.txt", "w");
    if (input == NULL || output == NULL) {
        perror("Files do not exist\n");
        return -1;
    }
    fgets(buffer, 21, input);
    fprintf(output, "%s", buffer);
    printf("%s", buffer);

    fclose(input);
    fclose(output);
    return 0;
}
