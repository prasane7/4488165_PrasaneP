#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* balancedSums(int arr_count, int* arr) {
    long long total_sum = 0;
    for (int i = 0; i < arr_count; i++) {
        total_sum += arr[i];
    }

    long long left_sum = 0;
    for (int i = 0; i < arr_count; i++) {
        long long right_sum = total_sum - left_sum - arr[i];

        if (left_sum == right_sum) {
            return "YES";
        }
        
        left_sum += arr[i];
    }

    return "NO";
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);

        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        const char* result = balancedSums(n, arr);
        printf("%s\n", result);

        free(arr);
    }

    return 0;
}