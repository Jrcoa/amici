#include "amici.h"
#include "friend_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  printf("initializing first person...");
  person_t *person1 = malloc(sizeof(person_t));
  person_t *person2 = malloc(sizeof(person_t));

  person1 -> handle = "guy";
  person1 -> firstname = "guyguy";
  person1 -> lastname = "jenkins";
  
  person2 -> handle = "masterjenkins";
  person2 -> firstname = "god";
  person2 -> lastname = "name";
  
  person1 -> friends = initialize_list(person2);
  person2 -> friends = initialize_list(person1);
  
  printf("%s should be masterjenkins\n" , person1->friends->head->person -> handle);
  
  person_t *person3 = malloc(sizeof(person_t));
  
  person3 -> handle = "person3handle";
  person3 -> firstname = "joseph";
  person3 -> lastname = "lastname3";
  
  add_friend(person3, person1 -> friends);
  person_t *p = find_friend("person3handle", person1 -> friends);
  printf("%s should be joseph\n", p->firstname);
  
  p = find_friend("masterjenkins", person1 -> friends);
  printf("%s should be god\n", p -> firstname);
}