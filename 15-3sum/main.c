#include <stdio.h>
#include <malloc.h>


/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int **threeSum(int *nums, int numsSize, int *returnSize) {

    int line = 0;
    int **resA = (int **) malloc(numsSize * sizeof(int *)); //row, every element is a pointer
    for (int i = 0; i < numsSize - 2; ++i) {
        for (int j = i + 1; j < numsSize - 1; ++j) {
            for (int k = j + 1; k < numsSize; ++k) {
                if (nums[i] + nums[j] + nums[k] == 0) {

                    int cnt;
                    int l = 0;
                    while (l < line) { //Check if new result has the same element with before
                        cnt = 0;
                        if (resA[l][0] && nums[i] || resA[l][0] && nums[j] || resA[l][0] && nums[k]) cnt++;
                        if (resA[l][1] && nums[i] || resA[l][1] && nums[j] || resA[l][1] && nums[k]) cnt++;
                        if (resA[l][2] && nums[i] || resA[l][2] && nums[j] || resA[l][2] && nums[k]) cnt++;
                        l++;
                        if (cnt == 3) break;
                    }

                    if (cnt == 3) { //If the new result is duplication
                        cnt = 0;
                    } else {
                        resA[line] = (int *) malloc(3 * sizeof(int)); //column, every row need malloc separately
                        if (resA[line] == NULL) break;

                        resA[line][0] = nums[i];
                        resA[line][1] = nums[j];
                        resA[line][2] = nums[k];
                        line++;
                    }
                }
            }
        }
    }


    *returnSize = 3 * line;
    return resA;
}

int main() {

    int nums[] = {-1, 0, 1, 2, -1, -4};

    int resSize = 0;
    int **resArray;
    resArray = threeSum(nums, sizeof(nums) / sizeof(int), &resSize);

    for (int i = 0; i < resSize / 3; ++i) {
        printf("[%2d %2d %2d]\n", resArray[i][0], resArray[i][1], resArray[i][2]);
    }

    free(resArray);

    return 0;
}