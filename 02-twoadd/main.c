#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    //Print the list elements
    printf("Create list in order:\n");
    for (ListNodeT *l = head->next; l != NULL; l = l->next) {
        printf("%d ", l->val);
    }
    printf("\n");

    return head;
}

char *getNumFromList(struct ListNode *l, int *size) {
    struct ListNode *p = l;

    int num = 0;
    while (p->next != NULL) {
        p = p->next;
        num++;
    }

    *size = num;
    //printf("number: %d\n", num);

    char *str = (char *) calloc(num + 1, sizeof(char));
    p = l->next;
    for (int i = num - 1; i >= 0; --i) {
        str[i] = (char) (p->val);// + 0x30);
        p = p->next;
    }

    //printf("str: %s\n", str);

//    int lNum = atoi(str);
//
//    printf("l1Num: %d\n", lNum);
//    return lNum;
    printf("str: \n");
    for (int j = 0; j < num; ++j) {
        printf("%d ", str[j]);
    }
    printf("\n");
    return str;
}

//struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
//    struct ListNode *head, *tail;
//    head = (struct ListNode *) calloc(1, sizeof(struct ListNode));
//    head->next = NULL;
//    tail = head;
//
//    int flag = 0;
//    struct ListNode *p1, *p2;
//    p1 = l1->next;
//    p2 = l2->next;
//
//    while (p1 != NULL || p2 != NULL||flag == 1) {
//        struct ListNode *p = (struct ListNode *) calloc(1, sizeof(struct ListNode));
//        if(p1!=NULL){
//            p->val += p1->val;
//        }
//        if(p2!=NULL){
//            p->val += p2->val;
//        }
//        p->val += flag;
//        //p->val = p1->val + p2->val + flag;
//        flag = 0;
//        if (p->val >= 10) {
//            p->val -= 10;
//            flag = 1;
//        }
//        p->next = NULL;
//        tail->next = p;
//        tail = p;
//
//if (p1 != NULL) p1 = p1->next;
//if (p2 != NULL) p2 = p2->next;
//    }
//
//    //Print the list elements
//    printf("Result list in order:\n");
//    for (struct ListNode *l = head->next; l != NULL; l = l->next) {
//        printf("%d ", l->val);
//    }
//    printf("\n");
//    return head;
//
//}

/*solution for leetcode: donot have head node*/
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *head, *tail;
    head = (struct ListNode *) calloc(1, sizeof(struct ListNode));
    head->next = NULL;
    tail = head;

    struct ListNode *p1, *p2;
    p1 = l1;
    p2 = l2;
    int flag = 0;
    while (p1 != NULL || p2 != NULL || flag == 1) {
        struct ListNode *p = (struct ListNode *) calloc(1, sizeof(struct ListNode));
        if (p1 != NULL) {
            p->val += p1->val;
        }
        if (p2 != NULL) {
            p->val += p2->val;
        }
        p->val += flag;

        flag = 0;
        if (p->val >= 10) {
            p->val -= 10;
            flag = 1;
        }
        p->next = NULL;
        tail->next = p;
        tail = p;

        if (p1 != NULL) p1 = p1->next;
        if (p2 != NULL) p2 = p2->next;
    }
    //Print the list elements
    printf("Result list in order:\n");
    for (struct ListNode *l = head->next->next; l != NULL; l = l->next) {
        printf("%d ", l->val);
    }
    printf("\n");
    return head->next;
}


int main() {

    int adder1[] = {2, 4, 3};
    int adder2[] = {5, 6, 4};

    ListNodeT *l1 = createList(adder1, sizeof(adder1) / sizeof(int));
    ListNodeT *l2 = createList(adder2, sizeof(adder1) / sizeof(int));

    ListNodeT *sum = addTwoNumbers(l1, l2);


    printf("\n\n");

    return 0;
}