#include <stdio.h>
#include <stdlib.h>

//将两数相除，要求不使用乘法、除法和 mod 运算符。
//int divide(int dividend, int divisor) {
//
//    if(divisor == 1) return  dividend;
//    if(divisor == -1) {
//
//        if(dividend==0x80000000){
//            return 0x7FFFFFFF;
//        }
//        else {
//            return -dividend;
//        }
//    }
//
//    int flag = 1;
//    int i = 0;
//    if (dividend >= 0 && divisor > 0) {
//        while (dividend >= divisor) {
//            i++;
//            dividend -= divisor;
//        }
//    } else if (dividend >= 0 && divisor < 0) {
//        if (divisor == 0x80000000) return 0;//-2^31
//        divisor = -divisor;
//        while (dividend >= divisor) {
//            i++;
//            dividend -= divisor;
//        }
//        flag = -1;
//    } else if (dividend < 0 && divisor > 0) {
//        int adder = 0;
//        if (dividend == 0x80000000) {
//            adder = 1;
//            dividend = 0x7FFFFFFF;
//        } else {
//            dividend = -dividend;
//        }
//
//        while (dividend >= divisor) {
//            i++;
//            dividend -= divisor;
//        }
//
//        dividend += adder;
//        if (dividend >= divisor) i++;
//
//        flag = -1;
//    } else {
//        int adder1 = 0;
//        if (dividend == 0x80000000) {
//            //if (divisor == -1) return 0x7FFFFFFF;
//            dividend = 0x7FFFFFFF;
//            adder1 = 1;
//        } else {
//            dividend = -dividend;
//        }
//
//        int adder2 = 0;
//        if (divisor == 0x80000000) {
//            divisor = 0x7FFFFFFF;
//            adder2 = 1;
//        } else {
//            divisor = -divisor;
//        }
//
//        while (dividend >= divisor) {
//            i++;
//            dividend = dividend - divisor - adder2;
//        }
//
//        dividend += adder1;
//        if (dividend - divisor >= adder2) i++;
//    }
//
//    return i * flag;
//}

int divide(int dividend, int divisor) {
    if (divisor == 1) {
        return dividend;
    } else if (divisor == -1) {
        if (dividend == 0x80000000) {
            return 0x7FFFFFFF;
        } else {
            return -dividend;
        }
    } else if (divisor == 0x80000000) {
        if (dividend == 0x80000000) return 1;
        else return 0;
    }

    int flag = 1;
    int adder = 0;

    if ((dividend >= 0 && divisor > 0)) {
        /*Do nothing*/

    } else if (dividend >= 0 && divisor < 0) {
        divisor = -divisor;
        flag = -1;

    } else if (dividend < 0 && divisor > 0) {
        if (dividend == 0x80000000) {
            adder = 1;
            dividend = 0x7FFFFFFF;
        } else {
            dividend = -dividend;
        }

        flag = -1;
    } else {
        if (dividend == 0x80000000) {
            adder = 1;
            dividend = 0x7FFFFFFF;
        } else {
            dividend = -dividend;
        }

        divisor = -divisor;
    }

    int end = dividend;
    int divOut = divisor;
    int res = 0;
    while (end >= divOut) {
        int div = divOut;
        int cnt = 1;
        while ((div << 1) < end) {
            if (div >= 0x3FFFFFF) {
                break; //avoid div overflow
            }
            div <<= 1;
            cnt <<= 1;

        }
        res += cnt;    //2+4+8+16+...+cnt^2
        end -= div;    //minus cnt^2 div as cnt increasing
        if (adder == 1) {
            end += adder;
            adder = 0;
        }
    }

    if (flag == -1) res = -res;
    return res;
}


int main() {


    printf("%d\n", divide(10, 3));      //3
    printf("%d\n", divide(0x7FFFFFFF, 3));//715827882
    printf("%d\n", divide(7, -3));          //-2
    printf("%d\n", divide(100, 3));     //33
    printf("%d\n", divide(100, -100));  //-1
    printf("%d\n", divide(100, -3));    //-33
    printf("%d\n", divide(0x7FFFFFFF, -3)); //-715827882
    printf("%d\n", divide(0x7FFFFFFF, 0x80000000)); //0
//
//
    printf("%d\n", divide(0x80000000, 0x80000000)); //1
    printf("%d\n", divide(0x80000000, 3));
    printf("%d\n", divide(0x80000000, -3));
    printf("%d\n", divide(-1, -1));
    printf("%d\n", divide(1100540749, -1090366779));


//    int jj = 0x80000000;
//    printf("%d\n", jj);
//    jj = 0x7FFFFFFF;
//    printf("%d\n", jj);


    return 0;
}