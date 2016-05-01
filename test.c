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

#include<stdio.h>
#include"list.h"


void destroy(void *data)
{
  free(data);
}

int main()
{
    List my_list;       
    ListElement my_element;
    ListElement *ptr_my_element = &my_element;
    List *ptr_my_list = &my_list;
    int data = 3;
    int *ptr_data = &data;

    list_init(ptr_my_list, destroy);

    list_insert_next(ptr_my_list, ptr_my_element, ptr_data);
    //int a = list_data(ptr_my_element);
    printf("Mi lista tiene los siguientes datos: %d\n", (ptr_my_element->data));
    return 0;
}
