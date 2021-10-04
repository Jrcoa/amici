//
// file: friend_list.c

#include "amici.h"
#include "hash.h"
#include <stdlib.h>
#include <string.h>

linked_list* initialize_list(person_t *first_friend){
  node_t *first = malloc(sizeof(node_t));
  linked_list *list = malloc(sizeof(linked_list));
  
  first -> person = first_friend;
  first -> next = NULL;
   
  list -> size = 1; 
  list -> head = first;
  list -> current = first;
  return list;
}

void add_friend (person_t *friend, linked_list *list){
  node_t *newnode = malloc(sizeof(node_t));
  newnode -> person = friend;
  newnode -> next = NULL;
  
  list -> current -> next = newnode;
  list -> current = list -> current -> next;
  list -> size++;
}

person_t* find_friend(char* handle, linked_list *list){
  if(strcmp(list -> head -> person -> handle, handle) == 0){
    return list->head -> person ;
  }
  node_t *curr = list -> head;
  while(curr != NULL){
    curr = curr -> next;
    if(strcmp(curr -> person -> handle, handle) == 0){
      return curr -> person;
    }
  }
  return (person_t*)NULL;
}


