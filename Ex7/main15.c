#include <stdio.h>

int main() {
    int var = 20; 
    int* ip;     

    ip = &var;
  
    printf("Address of var: %p\n", &var);
    printf("Value of ip (address of var): %p\n", ip);
    printf("Address of ip (the pointer itself): %p\n", &ip);
    printf("Value of *ip (value at the address ip points to): %d\n", *ip);

    return 0;
}
