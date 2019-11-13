#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int rand_num(){
    int fd = open("/dev/random", O_RDONLY);
    if(errno != 0){
        printf("%s\n", strerror(errno));
    }
    // printf("%d\n", pf);
    // printf("%d\n", errno);
    int buffer;
    int b = read(fd, &buffer, sizeof(int));
    if (errno != 0){
        printf("%s\n", strerror(errno));
    }

    int c = close(fd);
    if (errno != 0){
        printf("%s\n", strerror(errno));
    }

    return buffer;
}

int main(){
    // printf("%d\n", rand_num());

    // Populating into numbers array using rand_num function
    printf("First set of random numbers in array \"numbers[]\"\n");
    int numbers[10];
    int i = 0;
    for(; i < 10; i++){
        numbers[i] = rand_num();
        printf("\trandom %d: %d\n", i, numbers[i]);
    }

    // Writing into numbers_file file
    int fd = open("numbers_file", O_CREAT | O_WRONLY, 0x777);
    if (errno != 0){
        printf("%s\n", strerror(errno));
    }

    write(fd, numbers, sizeof(int) * 10);
    printf("Writing to file \"numbers_file\"\n");
    if (errno != 0){
        printf("WRITING TO FILE: %s\n", strerror(errno));
    }

    close(fd);
    if (errno != 0){
        printf("FIRST CLOSE: %s\n", strerror(errno));
    }

    // Reading numbers from file
    fd = open("numbers_file", O_RDONLY);
    if (errno != 0){
        printf("%s\n", strerror(errno));
    }

    int numbers_from_file[10];
    int r = read(fd, numbers_from_file, sizeof(int) * 10);
    if (errno != 0){
        printf("%s\n", strerror(errno));
    }

    close(fd);
    if (errno != 0){
        printf("%s\n", strerror(errno));
    }

    printf("Printing numbers from file \"numbers_file\"\n");
    i = 0;
    for(; i < 10; i++){
        printf("\trandom %d: %d\n", i, numbers_from_file[i]);
    }

    return 0;
}
