#include <stdio.h>

int main() {
    char *names[3] = {"Lee", "Eun", "Jee"};

    char *(*ptr)[3] = &names;

    printf("Original array elements (strings):\n");
    printf("names[0] = %s\n", names[0]);
    printf("names[1] = %s\n", names[1]);
    printf("names[2] = %s\n", names[2]);

    printf("\nAccessing elements using the complex pointer 'ptr':\n");

    printf("(*ptr)[0] = %s\n", (*ptr)[0]);
    printf("(*ptr)[1] = %s\n", (*ptr)[1]);
    printf("(*ptr)[2] = %s\n", (*ptr)[2]);

    return 0;
}
