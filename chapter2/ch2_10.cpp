//
// Created by York on 2018/2/18.
// 排版题
#include <stdio.h>

int main() {
    int h;
    while (scanf("%d", &h) != EOF) {
        int maxLine = h + (h - 1) * 2; // 计算最后一行包含的星号个数

        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= maxLine ; ++j) {
                if (j < maxLine - (h + ( i - 1) * 2) + 1)
                    printf(" ");
                else
                    // 输出星号
                    printf("*");
            }
            // 输出换行
            printf("\n");
        }

    }
    return 0;
}

