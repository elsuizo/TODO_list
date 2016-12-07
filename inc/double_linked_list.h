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

#endif

