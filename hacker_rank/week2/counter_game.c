#include <stdio.h>

long largestPowerOfTwo(long n) {
    long p = 1;
    while (p << 1 <= n) {
        p <<= 1;
    }
    return p;
}

char* counterGame(long n) {
    int moves = 0;
    while (n > 1) {
        if ((n & (n - 1)) == 0) {
            n /= 2;
        } else {
            n -= largestPowerOfTwo(n);
        }
        moves++;
    }
    return (moves % 2 == 0) ? "Richard" : "Louise";
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long n;
        scanf("%ld", &n);
        printf("%s\n", counterGame(n));
    }
    return 0;
}
