#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(){
    int pf = open("/dev/random", O_RDONLY);
    if(errno != 0){
        printf("%s\n", strerror(errno));
    }
    // printf("%d\n", pf);
    // printf("%d\n", errno);
    int buffer[100];
    int b = read(3, buffer, sizeof(int) * 10);
    printf("%d\n", b);
    if (errno != 0){
        printf("%s\n", strerror(errno));
    }

    // int i = 0;
    // for(; i < 10; i++){
    //     printf("%d\n", buffer[i]);
    // }
    int c = close(2);
    if (errno != 0){
        printf("%s\n", strerror(errno));
    }
    return 0;
}
