#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
合并两条有序的单向链表，使得合并后的链表也是有序的 (要求: 不能额外申请堆内存空间)。

输入：
   list1: 1 --> 3 --> 5
   list2: 2 --> 4 --> 6

输出：
   1 --> 2 --> 3 --> 4 --> 5 -->6

函数声明可以直接写:
Node* merge_two_lists(Node* list1, Node* list2);
请采用循环迭代求解这个问题。递归可以看一下，可以选择不使用递归实现。

注：循环实现时，可以思考一下加头结点的实现与不加的区别。
不仅要定义函数实现对应功能，还需要编写测试用例，进行测试。
*/

typedef struct node {
    int data;
    struct node *next;
}Node;

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


Node *merge_two_lists(Node *list1, Node *list2) {
    // 定义一个哨兵节点
    Node dummy;
    dummy.next = NULL;

    // cur 始终指向合并链表的当前末尾
    Node *cur = &dummy;

    // 只要两个链表都不为空，就进行比较
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            cur->next = list1;     // 把较小的结点接到合并链表的末尾
            list1 = list1->next;   // 把list1后移
        }
        else {
            cur->next = list2;     // 把较小的结点接到合并链表的末尾
            list2 = list2->next;   // 把list2后移
        }
        cur = cur->next;           // 更新合并链表的末尾指针
    }

    // 若还有链表不为空，直接把非空链表的剩余部分接到合并链表的末尾即可
    if (list1 != NULL) {
        cur->next = list1;
    }
    if (list2 != NULL) {
        cur->next = list2;
    }

    // 返回哨兵节点的下一个节点，即真正的合并链表的头节点
    return dummy.next;
}

int main(void) {
    
    Node *list1_head = create_node(1);
    list1_head->next = create_node(3);
    list1_head->next->next = create_node(5);

    Node *list2_head = create_node(2);
    list2_head->next = create_node(4);
    list2_head->next->next = create_node(6);

    printf("链表一：");
    print_list(list1_head);
    printf("链表二：");
    print_list(list2_head);

    Node *result_list_head = merge_two_lists(list1_head, list2_head);
    printf("合并得到的有序链表：");
    print_list(result_list_head);

    // 释放内存
    while (result_list_head != NULL) {
        Node *temp = result_list_head;
        result_list_head = result_list_head->next;
        free(temp);
    }

    return 0;
}