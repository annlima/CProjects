#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    pid_t pid1, pid2;
    int status;

    pid1 = fork();
    if(pid1 == 0)
    {
        sleep(3);
        printf("Terminé mi ejecución, mi pid es: %d, y el de mi padre es: %d\n", getpid(), getppid());
        return 0;
    }


    pid2 = fork();
    if (pid2 == 0)
    {
        sleep(1);
        printf("Terminé mi ejecución, mi pid es: %d, y el de mi padre es: %d\n", getpid(), getppid());
        return 0;
    }
    wait(&status);

    printf("Uno de mis hijos ha terminado su ejecución");

    return 0;
}

