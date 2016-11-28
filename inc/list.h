/* -------------------------------------------------------------------------
@file list.h
  ___| |___ _   _(_)_______
 / _ \ / __| | | | |_  / _ \
|  __/ \__ \ |_| | |/ / (_) |
 \___|_|___/\__,_|_/___\___/
@date 12/03/15 10:32:32
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Linked list declaration
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
#ifndef _LIST_H
#define _LIST_H

#include <stdlib.h>

/*------------------------------------------------------------------------------
                define a structure for a linked list elements
------------------------------------------------------------------------------*/
typedef struct _node{
   void*    data;
   struct  _node*   next;
}Node;

/*------------------------------------------------------------------------------
                    define a structure for a linked list
------------------------------------------------------------------------------*/
/* function pointers */
typedef int(*MATCH)(const void*, const void*);
typedef void(*DESTROY)(void*);
typedef void(*DISPLAY)(void*);

typedef struct _slinked_list {
   int      size;
   Node*     head;
   Node*     tail;
   Node*    current;

}Slinked_list;

/*------------------------------------------------------------------------------
                            public interface
------------------------------------------------------------------------------*/
// initialize the linked list, size=0, the head and tail poiter to NUL
// this opertion must realized before the list can be used
void list_init(Slinked_list* list);

// destroy a linked list(removing all elements of the list)
void list_destroy(Slinked_list* list, DESTROY destroy_func);

// insert element just after specified element
int list_insert_next(Slinked_list* list, Node* node, const void* data);

//
int list_remove_next(Slinked_list* list, Node* node, void** data);

void display_Slinked_list(Slinked_list* list, DISPLAY display_func, char* name);

/*------------------------------------------------------------------------------
                            Macros
------------------------------------------------------------------------------*/
#define list_size(Slinked_list) ((list) -> size)
#define list_head(Slinked_list) ((list) -> head)
#define list_tail(Slinked_list) ((list) -> tail)
#define list_is_head(Slinked_list, Node) ((node) -> next == NULL ? 1 : 0)
#define list_data(Node) ((node) -> data)
#define list_next(Node) ((node) -> next)

#endif
