#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
基于以下链表结点结构体类型的定义:
typedef int ElementType;
typedef struct node {
 int data;
 struct node* next;
} Node;
在main函数中定义一个head头指针等于NULL代表此时单链表为空：

Node *head = NULL;
利用二级指针语法实现以下函数：

// 头插法新增一个结点
void insert_head(Node** head, ElementType new_val);
// 修改第一个结点的元素值，如果链表为空，则用new_val初始化第一个结点
void modify_first_node(Node** head, int new_val);
// 尾插法新增一个结点
void insert_tail(Node** head, ElementType new_val);
// 打印单链表 格式为：1 -> 2 -> 3 ->...
void print_list(Node *head);
注：尾插法会稍微麻烦一些，可以放在最后实现。
*/

typedef int ElementType;
typedef struct node {
    int data;
    struct node *next;
} Node;


Node *create_node(ElementType val) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("内存分配失败！\n");
        return NULL;
    }
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}

// 头插法新增一个结点
void insert_head(Node **head, ElementType new_val) {
    Node *new_node = create_node(new_val);
    if (new_node == NULL) return;
    // 将新结点的 next 指向当前的头结点
    new_node->next = *head;
    // 更新头指针
    *head = new_node;
}

// 修改第一个结点的元素值，如果链表为空，则用new_val初始化第一个结点
void modify_first_node(Node **head, int new_val) {
    if (*head == NULL) {
        // 如果链表为空，利用头插法初始化第一个结点
        insert_head(head, new_val);
    }
    else {
        // 如果不为空，直接修改第一个结点的data域即可
        (*head)->data = new_val;  // 注意必须要打括号！解引用*的优先级很低！
    }
}

// 尾插法新增一个结点
void insert_tail(Node **head, ElementType new_val) {
    Node *new_node = create_node(new_val);
    if (new_node == NULL) return;

    if (*head == NULL) {
        // 链表为空，尾插就是头插
        *head = new_node;
    }
    else {
        // 链表不为空，需要找到尾结点
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        } // 移动到最后一个结点
        temp->next = new_node;
    }
}

// 打印单链表 格式为：1 -> 2 -> 3 ->...
void print_list(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        printf("%d", curr->data);
        if (curr->next != NULL) {  
            printf(" -> ");   // 当前结点不是最后一个结点时，打印箭头
        }
        curr = curr->next;
    }
    printf("\n");
}


int main(void) {
    Node *head = NULL; // 初始化空链表

    printf("头插20，10: ");
    insert_head(&head, 20);
    insert_head(&head, 10);
    print_list(head);

    printf("修改首结点为30: ");
    modify_first_node(&head, 30);
    print_list(head);

    printf("尾插40，80: ");
    insert_tail(&head, 40);
    insert_tail(&head, 80);
    print_list(head);

    printf("修改首结点为10: ");
    modify_first_node(&head, 10);
    print_list(head);

    return 0;
}