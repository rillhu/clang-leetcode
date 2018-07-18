#include <stdio.h>
#include <mem.h>

/*
 I             1
V             5
 X             10
L             50
 C             100
D             500
M             1000

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
*/

int romanToInt(char *s) {
    int num = 0;

    while (*s != '\0') {
        switch (*s) {
            case 'I':
                if (*(s + 1) == 'V') {
                    num += 4;
                    s++;
                } else if (*(s + 1) == 'X') {
                    num += 9;
                    s++;
                } else {
                    num += 1;
                }
                break;
            case 'X':
                if (*(s + 1) == 'L') {
                    num += 40;
                    s++;
                } else if (*(s + 1) == 'C') {
                    num += 90;
                    s++;
                } else {
                    num += 10;
                }
                break;
            case 'C':
                if (*(s + 1) == 'D') {
                    num += 400;
                    s++;
                } else if (*(s + 1) == 'M') {
                    num += 900;
                    s++;
                } else {
                    num += 100;
                }
                break;
            case 'V':
                num += 5;
                break;
            case 'L':
                num += 50;
                break;
            case 'D':
                num += 500;
                break;
            case 'M':
                num += 1000;
                break;
            default:
                printf("Unknown symbol\n");
                break;
        }
        s++;
    }


    return num;

}


int main() {

    char *roman[] = {
            "III",//3
            "IV",//4
            "IX",//9
            "LVIII",//58
            "MCMXCIV"//1994
    };

    for (int i = 0; i < 5; ++i) {
        printf("%d\n", romanToInt(roman[i]));
    }
    return 0;
}