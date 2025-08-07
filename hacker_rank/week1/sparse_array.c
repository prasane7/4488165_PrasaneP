#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buffer[110];

int main() {
    int n;
    scanf("%d", &n);
    char **strings = malloc(n * sizeof(char*));
    for(int i = 0; i < n; i++) {
        scanf("%s", buffer);
        strings[i] = strdup(buffer);
    }

    int q;
    scanf("%d", &q);
    char **queries = malloc(q * sizeof(char*));
    for(int i = 0; i < q; i++) {
        scanf("%s", buffer);
        queries[i] = strdup(buffer);
    }

    for(int i = 0; i < q; i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(strcmp(queries[i], strings[j]) == 0)
                count++;
        }
        printf("%d\n", count);
    }

    
    for(int i = 0; i < n; i++) free(strings[i]);
    for(int i = 0; i < q; i++) free(queries[i]);
    free(strings);
    free(queries);

    return 0;
}
