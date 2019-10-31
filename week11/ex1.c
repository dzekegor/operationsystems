//
//  main.c
//  test
//
//  Created by Egor Gubanov on 31/10/2019.
//  Copyright © 2019 Egor. All rights reserved.
//
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <stdint.h>
#include <fcntl.h>
int main() {
    char *addr;
    int file = open("ex1.tx1",O_RDWR);
    struct stat buf;
    addr = mmap(NULL, buf.st_size, PROT_WRITE, MAP_SHARED, file, 0);
    strncpy(addr, "This is a nice day", buf.st_size);
    munmap(addr, buf.st_size);
    close(file);
    return 0;
}
