#include "string_funcs.h"
#include <string.h>
#include <malloc.h>
#include "alloc.h"

char *trim_string(const char *string) {
    char *new = alloc(calloc(strlen(string) + 1, sizeof(char)));
    memset(new, 0, sizeof(string));

    int i;
    for (i = 0; i < strlen(string); i++) {
        char current = string[i];
        if (current == '\0') break;
        if (current == ' ' || current == '\n') continue;
        strncat(new, &current, 1);
    }

    return new;
}

char *get_last_split_item(const char *string, char split, int max_size) {
    char *item = alloc(calloc(max_size, sizeof(char)));

    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == split) {
            memset(item, 0, sizeof(char) * max_size);
        } else {
            strncat(item, &string[i], 1);
        }
    }

    return item;
}
