
#include <string.h>
#include <stdio.h>
#include "termcolors.h"

void cprint(char *string, char *color) {
    if (!strcmp(color, "red")) {
        printf("%s%s%s", RED, string, RESET);
    }
    if (!strcmp(color, "yellow")) {
        printf("%s%s%s", YELLOW, string, RESET);
    }
    if (!strcmp(color, "green")) {
        printf("%s%s%s", GREEN, string, RESET);
    }
    if (!strcmp(color, "blue")) {
        printf("%s%s%s", BLUE, string, RESET);
    }
    if (!strcmp(color, "magenta")) {
        printf("%s%s%s", MAGENTA, string, RESET);
    }
    if (!strcmp(color, "cyan")) {
        printf("%s%s%s", CYAN, string, RESET);
    }
}