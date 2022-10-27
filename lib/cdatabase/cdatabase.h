//
// Created by Анатолий Миронченко on 26.10.2022.
//

#ifndef CDATABASE_CDATABASE_H
#define CDATABASE_CDATABASE_H

int create_database(char *base_name);

int delete_database(char *base_name);

int create_table(char *base_name, char *table_name);

int delete_table(char *base_name, char *table_name);

void print_tables(char *base_name);

int create_column(char *base_name, char *table_name, char *column_name);

int delete_column(char *base_name, char *table_name, char *column_name);

void print_columns(char *base_name, char *table_name);

int create_data(char *base_name, char *table_name, int argc, char *argv[]);

void print_data(char *base_name, char *table_name);

#endif