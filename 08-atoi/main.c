#include <stdio.h>
#include <mem.h>


int myAtoi(char *str) {
    int len = strlen(str);

    int j;
    for (j = 0; j < len; ++j) {
        if (str[j] != ' ') break;
    }

    if (j == len) return 0;

    int flag = 1;
    if (str[j] < '0' || str[j] > '9') {
        if (str[j] == '+') {
            j++;
        } else if (str[j] == '-') {
            flag = -1;
            j++;
        } else {
            return 0;
        }
    }

    int res = 0;
    for (int i = j; i < len; ++i) {
        if (str[i] < '0' || str[i] > '9') break;
        res += (str[i] - 0x30) * flag;
        if (i + 1 < len && str[i + 1] >= '0' && str[i + 1] <= '9') {
            switch (flag) {
                case 1:
                if (res > 214748364) {   //cond 1 : >214748364=  0x7FFFFFFF / 10
                    return 2147483647;
                } else if (res == 214748364) {
                    if (str[i + 1] > '7') {               //cond 2: still have high bit
                        return 2147483647;
                    }
                }
                break;
                case -1:
                    if (res < -214748364) {   //cond 1 : >214748364=  0x7FFFFFFF / 10
                        return -2147483648;
                    } else if (res == -214748364) {
                        if (str[i + 1] > '8') {               //cond 2: still have high bit
                            return -2147483648;
                        }
                    }
                    break;
            }
            res *= 10;
        }
    }

    //if (flag == -1) res = -res;
    return res;
}

int main() {

    char *strArray[] = {
            "42",
            "    -42",
            "4193 with words",
            "words and 987",
            "-91283472332",
            "-2147483648",
            "2147483646"
    };

    for (int i = 0; i < 7; ++i) {
        printf("%d\n", myAtoi(strArray[i]));
    }

    return 0;
}