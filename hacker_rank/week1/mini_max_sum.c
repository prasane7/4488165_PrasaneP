#include <stdio.h>
#include <stdlib.h>



int main() {
    int nums[MAX_SIZE];
    int count = 0;
    char line[5000];
    

    if (fgets(line, sizeof(line), stdin) == NULL) {
        fprintf(stderr, "Failed to read input.\n");
        return 1;
    }


    char *ptr = line;
    while (count < MAX_SIZE) {
        int num;
        int chars_read;
      
        if (sscanf(ptr, "%d%n", &num, &chars_read) != 1) {
            // No more integers found
            break;
        }
        nums[count++] = num;
        ptr += chars_read;
    }

    if (count == 0) {
        printf("No numbers provided.\n");
        return 1;
    }

    long long total_sum = 0;
    for (int i = 0; i < count; i++) {
        total_sum += nums[i];
    }


    long long min_sum = total_sum - nums[0];
    long long max_sum = total_sum - nums[0];

    for (int i = 1; i < count; i++) {
        long long excluded_sum = total_sum - nums[i];
        if (excluded_sum < min_sum) min_sum = excluded_sum;
        if (excluded_sum > max_sum) max_sum = excluded_sum;
    }

    printf("%lld %lld\n", min_sum, max_sum);

    return 0;
}
