#include <stdlib.h>

#include <stdio.h>

#include "history.h"

#include "tokenizer.h"



/* Initialize the linked list to keep the history. */


List* init_history(){

  List *list = malloc(sizeof(List));

  list->root = malloc(sizeof(Item));

  return list;
}



/* Add a history item to the end of the list.

   List* list - the linked list

   char* str - the string to store

*/

void add_history(List *list, char *str){
  Item *actualNode = (*list).root;

  Item *newNode = (Item*) malloc(sizeof(Item));

  (*newNode).next = NULL;
  
}



/* Retrieve the string stored in the node where Item->id == id.

   List* list - the linked list

   int id - the id of the Item to find */

char *get_history(List *list, int id)
{

  Item *actualNode = list->root;



  // If history is empty

  if (actualNode == NULL)

    return "History is empty";



  while (actualNode != NULL){

    if (actualNode->id == id)

      return actualNode->str;

    actualNode = actualNode->next;

  }



  return "No such ID";  // ID doesn't exist



}



/*Print the entire contents of the list. */

void print_history(List *list)
{

  Item *actualNode = list->root;



  while (actualNode != NULL){

    printf ("H[%d] %s\n", actualNode->id, actualNode->str);

    actualNode = actualNode->next;

  }

}



/*Free the history list and the strings it references. */

void free_history(List *list)
{

  Item *actualNode;



  while (list->root != NULL){

    actualNode = list->root;

    list->root = list->root->next;

    free(actualNode->str);

    free(actualNode);

  }

  free(list);

}
