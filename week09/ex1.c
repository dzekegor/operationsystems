//
//  main.c
//  test
//
//  Created by Egor on 17/10/2019.
//  Copyright © 2019 Egor. All rights reserved.
//

#include <stdio.h>
#include <stdint.h>

int n;
int *pages;
uint64_t *ages;

void pass_time(unsigned int j) {
    for (int i = 0; i < n; i++) {
        ages[i] /= 2;
        
        if (i == j) {
            ages[i] = ages[i] | (1ull << 63);
        }
    }
}
int find_worst() {
    uint64_t minim = ages[0];
    int minim_id = 0;
    for (int i = 1; i < n; i++) {
        if (ages[i] < minim) {
            minim = ages[i];
            minim_id = i;
        }
    }
    return minim_id;
}
int search(unsigned int data) {
    int found = -1;
    for (int i = 0; i < n; i++) {
        if (ages[i] == data) {
            found = i;
        }
    }
    return found;
}
int main(int argc, char* argv[]) {
    for (int i = 0; argv[1][i] != '\0'; i++) {
        n = n * 10 + (argv[1][i] - '0');
    }
    //initialize
    pages = (int *) malloc(sizeof(int) * n);
    ages  = (uint64_t *) malloc(sizeof(uint64_t)  * n);
    for (int i = 0; i < n; i++) {
        pages[i] = 0;
        ages[i] = 0;
    }
    int data;
    int misses = 0;
    int hits = 0;
    int found;
    FILE *input = fopen("Lab 09 input.txt","r");
    while(!feof(input)){

        fscanf(input,"%d", &data);
        found = search(data);
        if (found != -1 ){ // -1 if not found
            hits++;
        }
        else{
            misses++;
            found = find_worst();  // Reuse found
            pages[found] = data; ages[found] = 0;
        }
        pass_time( found ); // Do it for both
    }


    printf("Hits:%d Misses:%d \nHitRate:%f", hits, misses , (float)hits/(float)misses);
    return 0;
}

