#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(){
    int pf = open("paul.txt", O_RDONLY);
    printf("%s\n", strerror(errno));
    // printf("%d\n", pf);
    // printf("%d\n", errno);
    char buffer[100];
    int b = read(3, buffer, 100);
    printf("%d\n", b);
    printf("%s\n", strerror(errno));

    printf("%s", buffer);
    return 0;
}
