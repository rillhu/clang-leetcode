#include <stdio.h>
#include <mem.h>
#include <stdlib.h>

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
char *intToRoman(int num) {
    char *roman = (char *) calloc(1, 128);

    char *thousand[] = {
            "XXX",
            "M",    //1000
            "MM",   //2000
            "MMM"   //3000
    };
    char *hundred[] = {
            "XXX",
            "C",    //100
            "CC",
            "CCC",
            "CD",
            "D",
            "DC",
            "DCC",
            "DCCC",
            "CM"   //900
    };
    char *decade[] = {
            "XXX",
            "X",    //10
            "XX",
            "XXX",
            "XL",
            "L",
            "LX",
            "LXX",
            "LXXX",
            "XC"    //90
    };
    char *single[] = {
            "XXX",
            "I",
            "II",
            "III",
            "IV",
            "V",
            "VI",
            "VII",
            "VIII",
            "IX"
    };

    if (num / 1000) {
        strcpy(roman, thousand[num / 1000]);
        num %= 1000;
    }
    if (num / 100) {
        strcpy(roman + strlen(roman), hundred[num / 100]);
        num %= 100;
    }
    if (num / 10) {
        strcpy(roman + strlen(roman), decade[num / 10]);
        num %= 10;
    }
    if (num) {
        strcpy(roman + strlen(roman), single[num]);
    }

    return roman;
}

int main() {

    char *p;

    for (int i = 2000; i < 2753; ++i) {

        p = intToRoman(i);
        printf("%d: %s\n", i, p);
    }
    free(p);
    return 0;
}