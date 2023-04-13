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

int sl_search_max_id(slhead_t *head); /* max id search */

slist_t *slist_append(slhead_t *head, SINGLE_LINKED_LIST_INFO_TYPE *info); /* adding element to the end */

slist_t *slist_get(slhead_t *head, int num); /* getting pointer on the element standing in a given place  */

#endif



#ifdef DOUBLE_LINKED_LIST_INFO_TYPE

typedef struct DoubleLInkedListNode {
    SINGLE_LINKED_LIST_INFO_TYPE* info;
    int id;
    struct DoubleLInkedListNode *prev;
    struct DoubleLInkedListNode *next;
}dlist_t;

typedef struct DoubleLInkedListHead {
    int length;
    dlist_t *first;
    dlist_t *last;
}dlhead_t;


#endif



#endif
