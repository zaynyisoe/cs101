#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TICKETS 5   // number of lotto sets per ticket
#define NUM_PER_SET 6   // number of numbers per set

// generate one lotto set with random numbers
void generate_lotto_set(int *nums) {
    int i, j, n;
    for (i = 0; i < NUM_PER_SET; i++) {
        n = rand() % 69 + 1; // random number 1–69
        // check for duplicate
        for (j = 0; j < i; j++) {
            if (nums[j] == n) {
                n = rand() % 69 + 1;
                j = -1; // restart checking
            }
        }
        nums[i] = n;
    }
    // sort numbers
    for (i = 0; i < NUM_PER_SET - 1; i++) {
        for (j = i + 1; j < NUM_PER_SET; j++) {
            if (nums[i] > nums[j]) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }
}

int main() {
    FILE *fp;
    int counter = 0;

    // 1. Try to open counter.bin
    fp = fopen("counter.bin", "rb");
    if (fp == NULL) {
        // first run, create counter.bin
        counter = 0;
    } else {
        fread(&counter, sizeof(int), 1, fp);
        fclose(fp);
    }

    // 2. Increase counter
    counter++;

    // 3. Create lotto filename
    char filename[32];
    sprintf(filename, "lotto[%05d].txt", counter);

    // 4. Open lotto file to write
    FILE *lotto = fopen(filename, "w");
    time_t now = time(NULL);
    fprintf(lotto, "========= lotto649 =========\n");
    fprintf(lotto, "========+ No.%05d +========\n", counter);
    fprintf(lotto, "= %s", ctime(&now));

    srand((unsigned) time(NULL));
    int nums[NUM_PER_SET];

    for (int i = 0; i < NUM_TICKETS; i++) {
        if (i < 3) {
            generate_lotto_set(nums);
            fprintf(lotto, "[%d]: ", i + 1);
            for (int j = 0; j < NUM_PER_SET; j++) {
                fprintf(lotto, "%02d ", nums[j]);
            }
            fprintf(lotto, "\n");
        } else {
            fprintf(lotto, "[%d]: -- -- -- -- -- --\n", i + 1);
        }
    }

    fprintf(lotto, "========= cs_ex8 ===========\n");
    fclose(lotto);

    // 5. Save counter to counter.bin
    fp = fopen("counter.bin", "wb");
    fwrite(&counter, sizeof(int), 1, fp);
    fclose(fp);

    printf("Generated %s successfully!\n", filename);
    return 0;
}
