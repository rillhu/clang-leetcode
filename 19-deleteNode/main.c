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


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//method 0
//struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
//    struct ListNode *l = head;
//    int len = 0;
//    while (l) {
//        len++;
//        l = l->next;
//    }
//
//    if (len == n) {
//        head = head->next;
//        return head;
//    }
//
//    l = head;
//    for (int i = 0; i < len - n - 1; ++i) {
//        l = l->next;
//    }
//    struct ListNode *tmp = l->next;
//    l->next = tmp->next;
//
//    return head;
//
//}

//method 1
struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    struct ListNode *curr, *currN;

    curr = head;
    currN = head;

    int len = 0;
    for (int i = 0; i < n; ++i) { //find the 1st node which n ahead the list head
        currN = currN->next;
    }

    if (!currN) return head->next; //if n points the 1st node of the list

    while (currN->next) {   //loop until currN point to last node
        curr = curr->next;
        currN = currN->next;
    }

    struct ListNode *tmp = curr->next;  //delete curr->next node
    curr->next = tmp->next;

    return head;
}

int main() {


    for (int i = 1; i < 6; ++i) {
        int list1[] = {1, 2, 3, 4, 5};
        ListNodeT *l1 = createList(list1, sizeof(list1) / sizeof(int));
        printList(l1);

        printf("\nDelete %d node list:\n", i);
        ListNodeT *ret = removeNthFromEnd(l1, i);

        printList(ret);

    }


    return 0;
}