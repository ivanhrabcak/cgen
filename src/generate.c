#include "generate.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include "alloc.h"
#include "string_funcs.h"
#include "exec.h"
#include "term.h"

void generate_cmake() {
    /*char *project_name = get_project_name();
    printf("name: '%s'\n", project_name);
    char *cmake_version = get_cmake_version();
    printf("version: '%s'\n", cmake_version);*/
    char *language = get_language();
    printf("language: '%s'\n", language);

    /*free(project_name);
    free(cmake_version);
    free(language);*/
}

char *get_project_name() {
    char *trimmed = NULL, *split = NULL;
    char *cwd = exec("/usr/bin/bash -c pwd");
    if (cwd == NULL) {
        if (getcwd(cwd, sizeof(cwd)) == NULL) {
            cwd = NULL;
        }
    }
    if (cwd != NULL) {
        split = get_last_split_item(cwd, '/', PATH_MAX / 4);
        free(cwd);
        cwd = split;
        split = NULL;
    }

    return ask("Enter project name", cwd);
}

char *get_cmake_version() {
    char *output = exec("/usr/bin/cmake --version");
    if (output != NULL) {
        int major, minor, patch;
        sscanf(output, "cmakeversion%d.%d.%d", &major, &minor, &patch);
        memset(output, 0, strlen(output));
        sprintf(output, "%d.%d", major, minor);
    }

    return ask("Enter cmake version", output);
}

char *get_language() {
    char *answers[] = {"C", "CXX"};
    return choose("Choose language", answers, 2);
}
