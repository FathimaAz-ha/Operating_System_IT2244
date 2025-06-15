/*Exercise

1.read two input from user (//parent process)
name:
reg no:
age:
2.print the output from the child(//child process)
name:abc
reg no: 2022/ict/01
age:25 */



#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char name[100], regno[100], age[10];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid > 0) {
        // Parent process
        close(pipefd[0]); // close read end

        printf("Enter name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0; // remove trailing newline

        printf("Enter reg no: ");
        fgets(regno, sizeof(regno), stdin);
        regno[strcspn(regno, "\n")] = 0;

        printf("Enter age: ");
        fgets(age, sizeof(age), stdin);
        age[strcspn(age, "\n")] = 0;

        // Write fixed-size chunks for each field
        write(pipefd[1], name, sizeof(name));
        write(pipefd[1], regno, sizeof(regno));
        write(pipefd[1], age, sizeof(age));

        close(pipefd[1]);
        wait(NULL); // wait for child
    } else {
        // Child process
        close(pipefd[1]); // close write end

        char r_name[100], r_regno[100], r_age[10];

        // Read fixed-size chunks for each field
        read(pipefd[0], r_name, sizeof(r_name));
        read(pipefd[0], r_regno, sizeof(r_regno));
        read(pipefd[0], r_age, sizeof(r_age));

        printf("\nFrom child process:\n");
        printf("name: %s\n", r_name);
        printf("reg no: %s\n", r_regno);
        printf("age: %s\n", r_age);

        close(pipefd[0]);
    }

    return 0;
}


Output:
[2021ict48@fedora ~]$ gcc pipe2.c-o pipe2
[2021ict48@fedora ~]$ ./pipe2
Enter name:Azha
Enter reg no: 2021ict48
Enter age: 23

From child process:
name: Azha
reg no: 2021ict48
age: 23