#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 *
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct Interval {
    int start;
    int end;
};

int min(int v1, int v2) {
    return (v1 < v2) ? v1 : v2;
}

int max(int v1, int v2) {
    return (v1 > v2) ? v1 : v2;
}

struct Interval *merge(struct Interval *intervals, int intervalsSize, int *returnSize) {
    //printf("size: %d\n", intervalsSize);
    if (intervalsSize == 0) return NULL;

    for (int i = 0; i < intervalsSize ; ++i) {
        for (int j = i+1; j < intervalsSize; ++j) {
            if(intervals[i].start>intervals[j].start){
                int t = intervals[i].start;
                intervals[i].start = intervals[j].start;
                intervals[j].start = t;

                t = intervals[i].end;
                intervals[i].end = intervals[j].end;
                intervals[j].end = t;
            }
        }
    }

//    for (int i = 0; i < intervalsSize; ++i) {
//        printf("[%d,%d]\n", intervals[i].start, intervals[i].end);
//    }

    struct Interval *res = (struct Interval *) calloc(intervalsSize, sizeof(struct Interval));

    int i = 0;
    int resId = 0;
    while (i < intervalsSize) {
        if (intervals[i].start == -1 && intervals[i].end == 0) { //Invalid interval, using [-1, 0] as the magic word
            i++;
            continue;
        }
        res[resId] = intervals[i];
        for (int j = i + 1; j < intervalsSize; ++j) {
            if (intervals[j].start == -1 && intervals[j].end == 0) { //Invalid interval, using [-1, 0] as the magic word
                continue;
            }
            if ((res[resId].end < intervals[j].start) || (res[resId].start > intervals[j].end)) {  //No overlap

            } else if (res[resId].end >= intervals[j].start && res[resId].end <= intervals[j].end &&
                       res[resId].start <= intervals[j].start) { //overlap type 1: [1,3], [2,6]
                res[resId].end = intervals[j].end;

                intervals[j].start = -1;
                intervals[j].end = 0;
            }  else if (res[resId].end >= intervals[j].start && res[resId].end >= intervals[j].end &&
                       res[resId].start <= intervals[j].start) { //overlap type 2: [1,7], [2,6]
                intervals[j].start = -1;
                intervals[j].end = 0;
            }
        }
        i++;
        resId++;
    }




    *returnSize = resId;
    return res;
//    int min = res[0].start;
//    int max = res[0].end;
//    int minId = 0, maxId = 0;
//    int k = 0;
//    for (k = 0; k < resId; ++k) {
//
//        if (min > res[k].start) {
//            min = res[k].start;
//            minId = k;
//        }
//        if (max < res[k].end) {
//            max = res[k].end;
//            maxId = k;
//        }
//    }
//
//    if (minId == maxId) {
//        *returnSize = 1;
//        res[0] = res[minId];
//    }

//    int id = 0;
//    i = 0;
//    struct Interval *res2 = (struct Interval *) calloc(resId, sizeof(struct Interval));
//    while (i < resId) {
//        if (res[i].start == -1 && res[i].end == 0) { //Invalid interval, using [-1, 0] as the magic word
//            i++;
//            continue;
//        }
//        res2[id] = res[i];
//        for (int j = i + 1; j < resId; ++j) {
//            if (res[j].start == -1 && res[j].end == 0) { //Invalid interval, using [-1, 0] as the magic word
//                continue;
//            }
//            if ((res2[id].end < res[j].start) || (res2[id].start > res[j].end)) {  //No overlap
//
//            } else if (res2[id].end >= res[j].start && res2[id].end <= res[j].end &&
//                       res2[id].start <= res[j].start) { //overlap type 1: [1,3], [2,6]
//                res2[id].end = res[j].end;
//
//                res[j].start = -1;
//                res[j].end = 0;
//            } else if ((res2[id].end >= res[j].start && res2[id].end >= res[j].end &&
//                        res2[id].start >= res[j].start)) {//overlap type 1: [2,6], [1,3]
//                res2[id].start = res[j].start;
//                res[j].start = -1;
//                res[j].end = 0;
//            } else if (res2[id].end >= res[j].start && res2[id].end >= res[j].end &&
//                       res2[id].start <= res[j].start) { //overlap type 2: [1,7], [2,6]
//                res[j].start = -1;
//                res[j].end = 0;
//            } else if (res2[id].end >= res[j].start && res2[id].end <= res[j].end &&
//                       res2[id].start >= res[j].start) { //overlap type 2: [2,6], [1, 7]
//                res2[id].start = res[j].start;
//                res2[id].end = res[j].end;
//                res[j].start = -1;
//                res[j].end = 0;
//            }
//        }
//        i++;
//        id++;
//    }
//    *returnSize = id;
//
//    return res2;
}


int main() {
    struct Interval arr[] = {
            {1,  3},
            {2,  6},
            {8,  10},
            {15, 18}
    };
//    struct Interval arr[] = {
//            {1, 4},
//            {4, 5}
//    };
//    struct Interval arr[] = {
//            {1, 4},
//            {0, 0}
//    };
//    struct Interval arr[] = {
//            {1, 4},
//            {0, 2},
//            {3, 5}
//    };
//    struct Interval arr[] = {
//            {4, 5},
//            {1, 4},
//            {0, 1}
//    };
//    struct Interval arr[] = {
//            {2, 3},
//            {4, 5},
//            {6, 7},
//            {8, 9},
//            {1, 10}
//    };
//    struct Interval arr[] = {
//
//    };
//    struct Interval arr[] = {
//            {4, 5},
//            {2, 4},
//            {4, 6},
//            {3, 4},
//            {0, 0},
//            {1, 1},
//            {3, 5},
//            {2, 2}
//    };

    int size = 0;
    struct Interval *r = merge(arr, sizeof(arr) / sizeof(struct Interval), &size);

    for (int i = 0; i < size; ++i) {
        printf("[%d,%d]\n", r[i].start, r[i].end);
    }

    return 0;
}