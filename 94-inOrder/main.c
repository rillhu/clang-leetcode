#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


/*Create the binary tree: first order bitree*/
struct TreeNode *createBiTree(char *e, int *i) {
    struct TreeNode *bt = NULL;

    if (e[(*i)++] != '#') //Note: This is inta recursive implementation, pointer i should not be added
    {
        bt = (struct TreeNode *) malloc(sizeof(struct TreeNode));
        bt->val = e[*i-1];
        bt->left = createBiTree(e, i);
        bt->right = createBiTree(e, i);
    }

//    if (e[(*i)] != '#') //Note: This is inta recursive implementation, pointer i should not be added
//    {
//        (*i)++;
//        bt = (struct TreeNode *) malloc(sizeof(struct TreeNode));
//        bt->val = e[*i-1];
//        bt->left = createBiTree(e, i);
//        bt->right = createBiTree(e, i);
//    }else{
//        (*i)++;
//        bt = NULL;
//    }

    return bt;
}


/*In order:Left-Root-Right*/
void inOrderBiTree(struct TreeNode *bt) {
    if (bt != NULL) {
        inOrderBiTree(bt->left);
        printf("%c", bt->val);
        inOrderBiTree(bt->right);
    }
}


//stack: using linear storage
#define MAXSIZE 100
struct stack {
    struct TreeNode *data[MAXSIZE];
    int top;
};

struct stack *initStack() {
    struct stack *stack;
    stack = (struct stack *) malloc(sizeof(struct stack));
    if (stack) {
        stack->top = -1;
    }
    return stack;
}

int emptyStack(struct stack *stack) {
    if (stack->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int pushStack(struct stack *stack, struct TreeNode *node) {
    if (stack->top == MAXSIZE - 1) {
        return 0;
    } else {
        stack->top++;
        stack->data[stack->top] = node;
        return 1;
    }
}

int popStack(struct stack *stack, struct TreeNode **node) {
    if (emptyStack(stack) == 1) {
        return 0;
    } else {
        *node = stack->data[stack->top];
        stack->top--;
        return 1;
    }
}
//stack



/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

//ref: https://blog.csdn.net/qq_24754061/article/details/72780229
int *inorderTraversal(struct TreeNode *root, int *returnSize) {
    *returnSize = 0;
    int *ret = (int *)malloc(MAXSIZE* sizeof(int));
    struct stack * stack;
    struct TreeNode * p = root;
    stack = initStack();
    while (p || !emptyStack(stack)) {
        if (p) {
            pushStack(stack, p);
            p = p->left;
        } else {
            popStack(stack, &p);
            //visit(p->data);
            printf("%c->",p->val);
            ret[*returnSize] = p->val;
            *returnSize += 1;
            p = p->right;
        }
    }

    return ret;
}


int main() {
    int i = 0;

//    int *p = &i;
//    printf("%d,%d\n",*p,p);
//    (*p)++;
//    printf("%d,%d\n",*p,p);
//    (*p)++;
//    printf("%d,%d\n",*p,p);


    char *cStr = "ABDH##I##E#J##CF#K##G##";
//    char *cStr = "1#23###";

    struct TreeNode *bt = createBiTree(cStr, &i);
    printf("Bi tree creation is done!\n");
    printf("In order the bi tree:\n");
    inOrderBiTree(bt);
    printf("\n");


    int size = 0;
    int *res = inorderTraversal(bt, &size);
    for (int j = 0; j < size; ++j) {
        printf("%c ", *res++);

    }
    return 0;
}