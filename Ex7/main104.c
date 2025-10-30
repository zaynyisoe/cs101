#include <stdio.h>

int add_numbers(int a, int b) {
    return a + b;
}

int main() {
    int (*pf)(int, int) = &add_numbers;

    int result1 = pf(10, 5);

    int result2 = (*pf)(20, 3); 

    printf("Result using pf(10, 5): %d\n", result1);
    printf("Result using (*pf)(20, 3): %d\n", result2);

    return 0;
}
