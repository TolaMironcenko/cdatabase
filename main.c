//
// Created by Анатолий Миронченко on 25.10.2022.
//

#include <stdio.h>
#include <sys/stat.h>

void create_dir(char *dirname) {
    if (mkdir("da", S_IRWXU | S_IRWXG | S_IRWXO) == -1) {
        perror("create dir error");
    }
}

void delete_dir(char *dirname) {

}

int main() {
    create_dir("da");
    printf("hello world\n");
    return 0;
}