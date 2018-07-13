#include <stdio.h>

int reverse(int x) {
    int MAX_INT = 0x7FFFFFFF;
    int MIN_INT = 0x80000000;
    //printf("%d, %d\n", MAX_INT, MIN_INT);

    int sign = 0;
    if (x < 0) {
        if (x == 0x80000000) return 0;
        x = -x;
        sign = 1;
    }


    int res = 0;
    for (int i = 0; i < 12; ++i) {

        res += x % 10;
        x = x / 10;
        if (x == 0) break;

        if (res > 214748364) {   //cond 1 : >214748364=  0x7FFFFFFF / 10
            return 0;

        } else if (res == 214748364) {
            if (x % 10>7) {               //cond 2: still have high bit
                return 0;
            }
        }

//        if (res > 10 * (0x7FFFFFFF / 10)) {  //cond 1: 2147483640
//            if (x % 10 > 7) {                //cond 2: >7
//                return 0;
//            }
//        }


        res *= 10;
    }

    //printf("%d\n", res);

    if (sign) res = -res;
    return res;
}


int main() {
    int n1 = -2147483412;
    int n2 = 1534236469;
    int n3 = 1563847412;

    printf("rev: %d\n", reverse(n1));
    printf("rev: %d\n", reverse(n2));
    printf("rev: %d\n", reverse(n3));

    return 0;
}