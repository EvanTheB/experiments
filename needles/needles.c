#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);


struct thing
{
    struct thing * t[24];
    int max;
    int cur;
    int *e;
};

struct thing makeg(char **genes, int n)
{
    struct thing *flist = malloc(n * (sizeof *flist));

    struct thing root = {0};

    for (int i = 0; i < n; ++i)
    {
        struct thing *cur = &root;
        char *s = genes[i];
        // printf("%s\n", s);
        while(*s)
        {
            if (cur->t[*s - 'a'] == NULL)
            {
                cur->t[*s - 'a'] = flist++;
                *cur->t[*s - 'a'] = (struct thing){0};
            }
            cur = cur->t[*s - 'a'];
            s++;
        }
        if (cur->max <= cur->cur)
        {
            cur->e = realloc(cur->e, (sizeof *(cur->e)) * (cur->max < 1 ? 8 : cur->max * 2));
        }
        cur->e[cur->cur] = i;
        cur->cur++;
        // for (int j = 0; j < cur->cur; ++j)
        // {
        //     printf("%d\n", cur->e[j]);
        // }
    }
    return root;
}

int dothing(struct thing *g, int* vs, int first, int last, char *d)
{
    int score = 0;
    struct thing **cur_states = calloc(100, sizeof *cur_states);
    struct thing **next_states = calloc(100, sizeof *next_states);
    cur_states[0] = g;
    // printf("%d %d %s\n", first, last, d);
    while (*d)
    {
        // printf("%c\n", *d);
        next_states[0] = g;
        struct thing **nex = (next_states + 1);
        struct thing **cur = cur_states;
        while (*cur)
        {
            if ((*cur)->t[*d - 'a'] != NULL)
            {
                *nex = (*cur)->t[*d - 'a'];
                nex++;
            }
            cur++;
        }
        nex = next_states;
        while(*nex)
        {
            // printf("%d\n", (*nex)->cur);
            for (int i = 0; i < (*nex)->cur; ++i)
            {
                int val = (*nex)->e[i];
                // printf("x%d %d\n", val, vs[val]);
                if (first <= val && val <= last)
                {
                    score += vs[val];
                }
            }
            nex++;
        }
        memcpy(cur_states, next_states, 100 * sizeof *cur_states);
        memset(next_states, 0, 100 * sizeof *next_states);
        d++;
    }
    return score;
}

int main()
{
    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char** genes_temp = split_string(readline());

    char** genes = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        char* genes_item = *(genes_temp + i);

        *(genes + i) = genes_item;
    }
    struct thing g = makeg(genes, n);

    char** health_temp = split_string(readline());

    int* health = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* health_item_endptr;
        char* health_item_str = *(health_temp + i);
        int health_item = strtol(health_item_str, &health_item_endptr, 10);

        if (health_item_endptr == health_item_str || *health_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(health + i) = health_item;
    }

    char* s_endptr;
    char* s_str = readline();
    int s = strtol(s_str, &s_endptr, 10);

    if (s_endptr == s_str || *s_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int s_itr = 0; s_itr < s; s_itr++) {
        char** firstLastd = split_string(readline());

        char* first_endptr;
        char* first_str = firstLastd[0];
        int first = strtol(first_str, &first_endptr, 10);

        if (first_endptr == first_str || *first_endptr != '\0') { exit(EXIT_FAILURE); }

        char* last_endptr;
        char* last_str = firstLastd[1];
        int last = strtol(last_str, &last_endptr, 10);

        if (last_endptr == last_str || *last_endptr != '\0') { exit(EXIT_FAILURE); }

        char* d = firstLastd[2];

        printf("%d\n", dothing(&g, health, first, last, d));
    }

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
