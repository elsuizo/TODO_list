/* -------------------------------------------------------------------------
@file listlib.c

@date 11/28/16 18:03:09
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief

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
#include "../inc/single_linked_list.h"

/**
 * @brief Initialization for a single linked list
 *
 * @param list
 */
void single_linked_list_init(SingleLinkedList* list) {
   list->head     =  NULL;
   list->tail     =  NULL;
   list->current  =  NULL;
   list->size     =  0;
}

/**
 * @brief Created a Node with the associated data in the head of single linked list
 *
 * @param list
 * @param data
 *
 * @return Status operation constants
 */
int single_linked_list_add_head(SingleLinkedList* list, void* data) {
   Node* node;
   /* check for memory */
   if ((node = (Node*)malloc(sizeof(Node))) == NULL) return STATUS_ERR;
   node->data = data;
   /* the list is empty */
   if (list->head == NULL) {
      list->tail = node;
      node->next = NULL;
   } else {
      node->next = list->head;
   }
   list->head = node;
   list->size++;

   return STATUS_OK;
}

/**
 * @brief Created a Node with the associated data in the tail of a single linked list
 *
 * @param list
 * @param data
 *
 * @return Status operation constants code
 */
int single_linked_list_add_tail(SingleLinkedList* list, void* data) {
   Node* node;
   if ((node = (Node*)malloc(sizeof(Node))) == NULL) return STATUS_ERR;
   node->data = data;
   node->next = NULL;
   if (list->head == NULL) {
      list->head = node;
   } else {
      list->tail->next = node;
   }
   list->tail = node;
   list->size++;

   return STATUS_OK;
}

/**
 * @brief Delete a Node from single linked list
 *
 * @param list
 * @param node
 *
 * @return Status operation constants code
 */
int single_linked_list_delete_Node(SingleLinkedList* list, Node* node) {
   /* check is empty */
   if(LIST_SIZE(list) == 0) {
      printf("ERROR the list is empty\n");
      return STATUS_ERR;
   }

   if (node == list->head) {
      /* the list become empty */
      if (list->head->next == NULL) {
         list->head = list->tail = NULL;
      } else {
         list->head = list->head->next;
      }
   } else {
      Node* tmp = list->head;
      while (tmp != NULL && tmp->next != node) {
         tmp = tmp->next;
      }
      if (tmp != NULL) {
         tmp->next = node->next;
      }
   }
   free(node);
   list->size--;

   return STATUS_OK;
}

/**
 * @brief Extract Node from single linked list
 *
 * @param list
 * @param compare_func
 * @param data
 *
 * @return pointer to Node or NULL(failled operation)
 */
Node* single_linked_list_get_Node(SingleLinkedList* list, COMPARE compare_func, void* data) {
   Node* node = list->head;
   while (node != NULL) {
      if (compare_func(node->data, data) == 0) {
         return node;
      }
      node = node->next;
   }
   return NULL;
}

/**
 * @brief Display elements fo single linked list
 *
 * @param list
 * @param display_func
 * @param name
 */
void single_linked_list_display(SingleLinkedList* list, DISPLAY display_func, char* name) {
   printf("=======%s=======\n", name);
   Node* current = list->head;
   while (current != NULL) {
      display_func(current->data);
      current = current->next;
   }
}

Node* single_linked_list_delete_Node_linus(Node** head, void* data) {
   Node** double_ptr = head;
   while (*double_ptr && (**double_ptr).data != data) {
      double_ptr = &(*double_ptr)->next;
     }
   if (*double_ptr == NULL) {
      return NULL;
   }
   Node* delete_Node = *double_ptr;
   *double_ptr = delete_Node->next;
   delete_Node->next = NULL;

   return delete_Node;
}
