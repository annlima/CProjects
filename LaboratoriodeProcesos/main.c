#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    pid_t pid1, pid2;
    int fd;

    pid1 = fork();
    if(pid1 == 0)
    {
        int value[10]= {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
        fd = creat("N.dat", 0777);
        write(fd, &value, sizeof(value));
        close(fd);
        exit(1);
    }
    sleep(2);

    pid2 = fork();
    if (pid2 == 0)
    {
        int value2[10]= {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
        fd = creat("M.dat", 0777);
        write(fd, &value2, sizeof(value2));
        close(fd);
        exit(1);
    }
    sleep(2);

    int value[10];
    int value2[10];
    int result[10];

    fd = open("N.dat", 0);
    read(fd, &value, sizeof(value));
    close(fd);
    fd = open("M.dat", 0);
    read(fd, &value2, sizeof(value2));
    close(fd);

    for (int i = 0; i < 10; i++) {
        result[i] = value[i] + value2[i];
    }

    for (int i = 0; i < 10; i++) {
        printf("%d + %d = %d\n", value[i], value2[i], result[i]);
    }

    return 0;
}

