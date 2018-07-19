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
    //struct ListNode *p1, *l2;
    //l1 = l1;
    //l2 = l2;

    struct ListNode *pp = (struct ListNode *) calloc(1, sizeof(struct ListNode));
    struct ListNode *ret = (struct ListNode *) calloc(1, sizeof(struct ListNode));
    pp->val = 0;
    pp->next = NULL;
    ret = pp;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            pp->next = l1;
            pp = l1;
            l1 = l1->next;
        } else {
            pp->next = l2;
            pp = l2;
            l2 = l2->next;
        }
    }

    if (l1) {
        pp->next = l1;
    } else if (l2) {
        pp->next = l2;

    }

    return ret->next;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    if (listsSize == 0) return NULL;
    if (listsSize == 1) return *lists;

    struct ListNode *lTmp = lists[0];
    for (int i = 1; i < listsSize; ++i) {
        lTmp = mergeTwoLists(lTmp, lists[i]);

    }
    return lTmp;
}


int main() {
    int l1[] = {1, 2, 4};
    int l2[] = {1, 3, 4};
    int l3[] = {-9, 3};
    int l4[] = {5, 7};

    struct ListNode **lists = (struct ListNode **) malloc(3 * sizeof(struct ListNode *));
    printf("0x%x\n", lists);
    printf("0x%x\n", lists[0]);


    lists[0] = createList(l1,sizeof(l1) / sizeof(int));
    printList(lists[0]);
    lists[1] = createList(l2, sizeof(l2) / sizeof(int));
    printList(lists[1]);
    lists[2] = createList(l3, sizeof(l3) / sizeof(int));
    printList(lists[2]);
    lists[3] = createList(l4, sizeof(l4) / sizeof(int));
    printList(lists[3]);

//    printf("\nMegerd list:\n");
//    struct ListNode *mergerdL1 = mergeTwoLists(lists[0], lists[1]);
//    printList(mergerdL1);
//
//    printf("\nMegerd list:\n");
//    struct ListNode *mergerdL2 = mergeTwoLists(lists[2], lists[3]);
//    printList(mergerdL2);


    printf("Merged K Lists:\n");
    struct ListNode *mergedL3 = mergeKLists(lists, 4);
    printList(mergedL3);


    return 0;
}