#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNodeT;

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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *swapPairs(struct ListNode *head) {
    struct ListNode *p1, *p2, *pp;

    p1 = head;
    if (p1 == NULL) return NULL;
    p2 = p1->next;
    if (p2 == NULL) return p1;

    p1->next = p2->next;
    p2->next = p1;
    head = p2;

    while (p1 && p2) {
        pp = p1;

        p1 = p1->next;
        if (p1 == NULL) break;

        p2 = p1->next;
        if(p2 == NULL) break;

        p1->next = p2->next;
        p2->next = p1;

        pp->next = p2;

    }

    return head;
}

int main() {
    int list1[] = {1, 2, 3, 4, 5, 6};
    int list2[] = {1, 3, 4};
//    int list1[] = {-9,3};
//    int list2[] = {5,7};

    ListNodeT *l1 = createList(list1, sizeof(list1) / sizeof(int));
    printList(l1);


    printf("\nMegerd list:\n");
    struct ListNode *exList = swapPairs(l1);
    printList(exList);
    return 0;
}