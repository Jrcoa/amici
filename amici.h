//
// file: amici.h
// author: joseph casale
#ifndef AMICI_H
#define AMICI_H
#define _DEFAULT_SOURCE  // strdup
#define MAX_COMMAND_SIZE 1024
#define MAX_NAME_SIZE 256
#define MAX_FRIENDS 1000 
#include "friend_list.h"
#include "table.h"
typedef struct person_s {
    char *firstname;
    char *lastname;
    char *handle;
    linked_list *friends;
    size_t friend_count;
    size_t max_friends;
} person_t;

void l_ptr_str_print(const void* key, const void* value);

void delete_l_ptr_str(void* key, void* value);

int add_person(const char* firstname, const char* lastname, const char* handle, Table handles);
#endif