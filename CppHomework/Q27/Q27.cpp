#include <stdio.h>
#include <stdlib.h>

/**
 * 链表节点结构体
 * @data: 节点存储的数据
 * @next: 指向下一个节点的指针
 */
typedef struct Node {
    int data;           // 节点数据域，存储整型数据
    struct Node* next;  // 节点指针域，指向下一个节点
} Node;

/**
 * 删除链表中指定值的节点
 * @head: 链表头指针（注意：这里传递的是头指针的副本）
 * @value: 要删除的节点值
 * @return: 返回删除节点后的新头指针
 *
 * 说明：由于C语言参数传值特性，这里需要返回新的头指针
 * 这里head是一个指向Node的指针，函数调用时，我们传入的是头指针的副本（即形参head是实参的一个拷贝）。如果我们修改了形参head（比如在删除头节点的情况下，我们将head指向了下一个节点），这个修改并不会反映到函数外部的实参上。
 * 因此如果不返回新的头指针，那么在删除头节点的情况下，函数内部虽然将head指向了下一个节点，但外部的头指针并没有改变，就会造成错误。
 * 特殊情况处理：
 * 1. 链表为空：直接返回NULL
 * 2. 删除头节点：需要更新头指针
 * 3. 删除中间或尾部节点：需要找到前驱节点
 */
Node* deleteNode(Node* head, int value) {
    // 情况1：链表为空
    if (head == NULL) {
        printf("链表为空，无法删除节点\n");
        return NULL;  // 直接返回空指针
    }

    // 情况2：要删除的是头节点
    if (head->data == value) {
        Node* temp = head;      // 临时保存当前头节点地址，用于后续释放内存
        head = head->next;      // 将头指针移动到下一个节点
        free(temp);             // 释放原头节点的内存空间
        printf("已删除头节点: %d\n", value);
        return head;            // 返回新的头指针
    }

    // 情况3：要删除的是中间或尾部节点
    Node* current = head;  // 从链表头开始遍历

    // 关键点：寻找要删除节点的前一个节点（前驱节点）
    // 条件说明：
    // current->next != NULL ：确保当前节点不是最后一个节点（避免访问空指针）
    // current->next->data != value ：继续遍历直到找到目标值
    while (current->next != NULL && current->next->data != value) {
        current = current->next;  // 移动到下一个节点
    }

    // 检查是否找到目标节点
    if (current->next != NULL) {
        // 找到目标节点，current是要删除节点的前一个节点
        Node* temp = current->next;    // temp指向要删除的节点
        current->next = temp->next;    // 跳过要删除的节点，连接前后节点
        free(temp);                    // 释放要删除节点的内存
        printf("已删除节点: %d\n", value);
    }
    else {
        // 遍历到链表末尾仍未找到目标值
        printf("未找到值为 %d 的节点\n", value);
    }

    return head;  // 返回头指针（头节点未改变时保持不变）
}

/**
 * 创建新节点
 * @data: 新节点要存储的数据
 * @return: 返回新创建的节点指针
 */
Node* createNode(int data) {
    // 动态分配内存空间，大小为Node结构体的大小
    Node* newNode = (Node*)malloc(sizeof(Node));

    // 检查内存分配是否成功
    if (newNode == NULL) {
        printf("内存分配失败！\n");
        exit(1);  // 分配失败时退出程序
    }

    // 初始化新节点的数据域和指针域
    newNode->data = data;
    newNode->next = NULL;  // 新节点初始时指向NULL

    return newNode;  // 返回新节点的地址
}

int main() {
    // 构建一个简单的链表: 1 -> 2 -> 3 -> NULL
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    // 删除值为 2 的节点
    head = deleteNode(head, 2);

    return 0;
}