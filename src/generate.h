#ifndef CGEN_GENERATE_H
#define CGEN_GENERATE_H

#define STDIN_INPUT_LENGTH 256

char *get_project_name();

char *get_cmake_version();

char *get_language();

char *get_language_standard(char *language);

void generate_cmake(char *project_name, char *cmake_version, char *language, char *language_standard);

#endif
