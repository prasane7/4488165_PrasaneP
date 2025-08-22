#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_grid(int r, int c, char** grid) {
    for (int i = 0; i < r; i++) {
        printf("%s\n", grid[i]);
    }
}

void free_grid(int r, char** grid) {
    if (grid == NULL) return;
    for (int i = 0; i < r; i++) {
        free(grid[i]);
    }
    free(grid);
}

char** detonate(int r, int c, char** initial_grid) {
    char** new_grid = (char**)malloc(r * sizeof(char*));
    for (int i = 0; i < r; i++) {
        new_grid[i] = (char*)malloc((c + 1) * sizeof(char));
        memset(new_grid[i], 'O', c);
        new_grid[i][c] = '\0';
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (initial_grid[i][j] == 'O') {
                new_grid[i][j] = '.';
                if (i > 0) new_grid[i - 1][j] = '.';
                if (i < r - 1) new_grid[i + 1][j] = '.';
                if (j > 0) new_grid[i][j - 1] = '.';
                if (j < c - 1) new_grid[i][j + 1] = '.';
            }
        }
    }
    return new_grid;
}

void bomberMan(long n, int r, int c, char** grid) {
    if (n < 2) {
        print_grid(r, c, grid);
        return;
    }

    if (n % 2 == 0) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                printf("O");
            }
            printf("\n");
        }
        return;
    }

    char** grid_after_first_detonation = detonate(r, c, grid);
    
    if (n % 4 == 3) {
        print_grid(r, c, grid_after_first_detonation);
        free_grid(r, grid_after_first_detonation);
        return;
    }
    
    if (n % 4 == 1) {
        char** grid_after_second_detonation = detonate(r, c, grid_after_first_detonation);
        print_grid(r, c, grid_after_second_detonation);
        free_grid(r, grid_after_second_detonation);
        free_grid(r, grid_after_first_detonation);
        return;
    }
}

int main() {
    int r, c;
    long n;
    scanf("%d %d %ld", &r, &c, &n);

    char** grid = (char**)malloc(r * sizeof(char*));
    for (int i = 0; i < r; i++) {
        grid[i] = (char*)malloc((c + 1) * sizeof(char));
        scanf("%s", grid[i]);
    }

    bomberMan(n, r, c, grid);
    
    free_grid(r, grid);

    return 0;
}