#include <stdio.h>


int trap(int *height, int heightSize) {
    int l = 0;
    int r = heightSize - 1;

    int hlMax = height[l]; //left height max
    int hrMax = height[r]; //right height max

    int vol = 0; //rain water trapping volume

    while (l != r) {
        hlMax = (hlMax >= height[l]) ? hlMax : height[l];
        hrMax = (hrMax >= height[r]) ? hrMax : height[r];
        if (hlMax < hrMax) {
            vol += hlMax - height[l];
            l++;
        } else {
            vol += hrMax - height[r];
            r--;
        }
    }
    return vol;
}

//int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

int height[] = {4,2,0,3,2,5};

int main() {
    printf("Vol: %d\n", trap(height, sizeof(height) / sizeof(int)));
    return 0;
}
