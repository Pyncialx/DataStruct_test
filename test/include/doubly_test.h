#include "clove.h"
#include "..\..\core\include\doubly.h"
#include <stdio.h>
#include <time.h>

#define srand() srand(1)

CLOVE_TEST(TEST)
{
    CLOVE_INT_EQ(1,1);
}

CLOVE_TEST(DOUBLY_ITEM_NOT_NULL)
{
    int num3= 3;
    item_t *item =  int_item_new(&num3);

    CLOVE_NOT_NULL(item);
    destroy_item(item);
}

CLOVE_TEST(DOUBLY_APPEND_HEAD_NOTNULL)
{
    item_t *list= NULL;
    int num1= 1;
    item_t *item = int_item_new(&num1);
    list_append_cast(&list,item);


    CLOVE_NOT_NULL(list);
    destroy_item(item);
}

CLOVE_TEST(DOUBLY_APPEND_CHECK_ITEM_ADDED_CORRECTLY)
{
    item_t *list= NULL;
    int num5= 1;
    item_t *item = int_item_new(&num5);
    list_append_cast(&list,item);

    CLOVE_PTR_EQ(list, item);
    CLOVE_INT_EQ(list->num, item->num);

    destroy_item(item);
}

CLOVE_TEST(DOUBLY_CHECKTAIL)
{
    item_t *list= NULL;
    int num1= 1;
    int num2= 2;
    int num3= 3;

    item_t *item1 = int_item_new(&num1);
    item_t *item2 = int_item_new(&num2);
    item_t *item3 = int_item_new(&num3);

    list_append_cast(&list,item1);
    list_append_cast(&list,item2);
    list_append_cast(&list,item3);

    item_t *tail = list_get_tail((doubly_node_t**)&list);
    
    CLOVE_PTR_EQ(tail, item3);
    CLOVE_INT_EQ(tail->num, item3->num);

    destroy_item(item1);
    destroy_item(item2);
    destroy_item(item3);
}

CLOVE_TEST(DOUBLY_CHECKPOP_EMPTYLIST)
{
    item_t *list= NULL;
    
    item_t *pop = list_pop((doubly_node_t**)&list);
    
    CLOVE_NULL(pop);
}

CLOVE_TEST(DOUBLY_CHECKPOP)
{
    item_t *list= NULL;
    int num1= 1;
    int num2= 2;
    int num3= 3;
    item_t *item1 = int_item_new(&num1);
    item_t *item2 = int_item_new(&num2);
    item_t *item3 = int_item_new(&num3);

    list_append_cast(&list,item1);
    list_append_cast(&list,item2);
    list_append_cast(&list,item3);

    item_t *pop = list_pop((doubly_node_t**)&list);
    
    CLOVE_PTR_EQ(pop, item1);
    CLOVE_INT_EQ(pop->num, item1->num);

    destroy_item(item1);
    destroy_item(item2);
    destroy_item(item3);
}

CLOVE_TEST(DOUBLY_CHECKREMOVE_SPECIFICITEM)
{
    item_t *list= NULL;
    int num1= 1;
    int num2= 2;
    int num3= 3;
    item_t *item1 = int_item_new(&num1);
    item_t *item2 = int_item_new(&num2);
    item_t *item3 = int_item_new(&num3);

    list_append_cast(&list,item1);
    list_append_cast(&list,item2);
    list_append_cast(&list,item3);

    item_t *removedItem = doubly_list_remove((doubly_node_t**)&list,(doubly_node_t*)item2);

    CLOVE_PTR_EQ(item2, removedItem);
    CLOVE_INT_EQ((int)(item2->num), (int)(removedItem->num));
    CLOVE_PTR_EQ(item3, item1->node.next);
    CLOVE_PTR_EQ(item1, item3->node.prev);

    destroy_item(item1);
    destroy_item(item2);
    destroy_item(item3);

}

CLOVE_TEST(DOUBLY_CHECKREMOVE_FIRSTITEM)
{
    item_t *list= NULL;
    int num1= 1;
    int num2= 2;
    int num3= 3;
    item_t *item1 = int_item_new(&num1);
    item_t *item2 = int_item_new(&num2);
    item_t *item3 = int_item_new(&num3);

    list_append_cast(&list,item1);
    list_append_cast(&list,item2);
    list_append_cast(&list,item3);

    item_t *removedItem = doubly_list_remove((doubly_node_t**)&list,(doubly_node_t*)item1);

    CLOVE_PTR_EQ(item1, removedItem);
    CLOVE_INT_EQ((int)(item1->num), (int)(removedItem->num));
    CLOVE_PTR_NE(item2->node.prev, item1);

    destroy_item(item1);
    destroy_item(item2);
    destroy_item(item3);

}

CLOVE_TEST(DOUBLY_CHECKREMOVE_LASTITEM)
{
    item_t *list= NULL;
    int num1= 1;
    int num2= 2;
    int num3= 3;
    item_t *item1 = int_item_new(&num1);
    item_t *item2 = int_item_new(&num2);
    item_t *item3 = int_item_new(&num3);

    list_append_cast(&list,item1);
    list_append_cast(&list,item2);
    list_append_cast(&list,item3);

    item_t *removedItem = doubly_list_remove((doubly_node_t**)&list,(doubly_node_t*)item3);

    CLOVE_PTR_EQ(item3, removedItem);
    CLOVE_INT_EQ((int)(item3->num), (int)(removedItem->num));
    CLOVE_PTR_NE(item2->node.next, item3);

    destroy_item(item1);
    destroy_item(item2);
    destroy_item(item3);
}

CLOVE_TEST(DOUBLY_INSERTAFTHER_EMPTYLIST)
{
    //can't insert afther nothing!

    item_t *list= NULL;

    int num1= 1;
    item_t *item1 = int_item_new(&num1);

    int result = list_insert_afther((doubly_node_t*)list,(doubly_node_t*)item1);

    CLOVE_INT_EQ(-1,result);
}

CLOVE_TEST(DOUBLY_INSERTAFTHER_LASTITEM)
{
   item_t *list= NULL;
    int num1= 1;
    int num2= 2;
    int num3= 3;
    item_t *item1 = int_item_new(&num1);
    item_t *item2 = int_item_new(&num2);
    item_t *item3 = int_item_new(&num3);

    list_append_cast(&list,item1);
    list_append_cast(&list,item2);

    int result = list_insert_afther((doubly_node_t*)item2,(doubly_node_t*)item3);

    CLOVE_INT_EQ(0, result);
    CLOVE_PTR_EQ(item2->node.next, item3);
    CLOVE_PTR_EQ(item3->node.prev, item2);

}

CLOVE_TEST(DOUBLY_INSERTAFTHER_CENTERITEM)
{
   item_t *list= NULL;
    int num1= 1;
    int num2= 2;
    int num3= 3;
    int num4= 4;
    item_t *item1 = int_item_new(&num1);
    item_t *item2 = int_item_new(&num2);
    item_t *item3 = int_item_new(&num3);
    item_t *item4 = int_item_new(&num4);


    list_append_cast(&list,item1);
    list_append_cast(&list,item2);
    list_append_cast(&list,item3);


    int result = list_insert_afther((doubly_node_t*)item2,(doubly_node_t*)item4);

    CLOVE_INT_EQ(0, result);
    CLOVE_PTR_EQ(item2->node.next, item4);
    CLOVE_PTR_EQ(item3->node.prev, item4);
    CLOVE_PTR_EQ(item4->node.prev, item2);
    CLOVE_PTR_EQ(item4->node.next, item3);

}

CLOVE_TEST(DOUBLY_INSERTBEFORE_CENTERITEM)
{
   item_t *list= NULL;
    int num1= 1;
    int num2= 2;
    int num3= 3;
    int num4= 4;
    item_t *item1 = int_item_new(&num1);
    item_t *item2 = int_item_new(&num2);
    item_t *item3 = int_item_new(&num3);
    item_t *item4 = int_item_new(&num4);


    list_append_cast(&list,item1);
    list_append_cast(&list,item2);
    list_append_cast(&list,item3);


    int result = list_insert_before((doubly_node_t**)list,(doubly_node_t*)item2,(doubly_node_t*)item4);

    CLOVE_INT_EQ(0, result);
    CLOVE_PTR_EQ(item2->node.prev, item4);
    CLOVE_PTR_EQ(item1->node.next, item4);
    CLOVE_PTR_EQ(item4->node.prev, item1);
    CLOVE_PTR_EQ(item4->node.next, item2);

}

CLOVE_TEST(DOUBLY_INSERTBEFORE_FIRSTITEM)
{
   item_t *list= NULL;
    int num1= 1;
    int num2= 2;
    int num3= 3;
    item_t *item1 = int_item_new(&num1);
    item_t *item2 = int_item_new(&num2);
    item_t *item3 = int_item_new(&num3);

    list_append_cast(&list,item1);
    list_append_cast(&list,item2);

    int result = list_insert_before((doubly_node_t**)list,(doubly_node_t*)item1,(doubly_node_t*)item3);


    CLOVE_INT_EQ(0, result);
    CLOVE_PTR_EQ(item3->node.prev, NULL);
    CLOVE_PTR_EQ(item3->node.next, item1);
    CLOVE_PTR_EQ(item1->node.prev, item3);

}
CLOVE_TEST(DOUBLY_GETLISTSIZE_EMPTYLIST)
{
     item_t *list= NULL;
    
    int list_size = doubly_list_get_size((doubly_node_t **)&list);

    CLOVE_INT_EQ(0,list_size);

}
CLOVE_TEST(DOUBLY_GETLISTSIZE)
{
     item_t *list= NULL;
    int num1= 1;
    int num2= 2;
    int num3= 3;
    item_t *item1 = int_item_new(&num1);
    item_t *item2 = int_item_new(&num2);
    item_t *item3 = int_item_new(&num3);

    list_append_cast(&list,item1);
    list_append_cast(&list,item2);
    list_append_cast(&list,item3);

    int list_size = doubly_list_get_size((doubly_node_t **)&list);

    CLOVE_INT_EQ(3,list_size);

}
CLOVE_TEST(DOUBLY_GETITEM_WITHINDEX_OUTOFRANGE)
{
     item_t *list= NULL;
    int num1= 1;
    int num2= 2;
    int num3= 3;
    
    item_t *item1 = int_item_new(&num1);
    item_t *item2 = int_item_new(&num2);
    item_t *item3 = int_item_new(&num3);
    
    list_append_cast(&list,item1);
    list_append_cast(&list,item2);
    list_append_cast(&list,item3);

    doubly_node_t *taked_item;
    int index = 4;
    taked_item = get_item_with_index((doubly_node_t**)&list, index);


    CLOVE_NULL(taked_item);

}
CLOVE_TEST(DOUBLY_GET_THEFOURTHITEM_WITHINDEX)
{
     item_t *list= NULL;
    int num1= 1;
    int num2= 2;
    int num3= 3;
    int num4= 4;
    int num5= 5;
    int num6= 6;
    item_t *item1 = int_item_new(&num1);
    item_t *item2 = int_item_new(&num2);
    item_t *item3 = int_item_new(&num3);
    item_t *item4 = int_item_new(&num4);
    item_t *item5 = int_item_new(&num5);
    item_t *item6 = int_item_new(&num6);

    list_append_cast(&list,item1);
    list_append_cast(&list,item2);
    list_append_cast(&list,item3);
    list_append_cast(&list,item4);
    list_append_cast(&list,item5);
    list_append_cast(&list,item6);


    doubly_node_t *taked_item;
    int index = 3;
    taked_item = get_item_with_index((doubly_node_t**)&list, index);


    CLOVE_PTR_EQ(taked_item,item4);

}






