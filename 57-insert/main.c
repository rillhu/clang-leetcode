#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

struct Interval {
    int start;
    int end;
};

struct Interval *insert(struct Interval *intervals, int intervalsSize, struct Interval newInterval, int *returnSize) {

    //if (intervalsSize == 0) return NULL;

    int k = 0;
    while (k < intervalsSize && intervals[k].start < newInterval.start) {

        k++;

    }

    struct Interval *newIntervals = (struct Interval *) calloc(intervalsSize + 1, sizeof(struct Interval));

    if (k == 0) {
        newIntervals[0] = newInterval;
        memcpy(newIntervals + 1, intervals, intervalsSize * sizeof(struct Interval));
    } else {
        memcpy(newIntervals, intervals, k * sizeof(struct Interval));
        newIntervals[k] = newInterval;
        memcpy(newIntervals + k + 1, intervals + k, (intervalsSize - k) * sizeof(struct Interval));
    }

    intervalsSize += 1;

    struct Interval *res = (struct Interval *) calloc(intervalsSize, sizeof(struct Interval));

    int i = 0;
    int resId = 0;
    while (i < intervalsSize) {
        if (newIntervals[i].start == -1 &&
            newIntervals[i].end == 0) { //Invalid interval, using [-1, 0] as the magic word
            i++;
            continue;
        }
        res[resId] = newIntervals[i];
        for (int j = i + 1; j < intervalsSize; ++j) {
            if (newIntervals[j].start == -1 &&
                newIntervals[j].end == 0) { //Invalid interval, using [-1, 0] as the magic word
                continue;
            }
            if ((res[resId].end < newIntervals[j].start) || (res[resId].start > newIntervals[j].end)) {  //No overlap

            } else if (res[resId].end >= newIntervals[j].start && res[resId].end <= newIntervals[j].end &&
                       res[resId].start <= newIntervals[j].start) { //overlap type 1: [1,3], [2,6]
                res[resId].end = newIntervals[j].end;

                newIntervals[j].start = -1;
                newIntervals[j].end = 0;
            } else if (res[resId].end >= newIntervals[j].start && res[resId].end >= newIntervals[j].end &&
                       res[resId].start <= newIntervals[j].start) { //overlap type 2: [1,7], [2,6]
                newIntervals[j].start = -1;
                newIntervals[j].end = 0;
            }
        }
        i++;
        resId++;
    }

    *returnSize = resId;
    return res;

}

int main() {

//    struct Interval arr[] = {
//            {1,  3},
//            {2,  6},
//            {8,  10},
//            {15, 18}
//    };
    struct Interval newArr;// = {
            //1,  20
    //};
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
    struct Interval arr[] = {

    };
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
    struct Interval *r = insert(arr, sizeof(arr) / sizeof(struct Interval), newArr, &size);

    for (int i = 0; i < size; ++i) {
        printf("[%d,%d]\n", r[i].start, r[i].end);
    }

    return 0;
}