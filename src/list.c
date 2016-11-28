/* -------------------------------------------------------------------------
@file list.c
  ___| |___ _   _(_)_______
 / _ \ / __| | | | |_  / _ \
|  __/ \__ \ |_| | |/ / (_) |
 \___|_|___/\__,_|_/___\___/
@date 04/12/16 22:18:33
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Implementation of a linked list datatype
@detail

Licence:
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
---------------------------------------------------------------------------*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../inc/list.h"

/*------------------------------------------------------------------------------
                                list_init
------------------------------------------------------------------------------*/
void list_init(Slinked_list* list) {
    // initialize the list
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return ;
}

/*------------------------------------------------------------------------------
                                list_destroy
------------------------------------------------------------------------------*/
void list_destroy(Slinked_list* list, DESTROY destroy_func) {

   void* data;
   // remove each element of the list
   while(list_size(list) > 0) {
      if(list_remove_next(list, NULL, (void **)&data) == 0 && destroy_func != NULL) {
         // call a user-defined function to free dinamically allocated data
         destroy_func(data);
      }
   }
   // no operation is allowed now, but clear the structure  as precaution
   //memset(list, 0, sizeof(list));
   //TODO(elsuizo) ver que era esto
   return;
}

/*------------------------------------------------------------------------------
                            list_ins_next
------------------------------------------------------------------------------*/

int list_insert_next(Slinked_list* list, Node* node, const void* data) {

   Node* new_element;
   // allocated storage for the element
   if ((new_element = (Node*)malloc(sizeof(Node))) == NULL) return -1;

   // insert the element into the list
   new_element->data = (void*)data;

   if (node == NULL) {
      // handle insertion at the head of the list
      new_element->next = list->head;
      list->head = new_element;
   } else {
      // handle insertion somewhere other that the head
      if (node->next == NULL){
         list->tail = new_element;
      }
      new_element->next = node->next;
      node->next = new_element;
   }
   // adjust the size of the list to account for  the inserted element
   list->size++;

   return 0;
}


/*------------------------------------------------------------------------------
                            list_remove_next
------------------------------------------------------------------------------*/
/**
 * @brief Remove the next element in single linked list
 *
 * @param list
 * @param element
 * @param data
 *
 * @return
 */

/* FIXME(elsuizo: 2016-11-27) esto no tiene que devolver int ??? */
int list_remove_next(Slinked_list* list, Node* element, void** data) {
   Node *old_element;
   // do not allow removal from an empty list
   if (list_size(list) == 0) return -1;

   // remove the element from the list
   if (element == NULL){
      // handle removal from the head of the list
      *data = list->head->data; // put the data in the head
      old_element = list->head;
      list->head = list->head->next;

      if (list_size(list) == 1) {
         list->tail = NULL;
      }
   } else {
      // handle removal from somewhere other than the head
      if (element->next == NULL) return -1;

      *data = element->next->data;
      old_element = element->next;
      element->next = element->next->next;

      if (element->next == NULL) {
         list->tail = element;
      }
   }
   // free the storage allocated by the  abstract datatype
   free(old_element);
   // adjust the size of list to account for the removed element
   list->size--;

   return 0;
}

/**
 * @brief Display all elements in a Single linked list
 *
 * @param list
 * @param display_func
 * @param name
 */
void display_Slinked_list(Slinked_list* list, DISPLAY display_func, char* name) {
   printf("\n =======%s=======\n", name);
   Node* current = list->head;
   while (current != NULL) {
      display_func(current->data);
      current = current->next;
   }
}
