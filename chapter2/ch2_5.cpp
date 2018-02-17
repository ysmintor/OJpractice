//
// Created by York on 2018/2/8.
//
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct E{
    char name[101];
    int age;
    int score;
    bool operator < (const E &b) const {
        // 实现比较规则
        if (score != b.score) return score < b.score;

        int tmp = strcmp(name, b.name);
        if (tmp != 0)
            return tmp < 0;
        else
            return age < b.age;
    }
}buf[1000];


int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%s%d%d", buf[i].name, &buf[i].age, &buf[i].score);
        }

        sort(buf, buf + n);
        for (int i = 0; i < n; ++i) {
            printf("%s  %d  %d\n", buf[i].name, buf[i].age, buf[i].score);
        }
    }
    return 0;
}