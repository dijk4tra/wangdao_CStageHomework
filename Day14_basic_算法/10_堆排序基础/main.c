#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct node_s {
	int data;
	struct node_s *left;
	struct node_s *right;
}Node;

int main(void) {

	// 树（Tree）：一对多的非线性结构。
	// 二叉树（Binary Tree）：每个节点最多只能有两个“后继”（孩子），分别叫左孩子和右孩子。
	// 堆（Heap）：一种特殊的完全二叉树，通常为了节省空间，会用连续的“数组”来模拟存储。

	return 0;
}