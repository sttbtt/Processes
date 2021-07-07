// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 1;

    printf("Starting x = %d from (pid: %d)\n", x, (int) getpid());

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        x = 100;
        printf("The child process (pid: %d) changed x to 100 and it is %d\n", (int) getpid(), x);
    } else {
        x = 200;
        printf("The parent process (pid: %d) changed x to 200 and it is %d\n", (int) getpid(), x);
    }

    printf("Ending x = %d\n", x);

    return 0;
}
