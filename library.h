#ifndef LISTS_LIBRARY_H
#define LISTS_LIBRARY_H

#include "main.c"


#ifdef SINGLE_LINKED_LIST_INFO_TYPE

typedef struct SingleLinkedListNode {
    SINGLE_LINKED_LIST_INFO_TYPE *info; /* Your structure */
    int id; /* Element id */
    struct SingleLinkedListNode *next; /* Pointer on the next element */
} slist_t; /* Type of single-linked list element */

typedef struct SingleLinkedListHead {
    int length; /* Length of list */
    slist_t *first; /* Pointer on the first element */
    slist_t *last; /* Pointer on the last element */
} slhead_t; /* Type of single-linked list head */

/* Single-linked list functions */

slhead_t *sl_head_init(); /* head initiation */

int search_max_id(void *head, links); /* max id search */

void list_clear(void *head, int links); /* clear list */

slist_t *slist_append(slhead_t *head, SINGLE_LINKED_LIST_INFO_TYPE *info); /* adding element to the end */

slist_t *slist_get(slhead_t *head, int num); /* getting pointer on the element standing in a given place  */

void sl_element_delete_from_tail(slhead_t *head, int num);

void swap(slhead_t *head, slist_t **first, slist_t **second);

#endif


#ifdef DOUBLE_LINKED_LIST_INFO_TYPE

        typedef struct DoubleLInkedListNode {
            SINGLE_LINKED_LIST_INFO_TYPE *info;
            int id;
            struct DoubleLInkedListNode *prev;
            struct DoubleLInkedListNode *next;
        } dlist_t;

        typedef struct DoubleLInkedListHead {
            int length;
            dlist_t *first;
            dlist_t *last;
        } dlhead_t;


        dlhead_t *dl_head_init();

                dlist_t *dlist_append(dlhead_t *head, DOUBLE_LINKED_LIST_INFO_TYPE*info);

dlist_t *dlist_get(dlhead_t *head, int num);

#endif


#endif
