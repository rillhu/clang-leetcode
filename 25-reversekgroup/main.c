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

struct ListNode *reverseList(struct ListNode *head, int k) {
    int cnt = 0;
    struct ListNode *p = head;
    while (cnt++ < k && p != NULL) {
        p = p->next;
    }
    if (cnt < k) return head;


    struct ListNode *p1, *p2, *p3;
    p1 = p2 = p3 = head;

    int loop = 0;
    while (loop < k) {
        if (p1->next != NULL) {
            if (loop == 0) {
                p1 = p1->next;  //First node handling
            } else {
                p3 = p1->next;
                p1->next = p2;
                p2 = p1;
                p1 = p3;
            }
        }
        loop++;
    }

    head->next = p1;
    return p2;
}

struct ListNode *reverseKGroup(struct ListNode *head, int k) {

    struct ListNode *ret;
    while(head!=NULL) {
        ret = reverseList(head, k);
        printList(ret);
    }
    return ret;
}


int main() {
    int list1[] = {1, 2, 3, 4, 5};// 6, 7, 8, 9};

    ListNodeT *l1 = createList(list1, sizeof(list1) / sizeof(int));
    printList(l1);

    struct ListNode *exKList = reverseKGroup(l1, 3);
    printList(exKList);

    return 0;
}