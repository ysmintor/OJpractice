//
// Created by York on 2018/2/18.
//
#include <stdio.h>

int main(){
    int buf[200];
    int n;
    while (scanf("%d", &n) != EOF) {
        // 输入数据
        for (int i = 0; i < n; ++i) {
            scanf("%d", &buf[i]);
        }
        // 初始化答案为-1，以期在找不到答案时能正确输出-1
        int x, ans = -1;
        scanf("%d", &x);
        for (int i = 0; i < n; ++i) {
            if (x == buf[i]) {
                ans = i;
                break;
            }
        }

        printf("%d\n", ans);

    }
    return 0;
}