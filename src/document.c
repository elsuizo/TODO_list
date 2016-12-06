/* -------------------------------------------------------------------------
@file document.c

@date 11/28/16 13:26:54
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Documents and his methods
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
#include "../inc/document.h"

/**
 * @brief evaluate if a Document is equal to another
 *
 * @param d1
 * @param d2
 *
 * @return
 */
int document_compare(Document* d1, Document* d2) {
   return strcmp(d1->name, d2->name);
}


/**
 * @brief
 *
 * @param document
 */
void document_display(Document* document) {
   printf("%s\t%s\t%d\n", document->name, document->path, document->size);
}


/**
 * @brief Initialization of Documents
 *
 * @param d
 * @param name
 * @param path
 * @param size
 */
void document_init(Document* d, const char* name, const char* path, int size) {
   /* set name */
   d->name = (char*)malloc(strlen(name) + 1);
   strcpy(d->name, name);
   /* set path */
   d->path = (char*)malloc(strlen(path) + 1);
   strcpy(d->path, path);
   /* set size */
   d->size = size;

}

/**
 * @brief
 *
 * @param document
 */
void document_destroy(Document* document) {
   free(document->name);
   free(document->path);
}
