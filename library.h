#include "library.h"

#include <stdlib.h>
#include <stdio.h>

#ifdef SINGLE_LINKED_LIST_INFO_TYPE
#ifdef DOUBLE_LINKED_LIST_INFO_TYPE

int search_max_id(void *head, links) {
    dlhead_t *dlhead = NULL;
    slhead_t *slhead = NULL;
    dlist_t *dlist = NULL;
    slist_t *slist = NULL;
    int max = 0;
    if (links == 1) {
        slhead = (slhead_t *) head;
        slist = slhead->first;
        for (slist = slhead->first; slist != NULL; slist = slist->next) {
            if (slist->id > max) max = slist->id;
        }
    } else if (links == 2) {
        dlhead = (dlhead_t *) head;
        dlist = dlhead->first;
        for (dlist = dlhead->first; dlist != NULL; dlist = dlist->next) {
            if (dlist->id > max) max = dlist->id;
        }
    }
    return max;
}

void list_clear(void *head, int links) {
    dlhead_t *dlhead = NULL;
    slhead_t *slhead = NULL;
    dlist_t *dnode1 = NULL;
    dlist_t *dnode2 = NULL;
    slist_t *snode1 = NULL;
    slist_t *snode2 = NULL;
    if (links == 1) {
        slhead = (slhead_t *) head;
        snode1 = slhead->first;
        while (snode1 != NULL) {
            snode2 = snode1;
            snode1 = snode1->next;
            free(snode2);
        }
    } else if (links == 2) {
        dlhead = (dlhead_t *) head;
        dnode1 = dlhead->first;
        while (dnode1 != NULL) {
            dnode2 = dnode1;
            dnode1 = dnode1->next;
            free(dnode2);
        }
    }
}

#endif
#endif

#ifdef SINGLE_LINKED_LIST_INFO_TYPE


slhead_t *sl_head_init() {
    slhead_t *head = NULL;
    if ((head = (slhead_t *) malloc(sizeof(slhead_t))) != NULL) {
        head->length = 0;
        head->first = NULL;
        head->last = NULL;
    }
    return head;
}

slist_t *slist_append(slhead_t *head, SINGLE_LINKED_LIST_INFO_TYPE *info) {
    slist_t *node = NULL;
    if ((node = (slist_t *) malloc(sizeof(slist_t))) != NULL) {
        node->info = info;
        node->next = NULL;
        if (head->length == 0) {
            head->first = node;
            head->last = node;
            head->length++;
            node->id = 1;
        } else {
            head->last->next = node;
            head->last = node;
            head->length++;
            node->id = search_max_id(head, 1) + 1;
        }
    }
    return node;
}

slist_t *slist_get(slhead_t *head, int num) {
    slist_t *node = NULL;
    int i;
    node = head->first;
    for (i = 0; node != NULL && i < num; i++) {
        node = node->next;
    }
    return node;
}

void sl_element_delete_from_tail(slhead_t *head, int num) {
    int i;
    slist_t *node1, *CAR_2;
    if (head->length != 0) {
        if (head->length == 1) {
            free(head->first);
            head->length = 0;
            head->first = NULL;
            head->last = NULL;
            puts("Deleted last element");
        } else {
            node1 = head->first;
            if (head->length > num) {
                for (i = 0; i < (head->length - num - 1); i++)
                    node1 = node1->next;
                CAR_2 = node1->next->next;
                free(node1->next);
                node1->next = CAR_2;

            } else {
                puts("Not enough elements to delete! deleted first.");
                node1 = head->first;
                head->first = node1->next;
                free(node1);
            }
            head->length--;
        }
    } else puts("There are no elements to delete!");
}

void swap(slhead_t *head, slist_t **first, slist_t **second) {
    slist_t *first_prev = NULL, *second_prev = NULL, *temp = NULL, *prev = NULL;
    temp = head->first;
    while (temp) {
        if (temp == *first) {
            first_prev = prev;
        }
        if (temp == *second) {
            second_prev = prev;
        }
        prev = temp;
        temp = temp->next;
    }

    if ((*first)->next == *second) {
        temp = (*second)->next;
        (*second)->next = *first;
        (*first)->next = temp;

        if (first_prev) {
            first_prev->next = *second;
        } else {
            head->first = *second;
        }
    } else if ((*second)->next == *first) {
        temp = (*first)->next;
        (*first)->next = (*second);
        (*second)->next = temp;
        if (second_prev) {
            second_prev->next = *first;
        } else {
            head->first = *first;
        }
    } else {
        temp = (*first)->next;
        (*first)->next = (*second)->next;
        (*second)->next = temp;
        if (first_prev) {
            first_prev->next = *second;
        } else {
            head->first = *second;
        }

        if (second_prev) {
            second_prev->next = *first;
        } else {
            head->first = *first;
        }
    }

    temp = *first;
    *first = *second;
    *second = temp;
}


#endif

#ifdef DOUBLE_LINKED_LIST_INFO_TYPE

dlhead_t *dl_head_init() {
    dlhead_t *head = NULL;
    if ((head = (dlhead_t *) malloc(sizeof(dlhead_t))) != NULL) {
        head->length = 0;
        head->first = NULL;
        head->last = NULL;
    }
    return head;
}

dlist_t *dlist_append(dlhead_t *head, DOUBLE_LINKED_LIST_INFO_TYPE *info) {
    dlist_t *node = NULL;
    if ((node = (dlist_t *) malloc(sizeof(dlist_t))) != NULL) {
        node->info = info;
        node->next = NULL;
        if (head->length == 0) {
            node->prev = NULL;
            head->first = node;
            head->last = node;
            head->length++;
            node->id = 1;
        } else {
            head->last->next = node;
            node->prev = head->last;
            head->last = node;
            head->length++;
            node->id = search_max_id(head, 2) + 1;
        }
    }
    return node;
}

dlist_t *dlist_get(dlhead_t *head, int num) {
    dlist_t *node = NULL;
    int i;
    node = head->first;
    for (i = 0; node != NULL && i < num; i++) {
        node = node->next;
    }
    return node;
}

#endif