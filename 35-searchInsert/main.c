#include <stdio.h>
//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//
//你可以假设数组中无重复元素。
//
//示例 1:
//
//输入: [1,3,5,6], 5
//输出: 2
//示例 2:
//
//输入: [1,3,5,6], 2
//输出: 1
//示例 3:
//
//输入: [1,3,5,6], 7
//输出: 4
//示例 4:
//
//输入: [1,3,5,6], 0
//输出: 0



int searchInsert(int *nums, int numsSize, int target) {
    int i = 0;
    while (target > nums[i] && i < numsSize) {
        i++;
    }
    return i;

}

int main() {
    int arr1[] = {1, 3, 5, 6};

    printf("%d\n", searchInsert(arr1, sizeof(arr1) / sizeof(int), 4));
    return 0;
}