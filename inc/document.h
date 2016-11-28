/* -------------------------------------------------------------------------
@file document.h

@date 11/28/16 13:28:33
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
#ifndef DOCUMENT_H
#define DOCUMENT_H

/*-------------------------------------------------------------------------
                              custom datatypes
  -------------------------------------------------------------------------*/
typedef struct _document {
   char* name;
   char* path;
   int   size;
} Document;
/*-------------------------------------------------------------------------
                              prototypes
  -------------------------------------------------------------------------*/
int compare_Documents(Document* d1, Document* d2);
void display_Documents(Document* document);
void deallocate_Documents(Document* Document);
void init_Document(Document d, const char* name, const char* path, int size);

#endif
