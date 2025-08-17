#include <stdio.h>

long sumXor(long n) {
    int zeroBits = 0;
    while (n) {
        if ((n & 1) == 0) {
            zeroBits++;
        }
        n >>= 1;
    }
    return (n == 0) ? 1L << zeroBits : 1L;
}

int main() {
    long n;
    scanf("%ld", &n);
    printf("%ld\n", sumXor(n));
    return 0;
}
