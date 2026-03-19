// 头文件保护语法
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

typedef int DataType;

// 定义链表结点结构
typedef struct node {
	DataType data;		// 数据域
	struct node *next;	// 指针域
}Node;

// 定义链表结构本身
typedef struct {
	Node *head;   // 头指针
	Node *tail;	  // 尾节点指针	
	int size;	  // 节点数量，用于记录链表的长度
}LinkedList;

// 创建链表、销毁链表、打印链表
LinkedList *linkedlist_create();
void linkedlist_destroy(LinkedList *list);
void linkedlist_print(LinkedList *list);

// 增删改查
// 头插法
bool linkedlist_insert_before_head(LinkedList *list, DataType new_data);
// 尾插法
bool linkedlist_insert_after_tail(LinkedList *list, DataType new_data);
// 根据索引插入一个新结点
bool linkedlist_insert_by_idx(LinkedList *list, int idx, DataType new_data);
// 根据索引搜索一个结点
Node *search_by_idx(LinkedList *list, int idx);
// 根据数据搜索一个结点
Node *search_by_data(LinkedList *list, DataType data);
// 根据数据删除一个结点
bool delete_by_data(LinkedList *list, DataType data);
// 扩展: 根据索引删除一个结点
bool delete_by_idx(LinkedList *list, int idx);

#endif // !LINKEDLIST_H

