// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    printf("Starting from (pid: %d)\n", (int) getpid());

    FILE *fp;
    fp = fopen("text.txt", "a");


    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);

    } else if (rc == 0) {
        printf("The child process (pid: %d)\n", (int) getpid());
        char *cstring = "This is from the child.\n";
        fwrite(cstring, sizeof(char), strlen(cstring), fp);

    } else {
        printf("The parent process (pid: %d)\n", (int) getpid());
        char *pstring = "This is from the parent.\n";
        fwrite(pstring, sizeof(char), strlen(pstring), fp);
    }

    fclose(fp);
    
    return 0;
}
