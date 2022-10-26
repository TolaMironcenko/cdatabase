//
// Created by Анатолий Миронченко on 25.10.2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/cdatabase/cdatabase.h"
#include "lib/termcolors//termcolors.h"

int main(int argc, char *argv[]) {
    system("clear");
    if (argc < 2) {
        printf("%sUse %s [some do]\n%s", YELLOW, argv[0], RESET);
        exit(0);
    }
    if (!strcmp(argv[1], "createdatabase")) {
        if (argc < 3) {
            printf("%sUse %s %s [database name]\n%s", YELLOW, argv[0], argv[1], RESET);
            exit(0);
        }
        create_database(argv[2]);
    }
    if (!strcmp(argv[1], "deldatabase")) {
        if (argc < 3) {
            printf("%sUse %s %s [database name]\n%s", YELLOW, argv[0], argv[1], RESET);
            exit(0);
        }
        delete_database(argv[2]);
    }
    if (!strcmp(argv[1], "createtable")) {
        if (argc < 4) {
            printf("%sUse %s %s [database name] [table name]\n%s", YELLOW, argv[0], argv[1], RESET);
            exit(0);
        }
        create_table(argv[2], argv[3]);
    }
    if (!strcmp(argv[1], "deltable")) {
        if (argc < 4) {
            printf("%sUse %s %s [database name] [table name]\n%s", YELLOW, argv[0], argv[1], RESET);
            exit(0);
        }
        delete_table(argv[2], argv[3]);
    }
    if (!strcmp(argv[1], "gettables")) {
        if (argc < 3) {
            printf("%sUse %s %s [database name]\n%s", YELLOW, argv[0], argv[1], RESET);
            exit(0);
        }
        print_tables(argv[2]);
    }
    if (!strcmp(argv[1], "createcolumn")) {
        if (argc < 5) {
            printf("%sUse %s %s [database name] [table name] [column name]\n%s", YELLOW, argv[0], argv[1], RESET);
            exit(0);
        }
        create_column(argv[2], argv[3], argv[4]);
    }
    if (!strcmp(argv[1], "delcolumn")) {
        if (argc < 5) {
            printf("%sUse %s %s [database name] [table name] [column name]\n%s", YELLOW, argv[0], argv[1], RESET);
            exit(0);
        }
        delete_column(argv[2], argv[3], argv[4]);
    }
    if (!strcmp(argv[1], "getcolumns")) {
        if (argc < 4) {
            printf("%sUse %s %s [database name] [table name]\n%s", YELLOW, argv[0], argv[1], RESET);
            exit(0);
        }
        print_columns(argv[2], argv[3]);
    }
    return 0;
}