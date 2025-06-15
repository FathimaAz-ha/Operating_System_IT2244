/*
nCr = n!/(n-r)! r!

nPr = n!/(n-r)!

*/


/*
read n, r values from user give n,r, n-r values from parent to shared memory and child 
retrieves it from shared mkepry and proecess nPr and nCr and gives 
the output to the parent to print via the shared memory
give easy simple code
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

long fact(int num) {
    long result = 1;
    for (int i = 2; i <= num; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int shmid;
    int *shared_mem;
    shmid = shmget(IPC_PRIVATE, 5 * sizeof(int), IPC_CREAT | 0666);

    if (shmid == -1) {
        perror("Shared memory creation failed");
        exit(EXIT_FAILURE);
    }

    shared_mem = (int*) shmat(shmid, NULL, 0);
    if (shared_mem == (int*) -1) {
        perror("Shared memory attachment failed");
        exit(EXIT_FAILURE);
    }

    int f = fork();

    if (f > 0) { // Parent process (Sender)
        printf("Enter n: ");
        scanf("%d", &shared_mem[0]);

        printf("Enter r: ");
        scanf("%d", &shared_mem[1]);

        shared_mem[2] = shared_mem[0] - shared_mem[1]; // n - r
        wait(NULL); // Wait for child to complete processing

        // Parent reads results from shared memory
        printf("nPr: %ld\n", shared_mem[3]);
        printf("nCr: %ld\n", shared_mem[4]);

        // Cleanup shared memory
        shmdt(shared_mem);
        shmctl(shmid, IPC_RMID, NULL);
    } 
    else if (f == 0) { // Child process (Receiver)
        shared_mem[3] = fact(shared_mem[0]) / fact(shared_mem[2]); // nPr
        shared_mem[4] = shared_mem[3] / fact(shared_mem[1]); // nCr

        shmdt(shared_mem);
        exit(0);
    }

    return 0;
}


//another
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

// Function to compute factorial
long fact(int num) {
    long result = 1;
    for (int i = 2; i <= num; i++) {
        result *= i;
    }
    return result;
}

int main() {
    // Allocate shared memory
    size_t size = 5 * sizeof(int);
    int *shared_mem = mmap(NULL, size, PROT_READ | PROT_WRITE,
        MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    if (shared_mem == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == 0) {
        // Child process: Compute nPr and nCr
        shared_mem[3] = fact(shared_mem[0]) / fact(shared_mem[2]); // nPr
        shared_mem[4] = shared_mem[3] / fact(shared_mem[1]); // nCr
        exit(0);
    } 
    else if (pid > 0) {
        // Parent process: Read input
        printf("Enter n: ");
        scanf("%d", &shared_mem[0]);

        printf("Enter r: ");
        scanf("%d", &shared_mem[1]);

        shared_mem[2] = shared_mem[0] - shared_mem[1]; // Store n-r

        wait(NULL); // Wait for child to process
        
        // Print results
        printf("nPr: %ld\n", shared_mem[3]);
        printf("nCr: %ld\n", shared_mem[4]);

        munmap(shared_mem, size);
    } 
    else {
        perror("fork failed");
        exit(1);
    }

    return 0;
}

Output:
[2021ict48@fedora ~]$ gcc qn.c-o qn
[2021ict48@fedora ~]$ ./qn
Enter n: 6
Enter r: 7
nPr: 1
nCr: 1
