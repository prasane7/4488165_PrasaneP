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

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

typedef struct {
    int* data;
    int size;
    int capacity;
} Vector;

void vector_init(Vector* v) {
    v->capacity = 2;
    v->size = 0;
    v->data = (int*)malloc(v->capacity * sizeof(int));
}

void vector_push(Vector* v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count) {
    Vector* seqList = malloc(n * sizeof(Vector));
    for (int i = 0; i < n; ++i) {
        vector_init(&seqList[i]);
    }
    int lastAnswer = 0;
    int* results = malloc(queries_rows * sizeof(int));
    int res_idx = 0;

    for (int i = 0; i < queries_rows; ++i) {
        int qtype = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];
        int idx = (x ^ lastAnswer) % n;
        if (qtype == 1) {
            vector_push(&seqList[idx], y);
        } else if (qtype == 2) {
            int value = seqList[idx].data[y % seqList[idx].size];
            lastAnswer = value;
            results[res_idx++] = lastAnswer;
        }
    }

    *result_count = res_idx;

    for (int i = 0; i < n; ++i) {
        free(seqList[i].data);
    }
    free(seqList);

    return results;
}

int main() {
    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));
    int q = parse_int(*(first_multiple_input + 1));

    int** queries = malloc(q * sizeof(int*));
    for (int i = 0; i < q; i++) {
        queries[i] = malloc(3 * sizeof(int));
        char** query_items = split_string(rtrim(readline()));
        for (int j = 0; j < 3; j++) {
            queries[i][j] = parse_int(query_items[j]);
        }
    }

    int result_count;
    int* result = dynamicArray(n, q, 3, queries, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d\n", result[i]);
    }

    free(result);
    for (int i = 0; i < q; i++) {
        free(queries[i]);
    }
    free(queries);

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

        if (data[data_length - 1] == '\n') {
            data[data_length - 1] = '\0';
            break;
        }

        if (data_length == alloc_length) {
            alloc_length <<= 1;
            data = realloc(data, alloc_length);
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) return NULL;
    while (*str && isspace(*str)) str++;
    return str;
}

char* rtrim(char* str) {
    if (!str) return NULL;
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace(*end)) end--;
    *(end + 1) = '\0';
    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");
    int spaces = 0;
    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        splits[spaces - 1] = token;
        token = strtok(NULL, " ");
    }
    return splits;
}

int parse_int(char* str) {
    return (int)strtol(str, NULL, 10);
}
