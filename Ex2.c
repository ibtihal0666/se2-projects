#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h> 
#include <stdlib.h>    

int main() {
    int i;
    pid_t pid;
 

    for (i = 1; i <= 3; i++) {
        pid = fork();
        if(pid<0){
            perror("ERROR1");
           return 1;
        }

        if (pid == 0) {
            printf("Child %d\n", i);
            printf("PID = %d\n", getpid());
            printf("PPID = %d\n", getppid());

            if (i == 1)
                printf("Message: Hello from child 0\n");
            else if (i == 2)
                printf("Message: Hello from child 1\n");
            else
                printf("Message: Hello from child 2\n");

            exit(0);
        }
    }

    for (i = 0; i <= 2; i++) {
        wait(NULL); 
    }

    printf("All children have finished\n");

    return 0;
}