# Введение

Эта библиотека предоставляет реализацию двусвязного списка с различными функциями для манипуляций с элементами списка.
## Структуры данных

Библиотека использует две основные структуры данных: node_t и head_t.

    node_t: Представляет собой элемент списка. Содержит:

        Указатель на данные (void *data)

        Идентификатор элемента (int id)

        Указатели на предыдущий и следующий элементы (struct node_s *prev и struct node_s *next)

        Функцию для освобождения памяти (void (*free)(void *))

    head_t: Представляет собой голову списка. Содержит:

        Информацию о длине списка (size_t length)

        Указатели на первый и последний элементы (node_t *first и node_t *last)

# Функции
## search_max_id

Описание: Возвращает максимальный идентификатор среди всех элементов списка.

Прототип: int search_max_id(head_t *head);

## head_init

Описание: Инициализирует новую голову списка.

Прототип: head_t *head_init();

## list_append

Описание: Добавляет новый элемент в конец списка.

Прототип: node_t *list_append(head_t *head, void *data, void (*free)(void*));

## list_get

Описание: Возвращает указатель на элемент списка по его номеру.

Прототип: node_t *list_get(head_t *head, size_t num);

## node_delete

Описание: Освобождает память, выделенную для элемента списка.

Прототип: void node_delete(node_t *node);

## list_delete

Описание: Освобождает память, выделенную для всего списка.

Прототип: void list_delete(head_t *head);

## list_insert

Описание: Вставляет новый элемент в список на указанную позицию.

Прототип: node_t *list_insert(head_t *head, node_t *node, size_t position);

## list_pop_tail

Описание: Удаляет последний элемент из списка и возвращает его.

Прототип: node_t *list_pop_tail(head_t *head);

## list_pop_top

Описание: Удаляет первый элемент из списка и возвращает его.

Прототип: node_t *list_pop_top(head_t *head);

## list_exclude

Описание: Удаляет указанный элемент из списка.

Прототип: void *list_exclude(head_t *head, node_t *node);

## swap

Описание: Меняет местами два элемента в списке.

Прототип: void swap(head_t *head, node_t **first, node_t **second);

# Пример использования

```
#include <stdio.h>
#include <stdlib.h>
#include "library.h"


void free_data(void *data) {
    free(data);
}

int main() {

    head_t *head = head_init();
    int *data1 = malloc(sizeof(int));
    *data1 = 10;

    int *data2 = malloc(sizeof(int));
    *data2 = 20;

    list_append(head, data1, free_data);
    list_append(head, data2, free_data);

    node_t *node = head->first;

    while (node) {
        printf("ID: %d\n", node->id);
        node = node->next;
    }

    list_delete(head);
    return 0;
}
```
