#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


int main(void) {
    // 创建一个空的链表
    LinkedList *list = linkedlist_create();

    // 测试头部插入
    linkedlist_insert_before_head(list, 10);
    linkedlist_insert_before_head(list, 20);
    linkedlist_insert_before_head(list, 30);

    printf("在头部插入30, 20, 10后:\n");
    linkedlist_print(list); // 预期输出: 30 -> 20 -> 10

    // 测试尾部插入
    linkedlist_insert_after_tail(list, 40);
    linkedlist_insert_after_tail(list, 50);

    printf("在尾部插入40, 50后:\n");
    linkedlist_print(list); // 预期输出: 30 -> 20 -> 10 -> 40 -> 50

    // 测试按索引插入
    linkedlist_insert_by_idx(list, 2, 25); // 在索引2的位置插入25

    printf("在索引2插入25后:\n");
    linkedlist_print(list); // 预期输出: 30 -> 20 -> 25 -> 10 -> 40 -> 50

    // 测试按索引搜索
    Node *node = search_by_idx(list, 2);
    printf("索引2处的元素: %d\n", node->data); // 预期输出: 25

    // 测试按数据搜索
    node = search_by_data(list, 40);
    printf("找到数据40的结点: %d\n", node->data); // 预期输出: 40

    // 测试按数据删除
    delete_by_data(list, 25);
    printf("删除数据25后:\n");
    linkedlist_print(list); // 预期输出: 30 -> 20 -> 10 -> 40 -> 50

    // 测试按索引删除
    delete_by_idx(list, 0); // 删除索引0处的元素
    printf("删除索引0处的元素后:\n");
    linkedlist_print(list); // 预期输出: 20 -> 10 -> 40 -> 50

    // 销毁链表
    linkedlist_destroy(list);
    return 0;
}