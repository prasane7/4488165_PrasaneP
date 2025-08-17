#include <stdio.h>
#include <string.h>

long long digit_sum(const char *n) {
    long long sum = 0;
    for (int i = 0; n[i] != '\0'; i++) {
        sum += n[i] - '0';
    }
    return sum;
}

int superDigitHelper(long long num) {
    if (num < 10)
        return (int)num;
    long long next = 0;
    while (num > 0) {
        next += num % 10;
        num /= 10;
    }
    return superDigitHelper(next);
}

int superDigit(char *n, int k) {
    long long initial_sum = digit_sum(n);
    long long total = initial_sum * k;
    return superDigitHelper(total);
}

int main() {
    char n[100001];
    int k;
    scanf("%s %d", n, &k);
    int result = superDigit(n, k);
    printf("%d\n", result);
    return 0;
}
