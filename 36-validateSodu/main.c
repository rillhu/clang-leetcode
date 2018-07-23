#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>

bool isValidSudoku(char **board, int boardRowSize, int boardColSize) {
    //Using hash map to check if row array has duplication.
    int dup = 0;
    for (int i = 0; i < boardRowSize; ++i) {
        char arrAsc[58] = {0,};
        for (int j = 0; j < boardColSize; ++j) {
            if (board[i][j] == '.') {
                continue;
            } else if (arrAsc[board[i][j]] == 0) {
                arrAsc[board[i][j]] = (char) (j + 1);
            } else {
                dup = 1;
                break;
            }
        }
        if (dup == 1) break;
    }

    //Using hash map to check if column array has duplication.
    for (int i = 0; i < boardColSize; ++i) {
        char arrAsc[58] = {0,};
        for (int j = 0; j < boardRowSize; ++j) {
            if (board[j][i] == '.') {
                continue;
            } else if (arrAsc[board[j][i]] == 0) {
                arrAsc[board[j][i]] = (char) (j + 1);
            } else {
                dup = 1;
                break;
            }
        }
        if (dup == 1) break;
    }

    //9 small squares should not have duplication.
    int i = 0;
    int j = 0;
    for (int k = 0; k < 3; ++k) {
        for (int l = 0; l < 3; ++l) {
            char arrAsc[58] = {0,};
            for (i = 3 * k; i < 3 * (k + 1); ++i) {
                for (j = 3 * l; j < 3 * (l + 1); ++j) {
                    if (board[i][j] == '.') {
                        continue;
                    } else if (arrAsc[board[i][j]] == 0) {
                        arrAsc[board[i][j]] = (char) (i + 1);
                    } else {
                        dup = 1;
                        break;
                    }
                }
            }
        }
    }

    return (bool) (dup == 0) ? true : false;
}

int main() {
//    char arr[9][9] = {
//            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
//            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
//            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
//            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
//    };

    char arr[9][9] = {
            {'.', '.', '.', '.', '5', '.', '.', '1', '.'},
            {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
            {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
            {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
            {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
            {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
            {'.', '.', '4', '.', '.', '.', '.', '.', '.'}
    };

    int sodouSize = 9;
    char **sodu = (char **) malloc(sodouSize);
    for (int i = 0; i < sodouSize; ++i) {
        sodu[i] = (char *) malloc(sodouSize * sizeof(char));
        sodu[i] = arr[i];
    }

//    for (int j = 0; j < sodouSize; ++j) {
//        printf("%c,", sodu[0][j]);
//    }

    printf("%d", isValidSudoku(sodu, sodouSize, sodouSize));


    return 0;
}