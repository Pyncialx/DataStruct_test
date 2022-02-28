#include "..\include\doubly.h"
#include <time.h>

item_t *int_item_new(const int *num)
{
    item_t *item = malloc(sizeof(item_t));
    if (!item)
    {
        return NULL;
    }
    item->num = num;
    return item;
}

doubly_node_t *doubly_list_append(doubly_node_t **head, doubly_node_t *item)
{
    doubly_node_t *tail = list_get_tail(head);
    if (!tail)
    {
        *head = item;
    }
    else
    {
        tail->next = item;
    }
    item->prev = tail;
    item->next = NULL;
    return item;
}

doubly_node_t *list_get_tail(doubly_node_t **head)
{
    doubly_node_t *current_node = *head;
    doubly_node_t *last_node = NULL;
    while (current_node)
    {
        last_node = current_node;
        current_node = current_node->next;
    }
    return last_node;
}

item_t *list_pop(item_t **head)
{
    item_t *current_head = *head;
    if (!current_head)
    {
        return NULL;
    }
    *head = (*head)->node.next;
    (*head)->node.prev = NULL;
    current_head->node.next = NULL;
    current_head->node.prev = NULL;

    return current_head;
}

item_t *doubly_list_remove(item_t **head, item_t *item)
{

    item_t *prev_node = item->node.prev;
    item_t *next_node = item->node.next;

    if (!item->node.prev)
    {
        item_t *returnedHead = list_pop(&head);
        return returnedHead;
    }

    if (item->node.next)
    {
        prev_node->node.next = item->node.next; // the next of the previous node to remove become the next node of the node to remove
        next_node->node.prev = item->node.prev; // the previous of the next node to remove become the previous node of the node to remove
    }
    else
    {
        prev_node->node.next = NULL;
    }
    // node to remove

    item->node.next = NULL; // removing the reference at the other node
    item->node.prev = NULL;

    return item;
}

int *list_insert_afther(doubly_node_t *item, doubly_node_t *item_to_insert) 
{
    if(!item)
    {
        return -1;
    }
    //need control if the item exist in a list
    if (item->next)
    {
        item_to_insert->next = item->next; //set the next of the item i have to insert
        (item->next)->prev = item_to_insert; //set the previous of the next item to the item i have to insert
    }
    else
    {
        item_to_insert->next = NULL; //if there is nothing afther the item i want to insert afther
    }
    item_to_insert->prev = item;  //set the previous
    item->next = item_to_insert;  //set the item_to_insert as the next of the previous item

    return 0;

}

int *list_insert_before(doubly_node_t **head,doubly_node_t *item, doubly_node_t *item_to_insert)
{     
    if(!head)
    {
        return -1;
    }  
                                                                                                                
    if(item->prev)
    {
        item_to_insert->prev = item->prev;
        (item->prev)->next = item_to_insert;
    }
    else
    {
        *head = item_to_insert;
        item_to_insert->prev = NULL;
    }
    item_to_insert->next= item;
    item->prev = item_to_insert;

    return 0;
}

int doubly_list_get_size(doubly_node_t **head)
{
    int counter=0;
    doubly_node_t *current_node = *head;
    while (current_node)
    {
        counter++;
        current_node = current_node->next;
    }
    //printf("size of the struct is %d\n", counter);
    return counter;
}
doubly_node_t *get_item_with_index(doubly_node_t **list, int index)
{
    int counter = doubly_list_get_size(list); 
    
    doubly_node_t *current = *list;
    if (counter < index)
    {
        //index out of list
        return NULL;
    }
    for (size_t i = 0; i < index; i++)
    {
        current = current->next;
    }
    
    return current;
}
int *list_Shuffle (doubly_node_t **head,int number_of_time_to_shuffle_item)
{
    
    int list_size = doubly_list_get_size(head);
    printf("list size: %d\n", list_size);

    doubly_node_t *item_to_insert = NULL;
    printf("entro in shuffle\n");
    /* 
    random int between 0 and value-1 -- Example int r = rand() % 20 [random is between 0 - 19]
    int r = rand() % value;
    */
   for (size_t i = 0; i < number_of_time_to_shuffle_item; i++)    //puo' prendere l'ultimo della lista
   {
       /* code */
       item_to_insert =list_pop(head);   //rimuovo quindi il numero degli item in lista cambia
       list_size = doubly_list_get_size(head);
       int index_where_insert_item = rand() % (list_size);
       //printf("sono nel for all'iterazione DOPO RAND: %d\n", index_where_insert_item);
       //printf("sono nel for all'iterazione DOPO POP: %d\n", i);

       doubly_node_t *item_pos_afther = get_item_with_index(head,index_where_insert_item); //in questo metodo mi riconto la lista, puo' capitare che cerco di inserire l'item
                                                                                                    //in un punto fuori dalla lista.
       //printf("sono nel for all'iterazione PRENDO ITEM CON INDEX: %d\n", i);


       list_insert_afther(item_pos_afther,item_to_insert);
   }
   
    /*random uno della lista -> remove
    doubly_list_node node_to_swap_one = remove(blabla);
    list append(problem of ripetute cicle) or list insert (found a new random where to insert item)


    //fai un ciclo per un numero di volte richiesto quindi nella signature
    
    */
   return 0;
}
item_t *destroy_item(item_t *item_to_destroy)
{
    if (item_to_destroy)
    {
        free(item_to_destroy);
        item_to_destroy = NULL;
    }
    return item_to_destroy;
}
