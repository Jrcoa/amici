//
// File: amici.c
// Author: Joseph Casale

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
#include "amici.h"
#include "friend_list.h"
////////////////////////////
// Definition of a person
////////////////////////////
///char* firstname//////////
///char* lastname///////////
///char* handle/////////////
void l_ptr_str_print(const void* key, const void* value){
    char *k = (char*)key;
    person_t *v = (person_t*)value;
    printf("%s", k);
    printf("%s", (v) -> firstname); 
}


void delete_l_ptr_str(void* key, void* value){
    
    free(key);
    //free(value->handle);
    free(value);
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
    new -> friend_count = 0;
    new -> max_friends = MAX_FRIENDS;

    ht_put(handles,(void*)(handle), new);
    //const char * lookup = "jrc4615";

    //lookup = (void*)lookup;
    //fprintf(stderr,"x%sx%sx", lookup, new->handle);
    //person_t *res = (person_t*)ht_get(handles,(void*)lookup);
    //fprintf(stderr,"first: %s last: %s handle: %s", res->firstname, res->lastname, res->handle);
    ht_dump(handles, true);
    return 0;
}


int main(void){
    
    //printf("top");
    //Database of handles
    Table handles = ht_create(str_hash, str_equals, l_ptr_str_print, delete_l_ptr_str );
    

    while(true){
    
        char *command = malloc(MAX_COMMAND_SIZE);
        printf("You entered: %s\n", command);
        fputs("amici> ", stdout);
        fgets(command, MAX_COMMAND_SIZE-1, stdin);
        char* tok = strtok(command, " ");
                
        if(strcmp(tok, "add") == 0){
            char *firstname = strtok(NULL, " ");
            char *lastname = strtok(NULL, " ");
            char *handle = strtok(NULL, " ");
            
            handle[strcspn(handle, "\n")] = 0;
            if(ht_has(handles, (void*)handle)){
                //has handle, currently pushing right to stderr
                fprintf(stderr, 
                     "error: handle '%s' is already taken. Try another handle.\n",
                     handle);
                //prompt againi
                free(command);
                continue;
            }

            printf("first: %s last: %s h: %s\n", firstname, lastname, handle);
            add_person(firstname, lastname, handle, handles);
            free(command);
        }
    }
}



