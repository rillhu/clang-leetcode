#include <stdio.h>

//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
//
//示例 1:
//
//输入: 1->1->2
//输出: 1->2
//示例 2:
//
//输入: 1->1->2->3->3
//输出: 1->2->3


#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * */
struct ListNode {
    int val;
    struct ListNode *next;
};

void printList(struct ListNode *l) {
    //Print the list elements
    printf("Create list in order:\n");
    while (l) {
        printf("%2d ", l->val);
        l = l->next;
    }
    printf("\n");
}

struct ListNode *createList(int *eles, int size) {
    struct ListNode *head, *tail;
    head = (struct ListNode *) calloc(1, sizeof(struct ListNode));
    head->next = NULL;
    tail = head;

    for (int i = 0; i < size; ++i) {
        struct ListNode *p = (struct ListNode *) calloc(1, sizeof(struct ListNode));
        p->val = eles[i];
        p->next = NULL;
        tail->next = p;
        tail = p;
    }

    return head->next;
}

struct ListNode *deleteDuplicates(struct ListNode *head) {
    if (head == NULL || head->next == NULL) return head;

    struct ListNode *p1 = head;
    struct ListNode *p2 = head;
    struct ListNode *headP = head;

    int dupFromBegninning = 0;

    if(p1->val == p1->next->val){
        dupFromBegninning = 1;
    }

    int flag = 0;
    while (p1->next != NULL) {
        p2 = p2->next;
        if (p1->val == p2->val) { //until get the different element
            p1->next = p2->next;
            flag = 1;
        } else {
            if (flag == 0) {
                headP = p1;
                headP->next = p2;
            } else {

                headP->next = p2;
                flag = 0;
            }
            p1 = p2;
        }
    }

    if(flag==1){
        headP->next = NULL;
    }
    if(dupFromBegninning == 1){
        head = head->next;
    }
    return head;
}

int main() {
//    int list1[] = {1, 1, 1, 2, 2, 2,3,3,4};
    int list1[] = {1, 1,2,2, 3, 3, 3, 4, 4, 4, 5, 5,6};

    struct ListNode *l1 = createList(list1, sizeof(list1) / sizeof(int));
    printList(l1);


    printf("\nMegerd list:\n");
    struct ListNode *mergerdL = deleteDuplicates(l1);
    printList(mergerdL);
    return 0;
}