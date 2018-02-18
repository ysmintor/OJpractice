//
// Created by York on 2018/2/18.
// Description: 学生信息输入 二分查找
//

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;


struct Student {
    // 学生结构体
    char no[100];   // 学号
    char name[100]; // 姓名
    int age;        // 年龄
    char sex[15];   // 性别
    bool operator<(const Student &A) const {
        return strcmp(no, A.no) < 0;
    }
}buf[1000];

int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        // 输入学生成绩
        for (int i = 0; i < n; ++i) {
            scanf("%s%s%s%d", buf[i].no,buf[i].name, buf[i].sex, &buf[i].age);
        }
        // 排序 升序
        sort(buf, buf + n);

        // t组询问
        int t;
        scanf("%d", &t);
        while (t-- != 0) {
            int ans = -1;
            char x[30];

            // 输入待查学号
            scanf("%s", x);
            int top = n -1, base = 0;

            // 初始时，开始下标为0， 结束下标n-1, 查找子集为整个数组

            while (top >= base) {
                int mid = (top + base) / 2;
                int tmp = strcmp(buf[mid].no, x);

                if (tmp == 0) {
                    // 找到
                    ans = mid;
                    // 跳出查找
                    break;
                } else if (tmp > 0) top = mid - 1;
                else
                    base = mid + 1;
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
