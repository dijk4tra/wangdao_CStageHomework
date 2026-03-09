#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 1. 基础结构定义
typedef int DataType;

typedef struct node_s {
    DataType data;
    struct node_s *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

// --- 内部辅助函数：创建新节点 ---
static Node *_createNode(DataType val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败！\n");
        return NULL;
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// 2. 创建链表（初始化封装结构）
LinkedList *createList() {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if (list) {
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
    }
    return list;
}

// 3. 打印链表
void printList(LinkedList *list) {
    if (!list || list->size == 0) {
        printf("链表为空\n");
        return;
    }
    Node *curr = list->head;
    printf("List (Size %d): ", list->size);
    while (curr) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// 4. 插入操作
// 头插
void insertAtHead(LinkedList *list, DataType val) {
    Node *newNode = _createNode(val);
    if (!newNode) return;

    newNode->next = list->head;
    list->head = newNode;

    if (list->size == 0) {
        list->tail = newNode;
    }
    list->size++;
}

// 尾插
void insertAtTail(LinkedList *list, DataType val) {
    Node *newNode = _createNode(val);
    if (!newNode) return;

    if (list->size == 0) {
        list->head = list->tail = newNode;
    }
    else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

// 按索引插入 (index 从 0 开始)
void insertAtIndex(LinkedList *list, int index, DataType val) {
    if (index < 0 || index > list->size) {
        printf("插入索引 %d 越界\n", index);
        return;
    }
    if (index == 0) {
        insertAtHead(list, val);
        return;
    }
    if (index == list->size) {
        insertAtTail(list, val);
        return;
    }

    Node *newNode = _createNode(val);
    Node *prev = list->head;
    for (int i = 0; i < index - 1; i++) {
        prev = prev->next;
    }
    newNode->next = prev->next;
    prev->next = newNode;
    list->size++;
}

// 5. 删除操作
// 按索引删除
void deleteByIndex(LinkedList *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("删除索引 %d 越界\n", index);
        return;
    }

    Node *target = NULL;
    if (index == 0) {
        target = list->head;
        list->head = target->next;
        if (list->size == 1) list->tail = NULL;
    }
    else {
        Node *prev = list->head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        target = prev->next;
        prev->next = target->next;
        if (target == list->tail) {
            list->tail = prev;
        }
    }
    free(target);
    list->size--;
}

// 按值删除（删除第一个匹配的节点）
void deleteByValue(LinkedList *list, DataType val) {
    Node *curr = list->head;
    Node *prev = NULL;

    while (curr) {
        if (curr->data == val) {
            if (prev == NULL) { // 删除的是头节点
                list->head = curr->next;
            }
            else {
                prev->next = curr->next;
            }

            if (curr == list->tail) { // 删除的是尾节点
                list->tail = prev;
            }

            free(curr);
            list->size--;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("未找到值为 %d 的节点\n", val);
}

// 6. 销毁链表
void destroyList(LinkedList *list) {
    if (!list) return;
    Node *curr = list->head;
    while (curr) {
        Node *nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }
    free(list);
    printf("链表内存已全部释放\n");
}

// --- 测试主函数 ---
int main() {
    LinkedList *myList = createList();

    printf("--- 插入测试 ---\n");
    insertAtTail(myList, 10); // [10]
    insertAtTail(myList, 20); // [10, 20]
    insertAtHead(myList, 5);  // [5, 10, 20]
    insertAtIndex(myList, 2, 15); // [5, 10, 15, 20]
    printList(myList);

    printf("\n--- 删除测试 ---\n");
    deleteByIndex(myList, 0);   // 删除 5 -> [10, 15, 20]
    printList(myList);

    deleteByValue(myList, 15);  // 删除 15 -> [10, 20]
    printList(myList);

    printf("\n--- 边界测试 (删除尾部) ---\n");
    deleteByIndex(myList, 1);   // 删除 20 -> [10]
    printList(myList);
    printf("当前尾节点数据: %d\n", myList->tail->data);

    destroyList(myList);

    // 现在，我在写一个C代码。 想写一个链表相关的基础操作。 
    //链表的基本结构
    //    typedef int DataType;
    //typedef struct node_s {
    //    DataType data;
    //    struct node_s *next;
    //}Node;

    //typedef struct {
    //    Node *head;
    //    Node *tail;
    //    int size;
    //}LinkedList;

    //函数包括：
    //创建链表
    //销毁链表
    //打印链表

    //头插 / 尾插 / 中间插
    //按值删 / 按索引删

    //函数的名字，使用下划线分割，不使用小驼峰命名方式。
    //所有函数的名字，都以linkedlist_create linkedlist_destory linkedlist_ * **开头，以区分这是链表的函数。

    return 0;
}