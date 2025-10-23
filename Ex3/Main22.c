#include <stdio.h>

int main() {
    int *ip;   // Uninitialized pointer
    *ip = 10;  // ❌ This will cause a segmentation fault
    printf("%d\n", *ip);
    return 0;
}
