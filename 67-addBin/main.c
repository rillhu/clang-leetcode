#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

//输入: a = "1010", b = "1011"
//输出: "10101"

char *addBinary(char *a, char *b) {
    int lenA = strlen(a);
    int lenB = strlen(b);


    int lenNew = (lenA > lenB) ? lenA : lenB;
    int len = lenNew;
    int idA = lenA - 1;
    int idB = lenB - 1;
    char t = 0;

    char *str = (char *)calloc(1, len+1);
    if(lenA>lenB){
        memcpy(str,a,lenA);
    } else{
        memcpy(str,b,lenB);
    }

    lenNew -= 1;

    while (idA >= 0 && idB >= 0) {
        str[lenNew] = a[idA] - '0' + b[idB] - '0' + t;
        t = str[lenNew] / 2;
        str[lenNew] %= 2;
        str[lenNew] += '0';

        lenNew--;
        idA--;
        idB--;
    }

    while (idA >= 0) {
        str[idA] -= '0';
        str[idA] += t;
        t = str[idA] / 2;
        str[idA] %= 2;
        str[idA] += '0';
        idA--;
    }
    while (idB >= 0) {
        str[idB] -= '0';
        str[idB] += t;
        t = str[idB] / 2;
        str[idB] %= 2;
        str[idB] += '0';
        idB--;
    }

    char *res;

    if (t > 0) {
        res = (char *) calloc(1, len + 1 + 1);
        res[0] = t + '0';
        memcpy(res + 1, str, len);
    } else {
        res = (char *) calloc(1, len + 1);
        memcpy(res, str, len);
    }

    return  res;

}

int main() {

//    char *a = "1010";
//    char *b = "1011";
//    char *a = "11";
//    char *b = "1";

    char *a = "1";
    char *b = "1101100";
    printf("%s\n", addBinary(a, b));
    return 0;
}