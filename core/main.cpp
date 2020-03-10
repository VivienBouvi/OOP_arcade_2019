/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <iostream>

void load_lib(char const *str)
{
    void *handle;
    void (*cosine)(int, int);
    char *error;

    handle = dlopen(str, RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    dlerror();
    *(void **)(&cosine) = dlsym(handle, "Display_Window");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }
    cosine(600, 700);
    dlclose(handle);
    exit(EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Use ./arcade ./lib/[library you want]"
                << std::endl;
    }
    load_lib(argv[1]);
    return 0;
}