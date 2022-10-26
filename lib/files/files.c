//
// Created by Анатолий Миронченко on 26.10.2022.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

void create_dir(char *dirname, mode_t mode) {
    if (mkdir(dirname, mode) == -1) {
        perror("create dir error");
        exit(1);
    }
}

void delete_dir(char *dirname) {
    struct dirent *pDirent;
    DIR *pDir;

    pDir = opendir (dirname);
    if (pDir == NULL) {
        perror("Cannot open directory");
    }
    while ((pDirent = readdir(pDir)) != NULL) {
        if (!strcmp(pDirent->d_name, ".") || !strcmp(pDirent->d_name, "..")) {
            continue;
        }
        if (pDirent->d_type == 4) {
            char path[1024];
            strcpy(path, dirname);
            strcat(path, "/");
            strcat(path, pDirent->d_name);
            delete_dir(path);
        }
        else {
            char path[1024];
            strcpy(path, dirname);
            strcat(path, "/");
            strcat(path, pDirent->d_name);
            if (remove(path) < 0) {
                perror("remove file error");
            }
            else {
                printf("file delete successful\n");
            }
        }
    }
    closedir (pDir);

    remove(dirname);
}