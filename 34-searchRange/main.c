#include <stdio.h>
#include <stdlib.h>

//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//
//你的算法时间复杂度必须是 O(log n) 级别。
//
//如果数组中不存在目标值，返回 [-1, -1]。
//
//示例 1:
//
//输入: nums = [5,7,7,8,8,10], target = 8
//输出: [3,4]
//示例 2:
//
//输入: nums = [5,7,7,8,8,10], target = 6
//输出: [-1,-1]

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
//int *searchRange(int *nums, int numsSize, int target, int *returnSize) {
//
//    int low = 0;
//    int high = numsSize - 1;
//    int mid = 0;
//    int flag = 0;
//    while (low <= high) {
//        mid = (low + high) / 2;
//        if (nums[mid] == target) {
//            flag = 1;
//            break;
//        } else if (target < nums[mid]) {
//            high = mid - 1;
//        } else {
//            low = mid + 1;
//        }
//    }
//
//    *returnSize = 2;
//    int *ret = (int *) malloc(*returnSize * sizeof(int));
//
//    if (flag == 0) {
//        ret[0] = -1;
//        ret[1] = -1;
//        return ret;
//    }
//
//    int midH = mid;
//    while (nums[midH] <= target && midH < numsSize) {
//        midH++;
//    }
//    int midL = mid;
//    while (nums[midL] >= target && midL >= 0) {
//        midL--;
//    }
//
//    ret[0] = midL + 1;
//    ret[1] = midH - 1;
//    return ret;
//
//}

int *searchRange(int *nums, int numsSize, int target, int *returnSize) {

    int i = 0;
    while (target != nums[i] && i < numsSize) {
        i++;
    }

    *returnSize = 2;
    int *ret = (int *) malloc(*returnSize * sizeof(int));

    if (i == numsSize) {
        ret[0] = -1;
        ret[1] = -1;

    } else {
        ret[0] = i;
        while (target == nums[i] && i < numsSize) {
            i++;
        }
        ret[1] = i - 1;
    }
    return ret;
}

int main() {
//    int arr[] = {5, 7, 7, 8, 8, 10};
    int arr[] = {1};
    int size;
    int *res = searchRange(arr, sizeof(arr) / sizeof(int), 1, &size);
    for (int i = 0; i < size; ++i) {
        printf("%d,", res[i]);

    }

    free(res);
    return 0;
}