//
// Created by York on 2018/2/18.
// Description: 学生信息输入 二分查找
//

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;


struct Goods {
    // 表示可买物品的结构体
    double totalWeight; // 物品总重量
    double totalValue;  // 物品总价值
    double ratio;       // 性价比
    bool operator<(const Goods &A) const {
        return ratio > A.ratio;
    }
}buf[1000];

int main(){
    double money;

    int n;
    while (scanf("%lf%d", &money, &n) != EOF) {
        // 当n== -1 且m==-1时跳出循环，程序运行结束
        if (money == -1 && n == 1) break;
        // 输入学生成绩
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf", &buf[i].totalWeight,buf[i].name, buf[i].totalValue);
            // 计算性价比
            buf[i].ratio = buf[i].totalWeight / buf[i].totalValue;
        }
        // 排序 降序
        sort(buf, buf + n);

        int index=0;    // 当前货物下标
        double ans = 0;

        // 循环的条件为既有物品剩余还有钱剩余时继续循环
        while (money>0&&index<n) {
            if (money > buf[index].ratio) {
                ans+=buf[index].totalWeight;
                money-=buf[index].totalValue;
            } else {
                // 只够买部份商品
                ans += buf[index].totalWeight * money/buf[index].totalValue;
                // 剩余的钱已经用完直接归零
                money = 0;
            }

            }
            if (ans == -1) {
                // 查找失败
                printf("No Answer! \n");
            } else
                // 查找成功
                printf("%s  %s  %s  %d\n", buf[ans].no, buf[ans].name, buf[ans].sex, buf[ans].age);
        }
        return 0;
    }
}
