#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize) {
    *returnSize = 0;
    int t = 0;
    digits[digitsSize - 1] += 1;
    for (int i = digitsSize - 1; i > 0; --i) {
        digits[i] += t;
        t = digits[i] / 10;
        digits[i] %= 10;
    }

    /*Handle the MSB*/
    digits[0] += t;
    t = digits[0] / 10;
    digits[0] %= 10;

    /*If the MSB is bigger than 10*/
    int add = 0;
    int *r;
    if (t > 0) {
        r = (int *) calloc(1, sizeof(int) * (digitsSize + 1));
        r[0] = t;
        add += 1;
        *returnSize += 1;
    } else {
        r = (int *) calloc(1, sizeof(int) * (digitsSize));
    }

    *returnSize += digitsSize;
    memcpy(r + add, digits, digitsSize * sizeof(int));

    return r;
}

int main() {

    int a[] = {4,3,2,1};
    int size;
    int *r = plusOne(a, sizeof(a) / sizeof(int), &size);

    for (int i = 0; i < size; ++i) {
        printf("%d,", r[i]);

    }
    return 0;
}