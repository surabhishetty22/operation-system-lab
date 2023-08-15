#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    int status;
    pid = vfork();
    if (pid == -1) {
        perror("vfork");
        return 1;
    } else if (pid == 0) {
        printf("Child process: Hello, i'm the child!\n");
        printf("Child process: My PID is %d\n", getpid());
        printf("Child process: My parent's PID is %d\n", getppid());
        exit(0);
    } else {
        printf("Parent process: Hello, I'm the parent!\n");
        printf("Parent process: My PID is %d\n", getpid());
        printf("Parent process: My parent's PID is %d\n", pid);
        waitpid(pid, &status, 0);
        if(WIFEXITED(status)) {
            printf("Parent process: Child process terminated normally.\n");
        } else {
            printf("Parent process: Child process terminated abnormally.\n");
        }
    }
    return 1;
}
