#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int DataType;

typedef struct node {
	DataType data;	// 数据域
	struct node *next;	// 指针域
}Node;

typedef struct {
	Node *head;	// 头指针
	Node *tail;	// 尾指针
	int size;	// 用于记录链表的长度
}LinkedList;

// 创建一个空链表
LinkedList *create_linked_list();
// 销毁链表
void destroy_linked_list(LinkedList *list);
// 头插法
bool add_before_head(LinkedList *list, DataType new_data);
// 尾插法
bool add_after_tail(LinkedList *list, DataType new_data);
// 根据索引插入一个新结点
bool add_by_idx(LinkedList *list, int idx, DataType new_data);
// 根据索引搜索一个结点
Node *search_by_idx(LinkedList *list, int idx);
// 根据数据搜索一个结点
Node *search_by_data(LinkedList *list, DataType data);
// 根据数据删除一个结点
bool delete_by_data(LinkedList *list, DataType data);
// 根据索引删除一个结点
bool delete_by_idx(LinkedList *list, int idx);
// 打印单链表（格式为：1 -> 2 -> 3 ->...）
void print_list(LinkedList *list);


#endif // !LINKEDLIST_H
