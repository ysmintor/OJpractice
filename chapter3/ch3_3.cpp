//
// Created by York on 2018/2/21.
// Description: 求哈夫曼树的带权路径长度
//
#include <queue>
#include <stdio.h>

using namespace std;
priority_queue<int, vector<int>, greater<int>> Q;   // 建立一个小顶堆
int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        while (Q.empty() == false) Q.pop(); // 清空堆中元素
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            Q.push(x);  // 将权值放入堆中
        }

        int ans = 0;
        while (Q.size() > 1) {
            // 取出堆中最小的两个元素
            int a = Q.top();
            Q.pop();
            int b = Q.top();
            Q.pop();

            ans += a + b;
            Q.push(a + b);
        }

        printf("WPL = %d", ans);
    }

    return 0;
};