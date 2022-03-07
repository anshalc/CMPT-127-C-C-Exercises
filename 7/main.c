// main.c

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(int argc, char *argv[])
{
    list_t *list = list_create();
    if (list->head != NULL || list->tail != NULL)
    {
        puts("When the list is empty, it is NULL");
        return 1;
    }

    list_print(list);

    int i = 5;
    for(i = 5; i < 10; i++)
    {
        list_append(list,i);
    }
    
    int j = 4;
    for (j = 4; j >=0; j--)
    {
        list_prepend(list,j);
    }

    int numCount = 0;
    for (element_t* ind = list->head; ind->next; ind = ind->next)
    {
        if (ind->val != numCount)
        {
            printf("The index value %d instead of %d\n", numCount, numCount);
            return 1;
        }
        numCount++;
    }

    list_print(list);
    int ind = 2;
    
    element_t* el = list_index(list,ind);
    if (el == NULL)
    {
        printf(" %d is not found\n", ind);
        return 1;
    }

    int ind2 = -2;

    element_t* el2 = list_index(list,ind2);
    if (el2 != NULL)
    {
        puts("This should actually be NULL");
        return 1;
    }

    printf("The index value %d is %d\n", ind, el->val);

    if (el->val != 2)
    {
        puts("The value should be 2");
        return 1;
    }

    int ind3 = 15;

    element_t* el3 = list_index(list, ind3);

    if (el3 != NULL)
    {
        puts("This should actually be NULL");
        return 1;
    }

    element_t* el4 = element_create(10);
    list->tail->next = el4;
    list->tail = el4;
    list_print(list);
    free(el4);
    list_print(list);
    list_t* list_2 = list_create();
    list_print(list_2);
    list_prepend(list_2, 5);
    list_append(list_2, 6);
    list_print(list_2);
    list_destroy(list_2);

    list_t* list_3 = list_create();

    if (list_3->head != NULL)
    {
        printf("This new list head should actually be NULL");
        return 1;
    }

    element_t* test_list_3 = list_index(list_3,3);

    if (test_list_3 != NULL)
    {
        puts("Returns NULL when there is an empty list");
        return 1;
    }

    list_prepend(list_3,3);

    if (list_3->tail == NULL)
    {
        puts("Tail should actually point to value");
        return 1;
    }

    list_append(list_3,4);
    list_append(list_3,5);
    list_print(list_3);
    list_destroy(list_3);

    element_t* test_5 = element_create(4);
    if (test_5->next != NULL)
    {
        puts("Next pointer should end up being NULL");
        return 1;
    }
    
    return 0;
}