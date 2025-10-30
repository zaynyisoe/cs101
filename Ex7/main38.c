#include <stdio.h>

int main() {
    int var[] = {1, 2, 3, 4, 5};
    int *ip = var;

    printf("Array elements and addresses:\n");

    printf("var[0] = %d (Address: %p)\n", var[0], (void*)&var[0]);

    printf("*(ip + 1) = %d (Address: %p)\n", *(ip + 1), (void*)(ip + 1));
    printf("*(ip + 4) = %d (Address: %p)\n", *(ip + 4), (void*)(ip + 4));

    ip++; 
    printf("\nAfter ip++, *ip = %d\n", *ip);

    return 0;
}
