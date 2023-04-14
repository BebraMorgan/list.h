#include "library.h"

int search_max_id(head_t *head) {
    node_t *list = NULL;
    int max = 0;
    list = head->first;
    for (list = head->first; list != NULL; list = list->next) {
        if (list->id > max) max = list->id;
    }
    return max;
}

head_t *head_init() {
    head_t *head = NULL;
    if ((head = (head_t*)malloc(sizeof(head_t))) != NULL) {
        head->length = 0;
        head->first = NULL;
        head->last = NULL;
    }
    return head;
}

node_t *list_append(head_t *head, void *data, void (*free)(void*)) {
    node_t *node = NULL;
    if ((node = (node_t*)malloc(sizeof(node_t))) != NULL) {
        node->data = data;
        node->next = NULL;
        if (head->length == 0) {
            head->first = node;
            head->last = node;
            head->length++;
            node->id = 1;
            node->prev = NULL;
        } else {
            node->prev = head->last;
            head->last->next = node;
            head->last = node;
            head->length++;
            node->id = search_max_id(head) + 1;
        }
    }
    return node;
}

node_t *list_get(head_t *head, size_t num) {
    node_t *node = NULL;
    size_t i;
    node = head->first;
    for (i = 0; node != NULL && i < num; i++) {
        node = node->next;
    }
    return node;
}

void node_delete(node_t *node) {
    if (node != NULL) {
        if (node->free != NULL)
            node->free(node->data);
        free(node);
    }
}

void list_delete(head_t *head){
    node_t *node = NULL, *next = NULL;
    if(head != NULL){
        for(node = head->first; node != NULL; node = next){
            next = node->next;
            node_delete(node);
        }
        free(head);
    }
}

node_t *list_insert(head_t *head, node_t *node, size_t position) {
    node_t *next = NULL;
    size_t i;
    if (head != NULL && node != NULL) {
        if (position >= 0) {
            for (i = 0, next = head->first; next != NULL && i != position; next = next->next)
                i++;
            if (next != NULL) {
                node->prev = next->prev;
                node->next = next;
                if (next->prev != NULL)
                    next->prev->next = node;
                else
                    head->first = node;
                next->prev = node;
            } else {
                node->prev = head->last;
                if (head->last != NULL)
                    head->last->next = node;
                else
                    head->first = node;
                head->last = node;
                node->next = NULL;
            }
        } else {
            for (i = -1, next = head->last; next != NULL && i != position; next = next->prev)
                i--;
            if (next != NULL) {
                node->prev = next->prev;
                node->next = next;
                if (next->prev != NULL)
                    next->prev->next = node;
                else
                    head->first = node;
                next->prev = node;
            } else {
                node->next = head->first;
                if (head->first != NULL)
                    head->first->prev = node;
                else
                    head->last = node;
                head->first = node;
                node->prev = NULL;
            }
        }
        head->length++;
    }
    return node;
}

node_t *list_pop_tail(head_t *head){
    node_t *node = NULL;
    if(head != NULL){
        node = head->last;
        if(node->prev != NULL){
            node->prev->next = node->next;
        }
        else{
            head->first = node->next;
        }
        head->last = node->prev;
        head->length--;
        node->next = NULL;
        node->prev = NULL;
    }
    return node;
}

node_t *list_pop_top(head_t *head){
    node_t *node = NULL;
    if(head != NULL){
        node = head->first;
        head->first = node->next;
        if (node->next != NULL)
            node->next->prev = node->prev;
        else
            head->last = node->prev;
        head->length--;
        node->prev = NULL;
        node->next = NULL;
    }
    return node;
}

void *list_exclude(head_t *head, node_t *node) {
    if (head != NULL && node != NULL) {
        if (node->prev != NULL)
            node->prev->next = node->next;
        else
            head->first = node->next;

        if (node->next != NULL)
            node->next->prev = node->prev;
        else
            head->last = node->prev;
        head->length--;
    }
    node->prev = NULL;
    node->next = NULL;
}

void swap(head_t *head, node_t **first, node_t **second) {
    node_t *first_prev = NULL, *second_prev = NULL, *temp = NULL, *prev = NULL;
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