#include <stdio.h>
#include <algorithm>

//
// Created by York on 2018/2/7.
//

int main(){
    int n;
    int buf[10000];
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &buf[i]);
        }
        std::sort(buf, buf + n);

        for (int i = 0; i < n; ++i) {
            printf("%d ", buf[i]);
        }
        printf("\n");
    }
    return 0;
}
