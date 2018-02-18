//
// Created by York on 2018/2/18.
//
#include <stdio.h>
#define OFFSET 500000
int Hash[1000001];

int main(){
    int n,m;
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = -500000; i < 500000; ++i) {
            Hash[i + OFFSET] = 0;   //初始化，将每个数字都标记为未出现
        }

        for (int j = 0; j < n; ++j) {
            int x;
            scanf("%d", &x);
            Hash[x + OFFSET] = 1;
        }

        for (int i = 500000; i >= -500000; i--) {
            if (Hash[i + OFFSET] == 1) {
                printf("%d", i);
                m--;
                if (m!=0) printf(" ");//输入空格
                else {
                    printf("\n");
                    break;
                }
            }
        }
    }
    return 0;
}
