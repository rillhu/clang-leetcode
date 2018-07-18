#include <stdio.h>
#include <stdbool.h>
#include <mem.h>


struct Stack {
    char stack[128];
    char *top, *base;
};


void stInitial(struct Stack *stack) {
    memset((char *) (stack->stack), 0, 128);
    stack->top = &(stack->stack[0]);
    stack->base = stack->top;
}

void stPush(struct Stack *stack, char val) {
    *stack->top++ = val;
}

char stPop(struct Stack *stack) {
    return *stack->top--;
}

bool isValid(char *s) {
    struct Stack stL, stR;
    stInitial(&stL);
    stInitial(&stR);

    for (int i = 0; i < strlen(s); ++i) {
        switch (*s) {
            case '(':
            case '[':
            case '{':
                stPush(&stL, *s);
                break;
            case ')':
            case ']':
            case '}':
                stPush(&stR, *s);
                if (stPop(&stL) != stPop(&stR)) return false;
                break;
            default:
                break;
        }
    }

    return true;
}

int main() {
    char *str[] = {
            "()", //1
            "()[]{}",//1
            "(]",//0
            "([)]",//0
            "{[]}"//1
    };

    for (int i = 3; i < 4; ++i) {
        printf("%d\n", isValid(str[i]));

    }
    return 0;
}