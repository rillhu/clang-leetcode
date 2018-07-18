#include <stdio.h>

//Method 0 is time out
//int maxArea(int *height, int heightSize) {
//    int max = 0;
//    for (int i = 0; i < heightSize - 1; ++i) {
//        for (int j = i + 1; j < heightSize; ++j) {
//            int hMin = height[i] < height[j] ? height[i] : height[j];
//            int tmp = (j - i) * hMin;
//            if (max < tmp)max = tmp;
//        }
//    }
//
//    return max;
//}

//Double pointer method
//The algorithm theory is not fully proved and understand, just copy from JAVA solution
int maxArea(int *height, int heightSize) {
    int max = 0;
    int l = 0, r = heightSize - 1;
    while (l < r) {
//        int hMin = height[l] < height[r] ? height[l] : height[r];
//        int tmp = (r - l) * hMin;
//        if (max < tmp)max = tmp;

        max = (max > ((height[l] < height[r] ? height[l] : height[r]) * (r - l)) ? max: ((height[l] < height[r] ? height[l] : height[r]) * (r - l)));

        if (height[l] < height[r]) {
            l++;
        } else {
            r--;
        }
    }
    return max;
}


int main() {
    int nums[] = {1, 1};

    printf("MaxArea: %d\n", maxArea(nums, sizeof(nums) / sizeof(int)));

    return 0;
}