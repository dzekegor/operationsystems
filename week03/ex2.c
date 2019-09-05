#include <stdio.h>
void bubble_sort(int array[],int n) {
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (array[j] > array[j+1]) {
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
}
int main() {
    int a[100];
    int n;
    printf("Number of elements\n");
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    bubble_sort(a,n);
    
    for (int i = 0; i < 5; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
