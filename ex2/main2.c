#include <stdio.h>
int main() {
    char a = 5;
    printf("\t%d\n", a^1);
    // 0000 0101 0000 0001 XOR 0000 0100 =
    printf("\t%d\n", ~a);
    // 0000 0101 ~ NOT = 111 1010
    printf("\t%d\n", a>>1);
    // 0000 0101 >> 1 = 0000 0010
    printf("\t%d\n", a<<1);
    // 0000 0101 << 1 =
    return 0;
}
