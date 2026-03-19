#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
给定一条单链表，请反转这条单链表。
举例：
输入: 1 --> 2 --> 3
输出: 3 --> 2 --> 1

基于以下函数的声明实现：
Node* reverse(Node *list); // 反转当前单链表并返回新的头指针

注意：
请采用循环迭代求解这个问题。递归可以看一下，可以选择不使用递归实现。
*/

typedef struct node {
    int data;
    struct node *next;
}Node;

// 函数：创建新结点
Node *create_node(int val) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("malloc failed in create_node.");
        return NULL;
    }

    new_node->data = val;
    new_node->next = NULL;
    
    return new_node;
}

// 函数：打印链表
void print_list(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

Node *reverse(Node *list) {
    Node *prev = NULL; // 指向当前节点的前一个，初始化为 NULL（原头变尾）
    Node *curr = list; // 指向当前正在处理的节点
    Node *next = NULL; // 用于备份下一个节点
    
    while (curr != NULL) {
        // 备份：在修改指针指向前，先记住下一个节点在哪
        next = curr->next;
        // 反转：将当前节点的next指向它的前驱节点
        curr->next = prev;
        // prev和curr同时向后移动一位，准备处理下一个结点
        prev = curr;    // prev 移动到当前节点
        curr = next;    // curr 移动到备份好的原下一个节点
    }
    // 当curr为NULL时，说明处理完了最后一个节点，此时prev指向原链表的尾结点
    // 这个尾结点就是新链表的头结点
    return prev;
}


int main(void) {
    
    // 构造链表1 -> 2 -> 3 -> NULL
    Node *head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);

    printf("原链表：");
    print_list(head);

    head = reverse(head);

    printf("反转后的新链表：");
    print_list(head);

    // 释放内存
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}