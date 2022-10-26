//
// Created by Анатолий Миронченко on 25.10.2022.
//

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "lib/files.h"
#include <string.h>

int main(int argc, char *argv[]) {
    system("clear");
    if (argc < 2) {
        printf("Use %s [some do]\n", argv[0]);
        exit(0);
    }
    if (!strcmp(argv[1], "createdatabase")) {
        if (argc < 3) {
            printf("Use %s %s [database name]\n", argv[0], argv[1]);
            exit(0);
        }
        struct stat st = {0};
        if (stat(argv[2], &st) == -1) {
            create_dir(argv[2], 0700);
            char datapath[1024];
            strcpy(datapath, argv[2]);
            strcat(datapath, "/data");
            create_dir(datapath, 0700);
            printf("Database create successful\n");
        } else {
            printf("Database alredy exist\n");
        }
    }
    if (!strcmp(argv[1], "deldatabase")) {
        if (argc < 3) {
            printf("Use %s %s [database name]\n", argv[0], argv[1]);
            exit(0);
        }
        struct stat st = {0};
        if (stat(argv[2], &st) == -1) {
            printf("You don't have this database.\n");
        } else {
            delete_dir(argv[2]);
            printf("deleted database %s successful\n", argv[2]);
        }
    }
    if (!strcmp(argv[1], "createtable")) {
        if (argc < 4) {
            printf("Use %s %s [database name] [table name]\n", argv[0], argv[1]);
            exit(0);
        }
        char datapath[1024];
        strcpy(datapath, argv[2]);
        strcat(datapath, "/data/");
        strcat(datapath, argv[3]);
        struct stat st = {0};
        if (stat(datapath, &st) == -1) {
            create_dir(datapath, 0700);
            printf("Table create successful\n");
        } else {
            printf("Table already exist\n");
        }
    }
    if (!strcmp(argv[1], "deltable")) {
        if (argc < 4) {
            printf("Use %s %s [database name] [table name]\n", argv[0], argv[1]);
            exit(0);
        }
        char datapath[1024];
        strcpy(datapath, argv[2]);
        strcat(datapath, "/data/");
        strcat(datapath, argv[3]);
        struct stat st = {0};
        if (stat(datapath, &st) == -1) {
            printf("You don't have this table.\n");
        } else {
            delete_dir(datapath);
            printf("deleted table %s successful\n", argv[3]);
        }
    }
    return 0;
}