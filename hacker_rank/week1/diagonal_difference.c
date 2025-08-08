#include <stdio.h>

int diagonalDifference(int n, int arr[n][n]) {
    int primary = 0;
    int secondary = 0;
    for (int i = 0; i < n; i++) {
        primary += arr[i][i];
        secondary += arr[i][n - 1 - i];
    }
    int diff = primary - secondary;
    if (diff < 0) diff = -diff;
    return diff;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int result = diagonalDifference(n, arr);
    printf("%d\n", result);
    return 0;
}
