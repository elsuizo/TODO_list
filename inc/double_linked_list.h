/* -------------------------------------------------------------------------
@file double_linked_list.h

@date 12/07/16 02:11:28
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
#ifndef __DOUBLE_LINKED_LIST_H__
#define __DOUBLE_LINKED_LIST_H__
/*-------------------------------------------------------------------------
                              includes
-------------------------------------------------------------------------*/
#include <inttypes.h> /* header for the uintx_t */
#include <stdlib.h>
#include <stdio.h>
/*-------------------------------------------------------------------------
                              custom data types
-------------------------------------------------------------------------*/
/**
 * @brief Node double linked
 */
typedef struct _nodeDouble {
   void* data;
   struct _nodeDouble* next;
   struct _nodeDouble* previous;
}NodeDouble;

/**
 * @brief Double linked list data type
 */
typedef struct _doubleLinkedList {
   NodeDouble* head;
   NodeDouble* tail;
   NodeDouble* current;
   uint8_t     size;
}DoubleLinkedList;

/**
 * @brief function pointer to display function
 *
 * @param
 */
typedef void(*DISPLAY)(void*); /* return void take void */
/**
 * @brief function pointer to comparison function
 *
 * @param
 *
 * @return -1, 0
 */
typedef int(*COMPARE)(void*, void*); /* return int, take two void */
/*-------------------------------------------------------------------------
                              prototypes
-------------------------------------------------------------------------*/
void double_linked_list_init(DoubleLinkedList* dlist);
int double_linked_list_add_head(DoubleLinkedList* dlist, void* data);
int double_linked_list_add_tail(DoubleLinkedList* dlist, void* data);
int double_linked_list_delete_NodeDouble(DoubleLinkedList* dlist, NodeDouble* dnode);
NodeDouble* double_linked_list_get_NodeDouble(DoubleLinkedList* dlist, COMPARE compare_func, void* data);
int double_linked_list_insert_next(DoubleLinkedList* dlist, NodeDouble* dnode, const void* data);
int double_linked_list_insert_previous(DoubleLinkedList* dlist, NodeDouble* dnode, const void* data);
/*-------------------------------------------------------------------------
                              macros
-------------------------------------------------------------------------*/
#define DOUBLE_LINKED_LIST_SIZE(dlist) ((dlist)->size)
#define DOUBLE_LINKED_LIST_HEAD(dlist) ((dlist)->head)
#define DOUBLE_LINKED_LIST_TAIL(dlist) ((dlist)->tail)
#define DOUBLE_LINKED_LIST_IS_TAIL(dnode) ((dnode)->prev == NULL ? 1 : 0)
#define DOUBLE_LINKED_LIST_IS_HEAD(dnode) ((dnode)->next == NULL ? 1 : 0)
#define DOUBLE_LINKED_LIST_GET_DATA(dnode) ((dnode)->data)
#define DOUBLE_LINKED_LIST_GET_NEXT(dnode) ((dnode)->next)
#define DOUBLE_LINKED_LIST_GET_PREVIOUS(dnode) ((dnode)->previous)

/*-------------------------------------------------------------------------
                              defines
-------------------------------------------------------------------------*/
#define STATUS_OK   0;
#define STATUS_ERR -1;

#endif

