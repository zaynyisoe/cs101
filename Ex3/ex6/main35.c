#include <stdio.h>

int main() {
    char v = 65;       // 'A'
    int *p = (int *)&v; // Wrong pointer type
    printf("%d\n", *p); // ❌ reading 4 bytes from 1-byte variable
    return 0;
}
