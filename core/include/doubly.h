#pragma once
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct doubly_list_node
{
    struct doubly_list_node *prev;
    struct doubly_list_node *next;
} doubly_node_t;

typedef struct int_item
{
    struct doubly_list_node node;
    const int *num;
} item_t;

item_t *int_item_new(const int *num);
doubly_node_t *doubly_list_append(doubly_node_t **head, doubly_node_t *item);
doubly_node_t *list_get_tail(doubly_node_t **head);
doubly_node_t *list_pop(doubly_node_t **head);
doubly_node_t *doubly_list_remove(doubly_node_t **head, doubly_node_t *item);
int *list_insert_afther(doubly_node_t *item, doubly_node_t *item_to_insert);
int *list_insert_before(doubly_node_t **head,doubly_node_t *item, doubly_node_t *item_to_insert);
int doubly_list_get_size (doubly_node_t **head);
doubly_node_t *get_item_with_index(doubly_node_t **list, int index);
int *list_Shuffle (struct doubly_list_node **head,int number_of_time_to_shuffle_item);
item_t *destroy_item(item_t *item_to_destroy);



#define doubleptr_d_list(obj) (doubly_node_t **)obj
#define singleptr_d_list(obj) (doubly_node_t *)obj 
#define list_append_cast(list,item_to_append) doubly_list_append(doubleptr_d_list(list),singleptr_d_list(item_to_append))