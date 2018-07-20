#include <stdio.h>

//method 0
//int removeDuplicates(int *nums, int numsSize) {
//    if (numsSize <= 1) return numsSize;
//
//    int i = 0;
//    int j = 0;
//    for (j = 0; j < numsSize; ++j) {
//        while (i < numsSize - 1 && nums[i] == nums[i + 1]) {
//            i++;
//        }
//        nums[j] = nums[i];
//        if (i == numsSize - 1) break;
//        i++;    //Move i to next potential loop
//    }
//
//    return j+1; //number = subscript + 1
//}

int removeDuplicates(int *nums, int numsSize) {
    if (numsSize <= 1) return numsSize;

    int j = 0;
    int i = 0;
    for (i = 0; i < numsSize - 1; ++i) {
        if (nums[i] == nums[i + 1]) {
        } else {
            nums[j] = nums[i];
            j++;
        }
    }

    nums[j] = nums[i];
    printf("size: %d\n", j);
    return j +1 ;
}

int main() {
//    给定数组 nums = [1,1,2],//
//    函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
//    你不需要考虑数组中超出新长度后面的元素。

//    给定 nums = [0,0,1,1,1,2,2,3,3,4],//
//    函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
//    你不需要考虑数组中超出新长度后面的元素。

    int nums[] = {1,1};
//    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
//    int nums[] = {-1, 0, 0, 0, 0, 3, 3};
    int len = removeDuplicates(nums, sizeof(nums) / sizeof(int));

    for (int i = 0; i < len; ++i) {
        printf("%d ", nums[i]);

    }
    printf("\n");
    return 0;
}