#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_char(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

char* gridChallenge(int n, char** grid) {
    for (int i = 0; i < n; i++) {
        qsort(grid[i], n, sizeof(char), cmp_char);
    }
    for (int col = 0; col < n; col++) {
        for (int row = 0; row < n - 1; row++) {
            if (grid[row][col] > grid[row + 1][col]) {
                return "NO";
            }
        }
    }
    return "YES";
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        char** grid = malloc(n * sizeof(char*));
        for (int i = 0; i < n; i++) {
            grid[i] = malloc((n + 1) * sizeof(char));
            scanf("%s", grid[i]);
        }
        char* result = gridChallenge(n, grid);
        printf("%s\n", result);
        for (int i = 0; i < n; i++)
            free(grid[i]);
        free(grid);
    }
    return 0;
}
