#ifndef CDATABASE_TERMCOLORS_H
#define CDATABASE_TERMCOLORS_H

//#include <string.h>
//#include <stdio.h>

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define WHITE   "\033[1;37m"
#define GREEN   "\033[1;32m"
#define BLUE   "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"

void cprint(char *string, char *color);// {
//    if (!strcmp(color, "red")) {
//        printf("%s%s%s", RED, string, RESET);
//    }
//    if (!strcmp(color, "yellow")) {
//        printf("%s%s%s", YELLOW, string, RESET);
//    }
//    if (!strcmp(color, "green")) {
//        printf("%s%s%s", GREEN, string, RESET);
//    }
//    if (!strcmp(color, "blue")) {
//        printf("%s%s%s", BLUE, string, RESET);
//    }
//    if (!strcmp(color, "magenta")) {
//        printf("%s%s%s", MAGENTA, string, RESET);
//    }
//    if (!strcmp(color, "cyan")) {
//        printf("%s%s%s", CYAN, string, RESET);
//    }
//}

#endif