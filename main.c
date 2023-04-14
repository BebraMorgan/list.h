#include "library.h"
#include <stdio.h>
#include "stdlib.h"

typedef struct cars {
    char *name;
    char *company;
    int max_speed;
    int gears_count;
    float horsepower;
    float price;
    float *consumption;
    struct cars *next;
} cars_t;

#define SINGLE_LINKED_LIST_INFO_TYPE cars_t

#define DOUBLE_LINKED_LIST_INFO_TYPE cars_t

int main(){

    slhead_t *head;
    return 0;
}
