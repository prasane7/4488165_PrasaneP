#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* pangrams(char* s) {
    int present[26] = {0};
    int count = 0;
    char* answer;

    for (int i = 0; s[i] != '\0'; ++i) {
        if (isalpha(s[i])) {
            int idx = tolower(s[i]) - 'a';
            if (present[idx] == 0) {
                present[idx] = 1;
                count++;
            }
        }
    }

    if (count == 26) {
        answer = (char*)malloc(8 * sizeof(char));
        strcpy(answer, "pangram");
    } else {
        answer = (char*)malloc(12 * sizeof(char));
        strcpy(answer, "not pangram");
    }

    return answer;
}

int main() {
    char str[1000];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    char* result = pangrams(str);
    printf("%s\n", result);
    free(result);

    return 0;
}
