#include <stdio.h>
#include <stdlib.h>

int compare_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compare_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

char* twoArrays(int k, int A[], int B[], int n) {
    qsort(A, n, sizeof(int), compare_asc);
    qsort(B, n, sizeof(int), compare_desc);
    for (int i = 0; i < n; i++) {
        if (A[i] + B[i] < k) {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    int q;
    scanf("%d", &q);
    for (int t = 0; t < q; t++) {
        int n, k;
        scanf("%d %d", &n, &k);
        int A[n], B[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &B[i]);
        printf("%s\n", twoArrays(k, A, B, n));
    }
    return 0;
}
