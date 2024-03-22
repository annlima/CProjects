#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid_A, pid_B, pid_C, pid_D;
    int status;

    pid_A = fork();
    if (pid_A == 0) {
        printf("Soy A y mi pid es: %d, y el de mi padre es: %d\n", getpid(), getppid());

        pid_D = fork();
        if (pid_D == 0) {
            printf("Soy D y mi pid es: %d, y el de mi padre es: %d\n", getpid(), getppid());
            execl("/bin/ls", "ls", NULL);;
            return 0;
        }
        waitpid(pid_D, &status, 0);
        execl("/bin/rm", "rm", "-r", "new_folder",  NULL);;
        return 0;
    }

    waitpid(pid_A, &status, 0);
    pid_C = fork();
    if (pid_C == 0)
    {
        printf("Soy C y mi pid es: %d, y el de mi padre es: %d\n", getpid(), getppid());
        execl("/bin/ls", "ls", NULL);;
        return 0;
    }

    waitpid(pid_C, &status, 0);
    pid_B = fork();
    if (pid_B == 0)
    {
        printf("Soy B y mi pid es: %d, y el de mi padre es: %d\n", getpid(), getppid());
        execl("/bin/mkdir", "mkdir", "new_folder",  NULL);;
        return 0;
    }

    waitpid(pid_B, &status, 0);
    printf("Soy M y mi PID es:  %d\n", getpid());

    return 0;
}
