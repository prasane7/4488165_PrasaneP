#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* to24Hour(const char* input) {
    int h, m, s;
    char suffix[3];
    char* result = malloc(9); 
    
    sscanf(input, "%2d:%2d:%2d%2s", &h, &m, &s, suffix);

    if (suffix[0] == 'A') {
        if (h == 12) h = 0;
    } else {
        if (h != 12) h += 12;
    }
    
    sprintf(result, "%02d:%02d:%02d", h, m, s);
    return result;
}

int main() {
    char timeInput[11];
    scanf("%10s", timeInput);
    char* formatted = to24Hour(timeInput);
    printf("%s\n", formatted);
    free(formatted);
    return 0;
}
