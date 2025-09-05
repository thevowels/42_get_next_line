#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int main(void) {
#ifdef OPEN_MAX
    printf("OPEN_MAX = %d (compile-time)\n", OPEN_MAX);
#else
    printf("OPEN_MAX not defined, using sysconf\n");
#endif

    long sc_openmax = sysconf(_SC_OPEN_MAX);
    if (sc_openmax == -1)
        perror("sysconf");
    else
        printf("sysconf(_SC_OPEN_MAX) = %ld (runtime)\n", sc_openmax);

    return 0;
}