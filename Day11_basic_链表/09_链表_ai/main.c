#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct node_s {
    DataType data;
    struct node_s *next;
} Node;

// 创建新节点（辅助函数）
Node *createNode(DataType data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败！\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void destroyList(Node *head);

// 创建链表（通过数组创建）
Node *createList(DataType arr[], int n) {
    if (n <= 0) return NULL;

    Node *head = createNode(arr[0]);
    if (head == NULL) return NULL;

    Node *current = head;
    for (int i = 1; i < n; i++) {
        current->next = createNode(arr[i]);
        if (current->next == NULL) {
            // 如果创建失败，需要清理已创建的节点
            destroyList(head);
            return NULL;
        }
        current = current->next;
    }

    return head;
}

// 销毁链表
void destroyList(Node *head) {
    Node *current = head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    printf("链表已销毁\n");
}

// 打印链表
void printList(Node *head) {
    if (head == NULL) {
        printf("链表为空\n");
        return;
    }

    Node *current = head;
    printf("链表内容: ");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

// 头插法
Node *insertAtHead(Node *head, DataType data) {
    Node *newNode = createNode(data);
    if (newNode == NULL) return head;

    newNode->next = head;
    return newNode;
}

// 尾插法
Node *insertAtTail(Node *head, DataType data) {
    Node *newNode = createNode(data);
    if (newNode == NULL) return head;

    // 如果链表为空
    if (head == NULL) {
        return newNode;
    }

    // 找到最后一个节点
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;

    return head;
}

// 中间插（在指定位置插入，位置从0开始）
Node *insertAtPosition(Node *head, DataType data, int position) {
    // 如果位置是0，相当于头插
    if (position == 0) {
        return insertAtHead(head, data);
    }

    Node *newNode = createNode(data);
    if (newNode == NULL) return head;

    // 找到要插入位置的前一个节点
    Node *current = head;
    int i = 0;

    // 遍历到 position-1 位置
    while (current != NULL && i < position - 1) {
        current = current->next;
        i++;
    }

    // 如果当前位置无效
    if (current == NULL) {
        printf("插入位置 %d 无效！\n", position);
        free(newNode);
        return head;
    }

    // 插入新节点
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

// 按值删除（删除第一个匹配的节点）
Node *deleteByValue(Node *head, DataType value) {
    if (head == NULL) {
        printf("链表为空，无法删除\n");
        return NULL;
    }

    // 如果要删除的是头节点
    if (head->data == value) {
        Node *temp = head;
        head = head->next;
        free(temp);
        printf("已删除值为 %d 的节点\n", value);
        return head;
    }

    // 查找要删除的节点
    Node *current = head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }

    // 如果找到了要删除的节点
    if (current->next != NULL) {
        Node *temp = current->next;
        current->next = temp->next;
        free(temp);
        printf("已删除值为 %d 的节点\n", value);
    }
    else {
        printf("未找到值为 %d 的节点\n", value);
    }

    return head;
}

// 按索引删除（位置从0开始）
Node *deleteByIndex(Node *head, int index) {
    if (head == NULL) {
        printf("链表为空，无法删除\n");
        return NULL;
    }

    // 删除头节点
    if (index == 0) {
        Node *temp = head;
        head = head->next;
        free(temp);
        printf("已删除索引 %d 的节点\n", index);
        return head;
    }

    // 找到要删除节点的前一个节点
    Node *current = head;
    int i = 0;

    while (current->next != NULL && i < index - 1) {
        current = current->next;
        i++;
    }

    // 检查索引是否有效
    if (current->next == NULL) {
        printf("索引 %d 无效！\n", index);
        return head;
    }

    // 删除节点
    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    printf("已删除索引 %d 的节点\n", index);

    return head;
}

// 获取链表长度
int getLength(Node *head) {
    int length = 0;
    Node *current = head;

    while (current != NULL) {
        length++;
        current = current->next;
    }

    return length;
}

// 测试函数
int main() {
    printf("=== 链表操作测试 ===\n\n");

    // 1. 创建链表
    printf("1. 创建链表\n");
    DataType arr[] = { 10, 20, 30, 40, 50 };
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *list = createList(arr, n);
    printf("初始链表: ");
    printList(list);
    printf("链表长度: %d\n\n", getLength(list));

    // 2. 头插测试
    printf("2. 头插法插入 5\n");
    list = insertAtHead(list, 5);
    printList(list);
    printf("\n");

    // 3. 尾插测试
    printf("3. 尾插法插入 60\n");
    list = insertAtTail(list, 60);
    printList(list);
    printf("\n");

    // 4. 中间插测试
    printf("4. 在位置3插入 25\n");
    list = insertAtPosition(list, 25, 3);
    printList(list);
    printf("\n");

    // 5. 按值删除测试
    printf("5. 按值删除 30\n");
    list = deleteByValue(list, 30);
    printList(list);
    printf("\n");

    // 6. 按索引删除测试
    printf("6. 按索引删除位置2的节点\n");
    list = deleteByIndex(list, 2);
    printList(list);
    printf("\n");

    // 7. 边界测试
    printf("7. 边界测试：头插和尾插\n");
    list = insertAtHead(list, 1);
    list = insertAtTail(list, 100);
    printList(list);
    printf("\n");

    // 8. 销毁链表
    printf("8. 销毁链表\n");
    destroyList(list);
    list = NULL;
    printList(list);

    return 0;
}