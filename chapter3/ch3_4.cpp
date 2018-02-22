//
// Created by York on 2018/2/22.
// Description: 二叉树前序与中序构建二叉树并输出后序遍历
// 采用递归方式构建二叉树
//
#include <stdio.h>
#include <string.h>

struct Node {
    Node *lchild;
    Node *rchild;
    char c;         // 结点字符信息
}Tree[50];

int loc;            // 静态内存分配数组
Node *create(){
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

char str1[30], str2[30];    // 保存前序和遗弃遍历结果字符串
void postOrder(Node *T){
    if (T->lchild != NULL) {    // 若左子树不空，递归遍历其左子树
        postOrder(T->lchild);
    }
    if (T->rchild != NULL) {
        postOrder(T->rchild);   //  若右子树不空，递归遍历其右子树
    }
    printf("%c", T->c);         // 遍历该结点，输出其字符信息
}

Node *build(int s1, int e1, int s2, int e2){
    // 字符串的前序遍历和中序遍历还原树，并返回其根结点，其中前序遍历结果为由str1[s1]到str2[e1]，中序遍历结果为str2[s2]到str2[e2]
    Node *ret = create();   // 为该树根结点申请空间
    ret->c = str1[s1];      // 该结点字符为前序遍历中的第一个字符
    int rootIdx;
    for (int i = s2; i <= e2; ++i) {
        if (str2[i] == str1[s1]) {
            rootIdx = i;
            break;          // 找到中序遍历中的index，并跳出循环
        }
    }

    if (rootIdx != s2) {
        // 左子树不为空
        // 递归还原其左子树
        ret->lchild = build(s1 + 1, s1 + (rootIdx - s2), s2, rootIdx - 1);
    }

    if (rootIdx != e2) {
        // 右子树不为空
        // 递归还原其右子树
        ret->rchild = build(s1 + (rootIdx - s2) + 1, e1, rootIdx + 1, e2);
    }

    return ret;     // 返回根结点指针
}


int main(){
    while (scanf("%s", str1) != EOF) {
        scanf("%s", str2);

        loc = 0;    // 初始化静态内存空间中已经使用结点个数为0
        // 计算两个字符串长度
        int L1 = strlen(str1);
        int L2 = strlen(str2);

        Node *T = build(0, L1 - 1, 0, L2 - 1);
        postOrder(T);   // 后序遍历
        printf("\n");   // 输出换行
    }
    return 0;
}


