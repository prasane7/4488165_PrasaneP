#include <stdio.h>

int sockMerchant(int n, int ar[]) {
    int colorCount[101] = {0}; // Since 1 <= ar[i] <= 100
    int pairs = 0;

    for (int i = 0; i < n; i++) {
        colorCount[ar[i]]++;
    }

    for (int color = 1; color <= 100; color++) {
        pairs += colorCount[color] / 2;
    }

    return pairs;
}

int main() {
    int n;
    scanf("%d", &n);
    int ar[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    int result = sockMerchant(n, ar);
    printf("%d\n", result);
    return 0;
}