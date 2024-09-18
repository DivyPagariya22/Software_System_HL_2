#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

int main() {
    struct rlimit limit;

    limit.rlim_cur = 1024;  // New soft limit
    limit.rlim_max = 2048;  // New hard limit

    if (setrlimit(RLIMIT_NOFILE, &limit) == 0) {
        printf("New limits set: Soft limit = %ld, Hard limit = %ld\n", (long)limit.rlim_cur, (long)limit.rlim_max);
    } else {
        perror("Error setting limit");
        exit(EXIT_FAILURE);
    }

    return 0;
}
