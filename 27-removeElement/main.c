#include <stdio.h>

int removeElement(int *nums, int numsSize, int val) {

    int i = 0;
    int j = 0;

    for (i = 0; i < numsSize; ++i) {
        if (nums[i] == val) {
        } else {
            nums[j] = nums[i];
            j++;
        }
    }

    return j;

}

int main() {
//    int nums[] = {3, 2, 2, 3};
    int nums[] = {0,1,2,2,3,0,4,2};

    int len = removeElement(nums, sizeof(nums) / sizeof(int), 2);
    for (int i = 0; i < len; ++i) {
        printf("%d ", nums[i]);

    }
    printf("\n");
    return 0;
}