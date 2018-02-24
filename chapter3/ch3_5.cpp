//
// Created by York on 2018/2/24.
// Description: 建立二叉排序树，并输出前序，中序，后序遍历
//

#include <stdio.h>
#include <string.h>

struct Node {
    Node *lchild;
    Node *rchild;
    int c;         // 结点字符信息
} Tree[50];

int loc;            // 静态内存分配数组
Node *create() {
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

void postOrder(Node *T) {
    if (T->lchild != NULL) {    // 若左子树不空，递归遍历其左子树
        postOrder(T->lchild);
    }
    if (T->rchild != NULL) {
        postOrder(T->rchild);   //  若右子树不空，递归遍历其右子树
    }
    printf("%d", T->c);         // 遍历该结点，输出其字符信息
}

void inOrder(Node *T) {
    if (T->lchild != NULL) {    // 若左子树不空，递归遍历其左子树
        inOrder(T->lchild);
    }
    printf("%d", T->c);         // 遍历该结点，输出其字符信息
    if (T->rchild != NULL) {
        inOrder(T->rchild);   //  若右子树不空，递归遍历其右子树
    }
}

void preOrder(Node *T) {
    printf("%d", T->c);         // 遍历该结点，输出其字符信息
    if (T->lchild != NULL) {    // 若左子树不空，递归遍历其左子树
        preOrder(T->lchild);
    }
    if (T->rchild != NULL) {
        preOrder(T->rchild);   //  若右子树不空，递归遍历其右子树
    }
}

Node *Insert(Node *T, int x) {
    if (T == NULL) {
        T = create();             // 建立结点
        T->c = x;
        return T;
    } else if (x < T->c)        // 若x小于根结点数值
        T->lchild = Insert(T->lchild, x);
    else if (x > T->c)         // 若x大于根结点数值
        T->rchild = Insert(T->rchild, x);

    return T;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        loc = 0;
        Node *T = NULL;
        // 建树
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            T = Insert(T, x);
        }

        // 几种遍历输出

        preOrder(T);
        printf("\n");

        inOrder(T);
        printf("\n");

        postOrder(T);
        printf("\n");
    }
}