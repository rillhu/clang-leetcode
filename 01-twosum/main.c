#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*method 0: not pretty good due to it cannot support negative value as element of array.*/
//int *twoSum(int *nums, int numsSize, int target) {
//    int *res = (int *) malloc(2 * sizeof(int));
//    memset((char *) res, 0, 2 * sizeof(int));
//
//    /*Create a simple HASH map for nums*/
//    int min = nums[0];
//    int max = nums[0];
//    for (int j = 1; j < numsSize; ++j) {
//        if (min > nums[j]) min = nums[j];
//        if (max < nums[j]) max = nums[j];
//    }
//
//    if (target < 2 * min) return res;
//
//    int mNum = target - min + 1;       //the elements num of the map should be the bigger one between
//    mNum = (mNum > max) ? mNum : max;  //target - min +1 and max
//#ifdef DEBUG
//    printf("Create a %d elements map: \n", mNum);
//#endif
//    int *m = (int *) malloc((mNum) * sizeof(int));
//    memset((char *) m, -1, mNum * sizeof(int));
//    //Initialize the map
//    for (int k = 0; k < numsSize; ++k) {
//        m[nums[k]] = k;
//    }
//#ifdef DEBUG
//    for (int l = 0; l <= mNum; ++l) {
//        printf("%d ", m[l]);
//    }
//    printf("\n\n");
//#endif
//
//    /*Use HASH map to detect the other adder.*/
//    for (int i = 0; i < numsSize; ++i) {
//        if (target < nums[i])continue;
//        int t = target - nums[i]; //Get the other adder
//        //condition 1: 查找元素t（the other adder）是否在map中
//        //condition 2: 避免元素重复
//        if ((m[t] >= 0) && (m[t] <= numsSize - 1) && (m[t] != i)) {
//            res[0] = i;
//            res[1] = m[t];
//            break;
//        }
//    }
//
//    free(m);
//    return res;
//}

/*method*/
int *twoSum(int *nums, int numsSize, int target) {
    bool found = false;
    int *res = (int *) calloc(2, sizeof(int));
    for (int i = 0; i < numsSize - 1 && !found; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (target == nums[i] + nums[j]) {
                found = true;
                res[0] = i;
                res[1] = j;
                break;
            }
        }
    }
    return res;
}

int main() {

    int array[4] = {-3, 4, 3, 90};


    for (int i = -50; i < 50; ++i) {
        int target = i;

        int *res = twoSum(array, sizeof(array) / sizeof(int), target);

        if (res[0] != res[1]) { //assume the return values are correctly initialized.
            printf("nums[%2d]%4d + nums[%2d]%4d = target %4d\n", res[0],array[res[0]], res[1],array[res[1]], target);
        } else {
            printf("Sum cannot get Target %4d!\n", target);
        }
        free(res);
    }
    return 0;
}