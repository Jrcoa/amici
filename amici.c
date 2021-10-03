
#define _DEFAULT_SOURCE  // strdup
#define MAX_COMMAND_SIZE 1024
#define MAX_FRIENDS 1000 
#include <assert.h>  // assert
#include <stdio.h>   // printf, fprintf
#include <stdlib.h>  // rand, srand, EXIT_SUCCESS
#include <string.h>  // strcmp
#include <stdbool.h> // bool
#include <string.h>  // strdup
#include <time.h>    // time
#include "hash.h"    // long_hash, long_equals, long_str_print, str_hash, str_equals
                     // str_long_print, longlong_print
#include "table.h"   // ht_create, ht_destroy, ht_dump, ht_get, ht_has, ht_put

// File: amici.c
// Author: Joseph Casale

/////////////////////////////
// Definition of a person
typedef struct person_s {
    char *firstname;
    char *lastname;
    char *handle;
    struct person_s **friends;
    size_t friend_count;
    size_t max_friends;
} person_t;

////////////////////////////
void l_ptr_str_print(const void* key, const void* value){
    char *k = (char*)key;
    person_t *v = (person_t*)value;
    printf("%s", k);
    printf("%s", (v) -> firstname); 
}

size_t l_ptr_hash(const void* element){
    return (size_t)element;
}
void delete_l_ptr_str(void* key, void* value){
    
    free(key);
    //free(value->handle);
    free(value);
}
bool l_ptr_equals(const void* key1, const void* key2){
    return (long)key1 == (long)key2;
}



// Database of handles
//Table handles = ht_create(
//    l_ptr_hash, l_ptr_equals, l_ptr_str_print, delete_l_ptr_str
//);
//Table h = ht_create(long_hash, long_equals, long_str_print, NULL);
int add_person(char* firstname, char* lastname, char* handle, Table handles){
   
    person_t *new = malloc(sizeof(person_t));

 
    new -> firstname = firstname;
    new -> lastname = lastname;
    new -> handle = handle;
    new -> friends = NULL;
    new -> friend_count = 0;
    new -> max_friends = MAX_FRIENDS;
    
    puts(new->firstname);
    ht_put(handles, &(new -> handle), &new);
    person_t *res = *(person_t**)ht_get(handles, &new->handle);
    puts(res->firstname);
    return 0;
}


int main(void){
    
    printf("top");
    //Database of handles
    Table handles = ht_create(l_ptr_hash, l_ptr_equals, l_ptr_str_print, delete_l_ptr_str );
    

    char command[MAX_COMMAND_SIZE];
    while(true){
        fgets(command, MAX_COMMAND_SIZE-1, stdin);
        puts(command);
        add_person("joe", "casale", "jr", handles);
    }

}

