#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* caesarCipher(char* s, int k) {
    int len = strlen(s);
    char* encrypted = (char*)malloc((len + 1) * sizeof(char));
    k = k % 26;
    for (int i = 0; i < len; i++) {
        char ch = s[i];
        if (ch >= 'a' && ch <= 'z') {
            encrypted[i] = ((ch - 'a' + k) % 26) + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z') {
            encrypted[i] = ((ch - 'A' + k) % 26) + 'A';
        }
        else {
            encrypted[i] = ch;
        }
    }
    encrypted[len] = '\0';
    return encrypted;
}

char* readline();
char* ltrim(char*);
char* rtrim(char*);
int parse_int(char*);

int main() {
    int n = parse_int(ltrim(rtrim(readline())));
    char* s = readline();
    int k = parse_int(ltrim(rtrim(readline())));
    char* result = caesarCipher(s, k);
    printf("%s\n", result);
    free(result);
    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);
    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);
        if (!line) break;
        data_length += strlen(cursor);
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') break;
        alloc_length <<= 1;
        data = realloc(data, alloc_length);
        if (!data) break;
    }
    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    } else {
        data = realloc(data, data_length + 1);
        data[data_length] = '\0';
    }
    return data;
}

char* ltrim(char* str) {
    if (!str) return NULL;
    while (*str != '\0' && isspace(*str)) str++;
    return str;
}

char* rtrim(char* str) {
    if (!str) return NULL;
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace(*end)) end--;
    *(end + 1) = '\0';
    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') exit(EXIT_FAILURE);
    return value;
}
