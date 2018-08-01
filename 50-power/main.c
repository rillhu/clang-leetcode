#include <stdio.h>
#include <math.h>


//double myPow(double x, int n) {
//
//    if (n == 0)return 1;
//
//    int flag = 0;
//    int pad = 0;
//    if (n < 0) {
//        if (n == 0x80000000) {    //-2^31
//            n = 0x7FFFFFFF;     //2^31 -1
//            pad = 1;
//        }
//        n = -n;
//        flag = 1;
//    }
//
//    double res = 1;
//    while (n--) {
//        res = res * x;
//    }
//
//    if (pad == 1) {
//        res = res * x;
//    }
//
//    if (flag == 1) {
//        res = 1 / res;
//    }
//    return res;
//}


//ref: https://blog.csdn.net/up_junior/article/details/46553751
double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;

    double xCpy = x;

    //1. Handle n
    int flag = 0;
    int pad = 0;
    if (n == 0x80000000) {    //-2^31
        n = 0x7FFFFFFF;       //2^31 -1
        pad = 1;
        flag = 1;
    } else if (n < 0) {
        n = -n;
        flag = 1;
    }

    //2. fast N power
    double res = 1;
    while (n > 1) {
        if (n % 2 != 0) {
            res *= x;
        }
        x *= x;
        n /= 2;
    }

    //3. handle the result, if we have pad multiply one more time with x original(xCpy)
    double r = res * x;
    if (pad == 1) r = r * xCpy;

    return (flag == 1) ? 1 / r : r;
}

int main() {
//    double x = 2;
//    int n = 0x80000000;
//    printf("myP: %f\nstd: %f\n", myPow(x, n), pow(x, n));

    double x = -1;
    int n = -1024;
//    int n = 0x80000000;
    printf("myP: %f\nstd: %f\n", myPow(x, n), pow(x, n));
    return 0;
}