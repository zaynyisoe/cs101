#include <stdio.h>
#include <stdlib.h>

int check_match(int lotto_nums[6], int input_nums[3]) {
    int match = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            if (lotto_nums[i] == input_nums[j]) match++;
        }
    }
    return match;
}

int main() {
    FILE *fp;
    int lotto[5][6];
    int input[3];
    int match_found = 0;

    fp = fopen("lotto.txt", "r");
    if (fp == NULL) {
        printf("❌ Cannot open lotto.txt. Make sure the file exists.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 6; j++)
            if (fscanf(fp, "%d", &lotto[i][j]) != 1)
                lotto[i][j] = -1;

    fclose(fp);

    printf("Enter your 3 lotto numbers (1~69): ");
    scanf("%d %d %d", &input[0], &input[1], &input[2]);

    for (int i = 0; i < 5; i++) {
        if (lotto[i][0] == -1) continue;
        int matched = check_match(lotto[i], input);
        if (matched > 0) {
            printf("✅ You matched %d number(s) in Set #%d!\n", matched, i + 1);
            match_found = 1;
        }
    }

    if (!match_found)
        printf("😢 Sorry, no matches found.\n");

    return 0;
}
