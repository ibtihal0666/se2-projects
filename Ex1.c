#include<stdio.h>
#include<unistd.h>

int main() {
    printf("Welcome\n");
    printf("PID = %d\n", getpid());
    printf("PPID = %d\n", getppid());

    sleep(20);

    printf("End of Program\n");

    return 0;
}