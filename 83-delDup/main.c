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
    struct ListNode *p2 = head->next;

    while (p1->next != NULL) {
        if (p1->val == p2->val) {
            p1->next = p2->next;
            p2 = p2->next;
        } else {
            p1->next = p2;
            p1 = p2;
            p2 = p2->next;
        }
    }
    return head;
}

int main() {
    int list1[] = {1, 1, 1, 2, 2, 2, 2, 3, 4, 5, 6, 7, 8, 8, 8, 9};
//    int list1[] = {1, 1, 2,3,3};

    struct ListNode *l1 = createList(list1, sizeof(list1) / sizeof(int));
    printList(l1);


    printf("\nMegerd list:\n");
    struct ListNode *mergerdL = deleteDuplicates(l1);
    printList(mergerdL);
    return 0;
}