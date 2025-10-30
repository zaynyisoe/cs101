#include <stdio.h>

struct Movie {
    int ranking;
    char* title;
};

int main() {
    struct Movie mymovie = {1, "BE ALL YOU CAN BE!"};

    struct Movie *m = &mymovie;

    printf("Movie Ranking (using ->): %d\n", m->ranking);
    printf("Movie Title (using ->): %s\n", m->title);

    printf("\nMovie Ranking (using (*m).): %d\n", (*m).ranking);

    return 0;
}
