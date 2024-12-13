//
// Created by Анатолий Миронченко on 26.10.2022.
//

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include "../termcolors/termcolors.h"
#include "../files/files.h"
#include <stdlib.h>
#include <dirent.h>
#include "cdatabase.h"

int create_database(char *base_name) {
    struct stat st = {0};
    if (stat(base_name, &st) != -1) {
        printf("%sDatabase alredy exist\n%s", YELLOW, RESET);
        return -1;
    } else {
        create_dir(base_name, 0700);
        char datapath[1024];
        strcpy(datapath, base_name);
        strcat(datapath, "/data");
        create_dir(datapath, 0700);
        printf("%sDatabase create successful\n%s", GREEN, RESET);
    }
    return 0;
}

int delete_database(char *base_name) {
    struct stat st = {0};
    if (stat(base_name, &st) == -1) {
        printf("%sYou don't have this database.\n%s", YELLOW, RESET);
        return -1;
    } else {
        delete_dir(base_name);
        printf("%sdeleted database %s successful\n%s", GREEN, base_name, RESET);
    }
    return 0;
}

int create_table(char *base_name, char *table_name) {
    char datapath[1024];
    strcpy(datapath, base_name);
    strcat(datapath, "/data/");
    strcat(datapath, table_name);
    struct stat st = {0};
    if (stat(datapath, &st) != -1) {
        printf("%sTable already exist\n%s", YELLOW, RESET);
        return -1;
    } else {
        create_dir(datapath, 0700);
        printf("%sTable create successful\n%s", GREEN, RESET);
    }
    return 0;
}

int delete_table(char *base_name, char *table_name) {
    char datapath[1024];
    strcpy(datapath, base_name);
    strcat(datapath, "/data/");
    strcat(datapath, table_name);
    struct stat st = {0};
    if (stat(datapath, &st) == -1) {
        printf("%sYou don't have this table.\n%s", YELLOW, RESET);
        return -1;
    } else {
        delete_dir(datapath);
        printf("%sdeleted table %s successful\n%s", GREEN, table_name, RESET);
    }
    return 0;
}

void print_tables(char *base_name) {
    struct dirent *pDirent;
    DIR *pDir;
    char datapath[1024];
    strcpy(datapath, base_name);
    strcat(datapath, "/data");
    pDir = opendir(datapath);
    if (pDir == NULL) {
        printf("%sCannot open this database:%s you don't have this database\n", RED, RESET);
        exit(0);
    }
    int iterator = 0;
    printf("%sDATABASE: %s\n%s", GREEN, base_name, RESET);
    cprint("-----------------------------------\n", "blue");
    while ((pDirent = readdir(pDir)) != NULL) {
        if (!strcmp(pDirent->d_name, ".") || !strcmp(pDirent->d_name, "..")) {
            continue;
        }
        printf("%s|%s %d %s|%s %s %s|%s\n", BLUE, RESET, iterator+1, BLUE, RESET, pDirent->d_name, BLUE, RESET);
        cprint("-----------------------------------\n", "blue");
        iterator++;
    }
}

int create_column(char *base_name, char *table_name, char *column_name) {
    char datapath[1024];
    strcpy(datapath, base_name);
    strcat(datapath, "/data/");
    strcat(datapath, table_name);
    strcat(datapath, "/");
    strcat(datapath, column_name);
    FILE *column = fopen(datapath, "w+b");
    if (column == NULL) {
        printf("%sCreate column error:%s don't have this table\n", RED, RESET);
        return -1;
    }
    fclose(column);
    cprint("Column create successful\n", "green");
    return 0;
}

int delete_column(char *base_name, char *table_name, char *column_name) {
    char datapath[1024];
    strcpy(datapath, base_name);
    strcat(datapath, "/data/");
    strcat(datapath, table_name);
    strcat(datapath, "/");
    strcat(datapath, column_name);
    if (remove(datapath) < 0) {
        printf("%sDelete column error:%s don't have this column\n", RED, RESET);
        return -1;
    } else {
        cprint("Column delete successful\n", "green");
    }
    return 0;
}

void print_columns(char *base_name, char *table_name) {
    struct dirent *pDirent;
    DIR *pDir;
    char datapath[1024];
    strcpy(datapath, base_name);
    strcat(datapath, "/data/");
    strcat(datapath, table_name);
    pDir = opendir(datapath);
    if (pDir == NULL) {
        printf("%sCannot open this database/table:%s you don't have this database/table\n", RED, RESET);
        exit(0);
    }
    int iterator = 0;
    printf("%sDATABASE: %s\n%s", GREEN, base_name, RESET);
    printf("%sTABLE: %s\n%s", GREEN, table_name, RESET);
    cprint("-----------------------------------\n", "blue");
    while ((pDirent = readdir(pDir)) != NULL) {
        if (!strcmp(pDirent->d_name, ".") || !strcmp(pDirent->d_name, "..")) {
            continue;
        }
        printf("%s|%s %d %s|%s %s %s|%s\n", BLUE, RESET, iterator+1, BLUE, RESET, pDirent->d_name, BLUE, RESET);
        cprint("-----------------------------------\n", "blue");
        iterator++;
    }
}

int create_data(char *base_name, char *table_name, int argc, char *argv[]) {
    char datapath[1024];
    strcpy(datapath, base_name);
    strcat(datapath, "/data/");
    strcat(datapath, table_name);
    strcat(datapath, "/");
    for (int i = 4; i < argc; i += 2) {
        char filepath[1024];
        strcpy(filepath, datapath);
        strcat(filepath, argv[i]);
        if (fopen(filepath, "r") == NULL) {
            printf("%sCreate data error:%s you don't have this column - %s\n", RED, RESET, argv[i]);
            return -1;
        }
        FILE *file = fopen(filepath, "a+w");
        char tofile[BUFSIZ];
        memset(&tofile, '\0', BUFSIZ);
        strcpy(tofile, argv[i+1]);
        strcat(tofile, "\n");
        fputs(tofile, file);
        fclose(file);
    }
    cprint("Successful create data\n", "green");
    return 0;
}

void print_data(char *base_name, char *table_name) {
    struct dirent *pDirent;
    DIR *pDir;
    char datapath[1024];
    strcpy(datapath, base_name);
    strcat(datapath, "/data/");
    strcat(datapath, table_name);
    strcat(datapath, "/");
    pDir = opendir(datapath);
    if (pDir == NULL) {
        printf("%sCannot open this database/table:%s you don't have this database/table\n", RED, RESET);
        exit(0);
    }
    printf("%sDATABASE: %s\n%s", GREEN, base_name, RESET);
    printf("%sTABLE: %s\n%s", GREEN, table_name, RESET);
    int iterator = 0;
    while ((pDirent = readdir(pDir)) != NULL) {
        if (!strcmp(pDirent->d_name, ".") || !strcmp(pDirent->d_name, "..")) {
            continue;
        }
//        char *filedata;
        char filepath[1024];
        memset(&filepath, '\0', 1024);
        strcpy(filepath, datapath);
        strcat(filepath, pDirent->d_name);
        printf("%s\n", filepath);
        FILE *datafile = fopen(filepath, "r");
        printf("%s|%s %d %s|%s %s %s|%s ", BLUE, RESET, iterator+1, BLUE, RESET, pDirent->d_name, BLUE, RESET);
        char some_data[1024];
//        int len = 0;
//        printf("%s\n%zu", some_data, len);
        while(1) {
            memset(some_data, '\0', 1024);
            if(fgets(some_data, 1024, datafile) == (char *) NULL )
            {
                break;
            }
            for (int i = 0; i < 1024; i++) {
              if (some_data[i] == '\n') {
                some_data[i] = ' ';
              }
            }
            printf("%s%s|%s ", some_data, BLUE, RESET);
        }
//        printf("%s\n", some_data);
        fclose(datafile);
        cprint("-----------------------------------\n", "blue");
        iterator++;
    }
}
