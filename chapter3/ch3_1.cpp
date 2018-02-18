//
// Created by York on 2018/2/18.
// Description: 栈的应用
//
#include <stdio.h>
#include <stack>
using namespace std;

stack<int> mStack;

char str[110];
char ans[110];

int main(){
    while (scanf("%s", str) != EOF) {
        int i;
        for (i = 0; str[i] !=0 ; ++i) {
            if(str[i] == '(') {   // 遇到左括号
                mStack.push(i); // 存放该数组下标到栈中
                ans[i] = ' ';   // 暂且将对应的输出字符串位置改为空格
            } else if (str[i] == ')') {
                if (mStack.empty() == false) {
                    // 栈非空
                    // 栈顶位置左括号与其匹配，从栈中弹出该已经匹配的左括号并修改输出中该位置为空格
                    mStack.pop();
                    ans[i] = ' ';
                } else
                    // 栈为空时说明 无法找到左括号与其匹配，修改输出中该位置为?
                    ans[i] = '?';
            } else ans[i] = ' ';    // 其它字符时与括号匹配无关，则修改输出为空格
        }

        while (!mStack.empty()) {
            // 当字符串遍历完成后，尚留栈中的左括号无法匹配
            ans[mStack.top()] = '$';
            mStack.pop();
        }


        ans[i] = 0; // 字符中结尾
        puts(str);
        puts(ans);
    }
    return 0;
}