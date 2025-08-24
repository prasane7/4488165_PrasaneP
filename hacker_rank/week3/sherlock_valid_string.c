#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[100005];
    int freq[26] = {0}, count[100005] = {0}, n, i, f1 = 0, f2 = 0, c1 = 0, c2 = 0;
    scanf("%s", s);
    n = strlen(s);
    for (i = 0; i < n; ++i) freq[s[i] - 'a']++;
    for (i = 0; i < 26; ++i) if (freq[i]) count[freq[i]]++;
    for (i = 1; i <= n; ++i) {
        if (count[i]) {
            if (!f1) { f1 = i; c1 = count[i]; }
            else if (!f2) { f2 = i; c2 = count[i]; }
            else { printf("NO\n"); return 0; }
        }
    }
    if (!f2 || (c2 == 1 && (f2 - f1 == 1 || f2 == 1)))
        printf("YES\n");
    else if (c1 == 1 && (f1 - f2 == 1 || f1 == 1))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
