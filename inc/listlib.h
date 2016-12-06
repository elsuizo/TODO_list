/* -------------------------------------------------------------------------
@file list_lib.h

@date 11/28/16 18:11:13
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
#ifndef LISTLIB_H
#define LISTLIB_H

#include <inttypes.h> /* header for the uintx_t */
#include <stdlib.h>
#include <stdio.h>
/*-------------------------------------------------------------------------
                           custom data types
-------------------------------------------------------------------------*/
/**
 * @brief Node data type for linked lists
 */
typedef struct _node {
   void* data;
   struct _node* next;
}Node;

typedef struct _singleLinkedList {
   Node* head;
   Node* tail;
   Node* current;
   uint8_t size;
}SingleLinkedList;

typedef void(*DISPLAY)(void*); /* return void take void */
typedef int(*COMPARE)(void*, void*); /* return int, take two void */

/*-------------------------------------------------------------------------
                              prototypes
-------------------------------------------------------------------------*/
void   listlib_init_Slinked_list(SingleLinkedList*     list);
int    listlib_add_head(SingleLinkedList*              list,   void*    data);
int    listlib_add_tail(SingleLinkedList*              list,   void*    data);
int    listlib_delete_Node(SingleLinkedList*           list,   Node*    node);
Node*  listlib_delete_Node_linus(Node**                head,   void*    data);
Node*  listlib_get_Node(SingleLinkedList*              list,   COMPARE  compare_func,  void*  data);
void   listlib_display_Slinked_list(SingleLinkedList*  list,   DISPLAY  display_func,  char*  name);

/*-------------------------------------------------------------------------
                              macros
-------------------------------------------------------------------------*/
#define LIST_SIZE(list) ((list) -> size)
#define LIST_HEAD(list) ((list) -> head)
#define LIST_TAIL(list) ((list) -> tail)
#define LIST_IS_Head(SingleLinkedList, Node) ((node) -> next == NULL ? 1 : 0)
#define LIST_DATA(node) ((node) -> data)
#define list_next(node) ((node) -> next)

/*-------------------------------------------------------------------------
                              defines
-------------------------------------------------------------------------*/
#define STATUS_OK   0;
#define STATUS_ERR -1;

/*-------------------------------------------------------------------------
                              EOF
-------------------------------------------------------------------------*/
#endif
