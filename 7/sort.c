//sort.c

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

void list_catenate(list_t * L1, list_t * L2) {
    if (L2->head == NULL) {
        assert(L2->tail == NULL);
    } else if (L1->head == NULL) {
        assert(L1->tail == NULL);
        //L1->head = L2->head;
        //L1->tail = L2->tail;
        *L1 = *L2;
    } else {
        L1->tail->next = L2->head;
        L1->tail= L2->tail;
    }
    free(L2);
}


void list_sort( list_t* list )

{
    // base case:  0 or 1 node
    if (list->head == list->tail) {
        return;
    }
    // remove the head from list     
    int pivot = list->head->val;
    
    element_t * pivot_element = list->head;
    
    list->head = list->head->next;
    
    // partition
    list_t * first = list_create();
    
    list_t * second = list_create();
    
    element_t * curr = list->head;
    
    element_t * next;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = NULL;
        //printf("1\n");
        if (curr->val <= pivot) {
        	list_append( first, curr->val );            
            //printf("11\n");
            /*if (first->head==NULL)
            first->tail->next = curr;
            printf("111\n");
            first->tail = curr;*/            
        } else {            
            list_append( second, curr->val );
            //printf("12\n");
        }
        //printf("2\n");
        curr = next;
    }
    //printf("3\n");
    list->head = NULL;
    list->tail = NULL;
    //printf("4\n");
    list_sort(first);
    list_sort(second);
    list_catenate(list, first);
    //printf("5\n");
    /*list->tail->next=first->head;
    list->tail=first->tail;*/
    //printf("6\n");
    list_append( list, pivot_element->val);
    
    list_catenate(list, second);
    //printf("7\n");
    /*list->tail->next=second->head;
    list->tail=second->tail;*/
    //printf("8\n");
}