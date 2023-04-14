# Start
***
This library is designed to collect all the basic functions for processing lists.

the following is a description of the features that are already present in the library.

***
To use your structure you need to specify the following in your file:

<code>#define SINGLE_LINKED_LIST_INFO_TYPE <Your_structure_name> // for the single-linked list</code>

<code>#define DOUBLE_LINKED_LIST_INFO_TYPE <Your_structure_name> // for the double-linked list</code>
***
## Functions for a single-linked list
***
### slhead_t *sl_head_init();
Description: initialisation of sl head.
### slist_t *slist_append(slhead_t *head, SINGLE_LINKED_LIST_INFO_TYPE *info); 
Description: Adding element to the end of list.
Arguments:
* slhead_t *head - sl head.
* SINGLE_LINKED_LIST_INFO_TYPE *info - your structure.
***
### slist_t *slist_get(slhead_t *head, int num);
Description: getting pointer on the element standing in a given place.
Arguments:
* slhead_t *head - sl head.
* int num - number of element.
***
### void sl_element_delete_from_tail(slhead_t *head, int num);
Description: Deleting element of list from tail.
Arguments:
* slhead_t *head - sl head.
* int num - number of element.
***
### void swap(slhead_t *head, slist_t **first, slist_t **second);
Description: Swapping two elements in list.
Arguments:
* slhead_t *head - sl head.
* slist_t **first - first element to swap.
* slist_t **second - second element to swap.
***
## Functions for a double-linked list
### dlhead_t *dl_head_init();
Description: initialisation of sl head.
***
### dlist_t *dlist_append(dlhead_t *head, DOUBLE_LINKED_LIST_INFO_TYPE *info);
Description: Adding element to the end of list.
Arguments:
* dlhead_t *head - list head.
* DOUBLE_LINKED_LIST_INFO_TYPE *info - your structure
***
### dlist_t *dlist_get(dlhead_t *head, int num);
Description: getting pointer on the element standing in a given place.
Arguments:
* dlhead_t *head - list head.
* int num - number of element.
***

## Functions for both lists
### int search_max_id(void *head, links); 
Description: max id search.
Arguments:
* void *head - list head.
* int links - number of links.
***
### void list_clear(void *head, int links); 
Description: clear list.
Arguments:
* void *head - list head.
* int links - number of links.
***
