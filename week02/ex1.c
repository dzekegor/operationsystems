#include <stdio.h>
#include <limits.h>
#include <float.h>
int main() {
    int integer = INT_MAX;
    float floatingpoint = FLT_MAX;
    double doublefloat = DBL_MAX;
    printf("%d\n%f\n%lf",integer,floatingpoint,doublefloat);
    return 0;
}
