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

#include <stdio.h>
#include "../inc/list.h"

/* TODO(elsuizo: 2016-11-27) ver porque no anda esta mierda */
void destroy(void *data){
  free(data);
}

void display_fucking_number(int* number) {
   printf("The number is:%d\n", *number);
}

int main()
{
    Slinked_list my_list;
    Node my_element;
    int data = 3;

    /* FIXME(elsuizo: 2016-11-27) ver cuando conviene pasar por referencia y cuando por valor */
    list_init(&my_list);

    list_insert_next(&my_list, &my_element, &data);
    //int a = list_data(ptr_my_element);
    display_Slinked_list(&my_list, (DISPLAY)display_fucking_number, "Number");
    return 0;
}
