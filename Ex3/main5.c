#include <stdio.h>

int main() {
    int i = 2000;
    if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) {
        printf("是閏年");
    } else {
        printf("不是閏年");
    }
    return 0;
}
