#include <stdio.h>

void countingSort(int arr[], int size) {
    int freq[100];
    for (int i = 0; i < 100; i++) {
        freq[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        freq[arr[i]] += 1;
    }
    for (int i = 0; i < 100; i++) {
        printf("%d ", freq[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    countingSort(arr, n);
    return 0;
}
