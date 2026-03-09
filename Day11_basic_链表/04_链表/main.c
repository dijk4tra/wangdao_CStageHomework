#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct node_s {
    int data;
    // next指针，用于存储下一个节点的地址
    struct node_s *next;
}Node;

typedef struct node_s1 {
    int data;
    // Node1 *next;  // 在结构体内部一定不能用自己的别名
}Node1;

int main(void) {
    
    //Node n1;
    //Node.data

    //Node1 *next;

    //Node n1;
    //n1.data;

    Node1 n2;

    return 0;
}