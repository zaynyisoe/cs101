#include <stdio.h>

typedef struct {
    char title[20];
    int year;
} Movie;

int main() {
    Movie m = {"Matrix", 1999};
    Movie *p = &m;

    printf("Title: %s\n", p->title);
    printf("Year: %d\n", p->year);
    return 0;
}
