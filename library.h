#ifndef LISTS_LIBRARY_H
#define LISTS_LIBRARY_H


typedef struct node_s {
    void *data; /* Your structure */
    int id; /* Element id */
    struct node_s *prev; /* Pointer on the previous element */
    struct node_s *next; /* Pointer on the next element */
    void (*free)(void *);
} node_t; /* Type of list element */

typedef struct head_s {
    size_t length; /* Length of list */
    node_t *first; /* Pointer on the first element */
    node_t *last; /* Pointer on the last element */
} head_t; /* Type of list head */


int search_max_id(head_t *head);

head_t *head_init();

node_t *list_append(head_t *head, void *data, void (*free)(void*));

node_t *list_get(head_t *head, size_t num);

void node_delete(node_t *node);

void list_delete(head_t *head);

node_t *list_insert(head_t *head, node_t *node, size_t position);

node_t *list_pop_tail(head_t *head);

node_t *list_pop_top(head_t *head);

void *list_exclude(head_t *head, node_t *node);

void swap(head_t *head, node_t **first, node_t **second);


#endif 
