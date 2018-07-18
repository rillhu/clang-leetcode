#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNodeT;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void printList(struct ListNode *l) {
    //Print the list elements
    printf("Create list in order:\n");
    while (l) {
        printf("%2d ", l->val);
        l = l->next;
    }
    printf("\n");
}

ListNodeT *createList(int *eles, int size) {
    ListNodeT *head, *tail;
    head = (ListNodeT *) calloc(1, sizeof(ListNodeT));
    head->next = NULL;
    tail = head;

    for (int i = 0; i < size; ++i) {
        ListNodeT *p = (ListNodeT *) calloc(1, sizeof(ListNodeT));
        p->val = eles[i];
        p->next = NULL;
        tail->next = p;
        tail = p;
    }

    return head->next;
}

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *p1, *p2, *ret;
    p1 = l1;
    p2 = l2;

    struct ListNode *pp = (struct ListNode *) calloc(1, sizeof(struct ListNode));
    pp->val = 0;
    ret = pp;

    while (p1 != NULL && p2 != NULL) {
        if (p1->val < p2->val) {
            pp->next = p1;
            pp = p1;
            p1 = p1->next;
        } else {
            pp->next = p2;
            pp = p2;
            p2 = p2->next;
        }
    }

//    while (p1) {
//        pp->next = p1;
//        pp = p1;
//        p1 = p1->next;
//    }
//
//    while (p2) {
//        pp->next = p2;
//        pp = p2;
//        p2 = p2->next;
//    }

    if(p1){
        pp->next = p1;
    }else if(p2){
        pp->next = p2;

    }

    return ret->next;
}


int main() {
    int list1[] = {1, 2, 4};
    int list2[] = {1, 3, 4};
//    int list1[] = {-9,3};
//    int list2[] = {5,7};

    ListNodeT *l1 = createList(list1, sizeof(list1)/ sizeof(int));
    printList(l1);
    ListNodeT *l2 = createList(list2, sizeof(list2)/ sizeof(int));
    printList(l2);

    printf("\nMegerd list:\n");
    struct ListNode *mergerdL = mergeTwoLists(l1, l2);
    printList(mergerdL);
    return 0;
}