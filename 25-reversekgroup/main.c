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

struct ListNode *reverseKGroup(struct ListNode *head, int k) {

    //Add a head for the list
    struct ListNode *pp, *ppp;
    pp = ppp = head;
    int lpOut = 0;
    while (pp) {
        /*Check if list has enough node to reverse
         * if not, directly return the head pointer*/
        int cnt = 0;
        struct ListNode *p;
        p = pp;

        while (cnt < k && p != NULL) {
            p = p->next;
            cnt++;
        }
        if (cnt < k) return head;   //This will not cause problem
                                    // since the k is less or equal the list length


        /*Reverse the sub-list with len == k*/
        struct ListNode *p1, *p2, *p3;
        p1 = p2 = p3 = pp;
        int lpIn = 0;
        while (lpIn < k) {
            if (p1 != NULL) {
                if (lpIn == 0) {
                    p1 = p1->next;  //First node handling
                } else {
                    p3 = p1->next;
                    p1->next = p2;
                    p2 = p1;
                    p1 = p3;
                }
            }
            lpIn++;
        }

        /*Post-update the ppp and pp pointers*/
        if (lpOut == 0) {
            ppp = pp;
            ppp->next = p1;
            pp = p1;
        } else {
            ppp->next = p2;
            pp->next = p1;
            ppp = pp;
            pp = p1;
        }

        /*Only update the head node pointer when first loop*/
        if (lpOut == 0) {
            head = p2;
        }

        lpOut++;    //Update the loop counter
    }
    return head;
}


int main() {
    int list1[] = {1, 2, 3, 4, 5, 6};// 6, 7, 8, 9};

    ListNodeT *l1 = createList(list1, sizeof(list1) / sizeof(int));
    //printList(l1);

    struct ListNode *exKList = reverseKGroup(l1, 6);
    printList(exKList);

    return 0;
}