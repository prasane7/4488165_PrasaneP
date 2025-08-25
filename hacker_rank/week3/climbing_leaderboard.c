#include <stdio.h>
#include <stdlib.h>

int uniqueScores(int *r, int n, int *res) {
    int cnt = 1;
    res[0] = r[0];
    for(int i = 1; i < n; i++) {
        if(r[i] != r[i-1]) {
            res[cnt++] = r[i];
        }
    }
    return cnt;
}

int getRank(int *res, int len, int score) {
    int low = 0, high = len - 1, mid;
    int pos = len;
    while(low <= high) {
        mid = low + (high - low)/2;
        if(res[mid] == score) return mid + 1;
        else if(res[mid] > score) low = mid + 1;
        else {
            pos = mid;
            high = mid - 1;
        }
    }
    return pos + 1;
}

int main() {
    int n, m;
    scanf("%d", &n);
    int *ranked = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &ranked[i]);

    int *uniq = malloc(n * sizeof(int));
    int ulen = uniqueScores(ranked, n, uniq);

    scanf("%d", &m);
    int *player = malloc(m * sizeof(int));
    for(int i = 0; i < m; i++) scanf("%d", &player[i]);

    for(int i = 0; i < m; i++) {
        int rank = getRank(uniq, ulen, player[i]);
        printf("%d\n", rank);
    }

    free(ranked);
    free(uniq);
    free(player);
    return 0;
}
