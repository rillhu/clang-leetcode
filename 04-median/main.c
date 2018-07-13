#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {

    int *num = (int *) calloc(1, (nums1Size + nums2Size)* sizeof(int));

    int i = 0, j = 0;
    int k = 0;

    while (i < nums1Size && j < nums2Size) {

        if (nums1[i] < nums2[j]) {
            num[k] = nums1[i];
            i++;
        } else {
            num[k] = nums2[j];
            j++;
        }
        k++;

    }

    while (i < nums1Size) {
        num[k] = nums1[i];
        i++;
        k++;
    }

    while (j < nums2Size) {
        num[k] = nums2[j];
        j++;
        k++;
    }

    double median = 0.0;

    if (k % 2 == 0) {
        median = (double) (num[k / 2 - 1] + num[k / 2]) / 2.0;

    } else {
        median = (double) num[(k + 1) / 2 - 1];
    }

    return median;

}

int main() {
//    int num1[] = {1, 2};
//    int num2[] = {3, 4};

//    int num1[] = {1, 3};
//    int num2[] = {2};
    int num1[] = {2, 2, 2, 2};
    int num2[] = {2, 2, 2};

    printf("num1[]:\n[");
    for (int i = 0; i < sizeof(num1)/ sizeof(int); ++i) {
        printf("%d, ",num1[i]);
    }
    printf("]\nnum2[]:\n[");
    for (int i = 0; i < sizeof(num2)/ sizeof(int); ++i) {
        printf("%d, ",num2[i]);
    }

    printf("]\nmedian: %f\n", findMedianSortedArrays(num1, 4, num2, 3));
    return 0;
}