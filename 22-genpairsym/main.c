#include <stdio.h>
#include <malloc.h>
#include <mem.h>


struct Stack {
    char *stack;
    char *top, *base;
};

void stInitial(struct Stack *stack, int len) {
    stack->stack = (char *) calloc(1, len);
    stack->top = stack->stack;
    stack->base = stack->top;
}

void stPush(struct Stack *stack, char val) {
    *stack->top++ = val;
}

char stPop(struct Stack *stack) {
    if (stack->top != stack->base) {
        stack->top--;
    }
    return *stack->top;

}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **generateParenthesis(int n, int *returnSize) {
    char *lSym = calloc(1, n);
    char *rSym = calloc(1, n);
    memset(lSym, '(', n);
    memset(rSym, ')', n);

    char **str = (char **) malloc(n * n);
    str[0] = (char *) calloc(1, n * 2 + 1);

    struct Stack st;
    stInitial(&st, n);

    for (int k = 0; k < n * 2; ++k) {
        for (int i = 0; i < n; ++i) {
            //stPush(&st, lSym[i]);
            for (int j = 0; j < n; ++j) {


            }
        }
    }


    char **str = (char **) malloc(n * n);

    str[0] = (char *) calloc(1, n * 2 + 1);
    memset(str[0], 'a', n * 2);

    *returnSize += 1;
    str[1] = (char *) calloc(1, n * 2 + 1);
    memset(str[1], 'b', n * 2);
    *returnSize += 1;
    return str;
}

int main() {

    int size = 0;
    char **p = generateParenthesis(3, &size);

    for (int i = 0; i < size; ++i) {
        printf("%s\n", *p++);
    }


    return 0;
}