/* -------------------------------------------------------------------------
@file test.c

@date 04/30/16 18:57:34
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

#include "../inc/listlib.h"
#include "../inc/document.h"

int main()
{
   SingleLinkedList document_list;

   listlib_init_SingleLinkedList(&document_list);

   Document* document1 = (Document*)malloc(sizeof(Document));

   init_Document(document1, "baboon.jpg", "/home/elsuizo/Images", 73);

   listlib_add_head(&document_list, document1);

   listlib_display_SingleLinkedList(&document_list, (DISPLAY)display_Documents, "Documents");

   Node* r1 = listlib_delete_Node_linus(&(document_list.head), document1);

   printf("Node data delete:\n");

   display_Documents(r1->data);

   printf("After Delete\n");

   listlib_display_SingleLinkedList(&document_list, (DISPLAY)display_Documents, "Documents");

   deallocate_Documents(document1);

   return 0;
}
