#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pidB, pidC, pidE;
    int status;

    pidB = fork();
    if (pidB==0)
    {
        sleep(3);
        return 1;
    }


    pidC = fork();
    if (pidC==0)
    {
        sleep(1);
        return 2;
    }

    pidE = fork();
    if (pidE==0)
    {
        return 3;
    }


    waitpid(pidB, &status, 0);
    printf("Mi hijo M terminó de ejecutarse y su valor de retorno es: %d\n", WEXITSTATUS(status));
    waitpid(pidC, &status, 0);
    printf("Mi hijo A terminó de ejecutarse y su valor de retorno es: %d\n", WEXITSTATUS(status));
    waitpid(pidE, &status, 0);
    printf("Mi hijo B terminó de ejecutarse y su valor de retorno es: %d\n", WEXITSTATUS(status));

}
