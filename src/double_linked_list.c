/* -------------------------------------------------------------------------
@file double_linked_list.c

@date 12/07/16 00:54:42
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
#include "../inc/double_linked_list.h"

/**
 * @brief
 *
 * @param dlist
 */
void double_linked_list_init(DoubleLinkedList* dlist) {
   dlist->head     =  NULL;
   dlist->tail     =  NULL;
   dlist->current  =  NULL;
   dlist->size     =  0;
}

/**
 * @brief
 *
 * @param dlist
 * @param data
 *
 * @return
 */
int double_linked_list_add_head(DoubleLinkedList* dlist, void* data) {
   NodeDouble* dnode;
   /* check for memory */
   if ((dnode = (NodeDouble*)malloc(sizeof(NodeDouble))) == NULL) {
      return STATUS_ERR;
   }
   dnode->data = data;
   /* the list is empty */
   if (dlist->head == NULL && DOUBLE_LINKED_LIST_SIZE(dlist) == 0) {
      dlist->tail = dnode;
      dnode->next = NULL;
      dnode->previous = NULL;
   } else {
      dnode->next = dlist->head;
      dnode->previous = NULL;
   }
   dlist->head = dnode;
   dlist->size++;
   return STATUS_OK;
}

/**
 * @brief
 *
 * @param dlist
 * @param dnode
 * @param data
 *
 * @return
 */
int double_linked_list_insert_next(DoubleLinkedList* dlist, NodeDouble* dnode, const void* data) {

   NodeDouble* new_dnode;
   /* check for memory */
   if (dnode == NULL && DOUBLE_LINKED_LIST_SIZE(dlist) != 0) {
      return STATUS_ERR;
   }
   /* allocate memory for the new double node */
   if ((new_dnode = (NodeDouble*)malloc(sizeof(NodeDouble))) == NULL) {
      return STATUS_ERR;
   }
   /* insert the new element in the double linked list */
   new_dnode->data = (void*)data;
   if (DOUBLE_LINKED_LIST_SIZE(dlist) == 0) {
      /* handle insertion when the list is empty */
      dlist->head = new_dnode;
      dlist->head->previous = NULL;
      dlist->head->next = NULL;
      dlist->tail = new_dnode;
   } else {
      /* handle insertion when the list is not empty */
      new_dnode->next = dnode->next;
      new_dnode->previous = dnode;
      if (dnode->next == NULL) {
         dlist->tail = new_dnode;
      } else {
         dnode->next->previous = new_dnode;
      }

      dnode->next = new_dnode;
   }

   /* adjust the size of the list to account for the inserted element */
   dlist->size++;

   return STATUS_OK;

}

/**
 * @brief
 *
 * @param dlist
 * @param dnode
 * @param data
 *
 * @return
 */
int double_linked_list_insert_previous(DoubleLinkedList* dlist, NodeDouble* dnode, const void* data) {

   NodeDouble* new_dnode;
   /* do not allow a NULL element unless the list is empty */
   if (dnode == NULL && DOUBLE_LINKED_LIST_SIZE(dlist) != 0) {
      return STATUS_ERR;
   }
   /* allocate storage to be managed by the abstract datatype */
   if ((new_dnode = (NodeDouble*)malloc(sizeof(NodeDouble))) == NULL) {
      return STATUS_ERR;
   }
   new_dnode->data = (void*)data;
   if (DOUBLE_LINKED_LIST_SIZE(dlist) == 0) {
      /* handle insertion when the list is empty */
      dlist->head = new_dnode;
      dlist->head->previous = NULL;
      dlist->head->next = NULL;
      dlist->tail = new_dnode;
   } else {
      /* handle insertion when the list is not empty */
      new_dnode->next = dnode;
      new_dnode->previous = dnode->previous;
      if (dnode->previous == NULL) {
         dlist->head = new_dnode;
      } else {
         dnode->previous->next = new_dnode;
      }

      dnode->previous = new_dnode;
   }
   /* adjust the size of the list to account for the new element */
   dlist->size++;

   return STATUS_OK;

}
