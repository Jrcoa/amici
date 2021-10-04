//
// file: friend_list.h


#ifndef FRIEND_LIST_H
#define FRIEND_LIST_H
#include "amici.h"
#include "hash.h"

typedef struct node_f{
  struct person_s *person;
  struct node_f *next;
} node_t;

typedef struct linked_list_f{
  node_t *head;
  node_t *current;
  size_t size;
} linked_list;

void add_friend (struct person_s *friend, linked_list *list);

linked_list* initialize_list(struct person_s *first_friend);

struct person_s* find_friend(char* handle, linked_list *list);
#endif