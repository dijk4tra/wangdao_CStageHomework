#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

// 创建链表
LinkedList *linkedlist_create() {
	// 如何创建一个链表？

	LinkedList *list = malloc(sizeof(LinkedList));

	if (list == NULL) {
		printf("malloc failed in linkedlist_create.\n");
		return NULL;
	}

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	// 使用calloc可以自动初始化成员为默认零值,更加省事
	// LinkedList *list = calloc(1, sizeof(LinkedList));
	return list;

}


// 删除链表
void linkedlist_destroy(LinkedList *list) {
	Node *curr_node = list->head;

	while (curr_node != NULL) {
		//说明curr_node不为空
		Node *temp = curr_node->next;
		free(curr_node);
		curr_node = temp;
	} // while循环结束时，curr_node指针指向NULL
	// 最后释放链表结构
	free(list);
}


// 遍历打印链表
void linkedlist_print(LinkedList *list) {
	Node *curr_node = list->head;
	while (curr_node != NULL) {
		printf("%d", curr_node->data);
		// 如果不是链表的最后一个节点，就打印箭头
		if (curr_node->next != NULL) {
			printf(" ---> ");
		}
		curr_node = curr_node->next;
	}
	printf("\n");
}


// 增删改查
// 头插法插入结点
bool linkedlist_insert_before_head(LinkedList *list, DataType new_data) {
	Node *new_node = (Node *)malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("malloc failed in linkedlist_insert_before_head.\n");
		return false;
	}
	// 初始化新结点
	new_node->data = new_data;
	new_node->next = list->head;	// 新节点指向原本的第一个结点

	// 更新头指针指向新结点
	list->head = new_node;

	// 如果尾指针为NULL，说明链表在插入新结点前为空，此时新结点同时也成为尾结点
	if (list->tail == NULL) {
		list->tail = new_node;
	}
	list->size++;
	return true;
}


// 尾插法插入结点
bool linkedlist_insert_after_tail(LinkedList *list, DataType new_data) {
	Node *new_node = (Node *)malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("malloc failed in linkedlist_insert_after_tail.");
		return false;
	}
	// 初始化新结点
	new_node->data = new_data;
	new_node->next = NULL;	// 指针域初始为NULL

	// 如果尾结点指针为NULL，说明链表尾插前为空，新结点插入后既是头结点也是尾结点
	if (list->tail == NULL) {
		// 链表为空
		list->head = new_node;
		list->tail = new_node;
	}
	// 尾指针不为空，让之前的尾结点指向新结点，再更新尾指针
	list->tail->next = new_node;
	list->tail = new_node;
	list->size++;
	return true;
}


// 根据索引插入结点
bool linkedlist_insert_by_idx(LinkedList *list, int idx, DataType new_data) {
	// 按照索引插入
	// 索引取值范围应该是[0, size]

	if (idx<0 || idx > list->size) {
		printf("idx illegal.\n");
		return false;
	}

	// 边界值处理, 即处理头插和尾插的情况
	if (idx == 0) {
		linkedlist_insert_before_head(list, new_data);
	}
	if (idx == list->size) {
		linkedlist_insert_after_tail(list, new_data);
	}

	// 代码走到这里，说明不是头插也不是尾插
	// 如何插入？在链表中，若要操作某个节点，需要找到这个节点的前驱节点
	// 处理在中间插入结点的情况
	// 分配新结点, 并初始化数据域
	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL) {
		// 内存分配失败处理
		printf("malloc failed in linkedlist_insert_by_idx.\n");
		return false;
	}
	new_node->data = new_data;

	// 遍历找到目标索引的前一个结点
	Node *pre_node = list->head;
	for (int i = 0; i < idx - 1; i++) {
		pre_node = pre_node->next;
	} // 循环结束后, prev指针指向idx索引前面的一个结点
	
	// 在idx位置, 插入新结点
	// 先让新结点指向pre_node的后继结点，再让pre_node指向新结点
	new_node->next = pre_node->next;
	pre_node->next = new_node;

	list->size++;
	return true;
	
}


// 根据索引搜索一个结点
Node *search_by_idx(LinkedList *list, int idx) {
	if (idx < 0 || idx> list->size - 1) {
		printf("illegal index.");
		return NULL;
	}
	// 遍历找到目标索引的结点
	Node *curr_node = list->head;
	for (int i = 0; i < idx - 1; i++) {
		curr_node = curr_node->next;
	} // while循环结束时, curr_node指针就指向idx位置的结点
	return curr_node;
}


// 根据数据搜索一个结点
Node *search_by_data(LinkedList *list, DataType data) {
	Node *curr_node = list->head;
	while (curr_node != NULL) {
		if (curr_node->data == data) {
			return curr_node;
		}
		curr_node = curr_node->next;
	}
	// 遍历完整条链表都没找到, 说明目标结点不存在
	return NULL;
}


// 根据数据删除一个结点
bool delete_by_data(LinkedList *list, DataType data) {
	// 定义一个临时指针用于遍历链表
	Node *curr_node = list->head;
	// 若要删除的结点是第一个结点，需要更新头指针
	if (curr_node->data == data) {
		list->head = list->head->next;
		// 若链表只有一个结点，那还需要更新尾指针
		if (list->head == NULL) {
			list->tail = NULL;
		}
		free(curr_node);
		list->size--;
		return true;
	}
	// 如果要删除的结点，不是第一个结点，则从第二个结点开始遍历查找待删除目标结点
	// 删除操作需要两个指针完成: curr_node指针用于查找待删除目标结点, pre_node指向待删除结点的前驱结点
	Node *pre_node = curr_node; // pre_node始终指向curr_node结点的前驱
	curr_node = curr_node->next;	   // curr_node指针用于遍历查找待删除的结点
	while (curr_node != NULL) {
		if (curr_node->data = data) {
			pre_node->next = curr_node->next;  // 让待删除结点的前驱结点指向待删除结点的后继结点
			if (curr_node->next == NULL) {
				// 若待删除的是尾结点，则还要更新尾指针
				list->tail = pre_node;
			}
			free(curr_node);
			list->size--;
			return true;
		}
		// 当前结点不是待删除目标结点，继续遍历
		pre_node = curr_node;
		curr_node = curr_node->next;
	}
	// 遍历完都未找到目标结点, 删除失败
	return false;
}


// 根据索引删除一个结点
bool delete_by_idx(LinkedList *list, int idx) {
	// 检查待搜索的索引是否越界，索引的合法范围是[0, size-1]
	if (idx < 0 || idx >= list->size) {
		printf("illegal index.");
		return false;
	}

	// 需要两个结点来完成结点的删除
	Node *pre_node = NULL;
	Node *curr_node = list->head;

	// 如果要删除的结点是第一个结点（idx == 0）
	if (idx == 0) {
		list->head = curr_node->next;  // 更新头指针
		// 若删除的结点是唯一的结点，则还需要更新尾指针
		if (list->size == 1) {
			list->tail = NULL;
		}
		free(curr_node);
		list->size--;
		return true;
	}

	// 要删除的结点不是第一个结点
	for (int i = 0; i < idx - 1; i++) {
		pre_node = curr_node;
		curr_node = curr_node->next;
	} //循环结束时, curr_node指针就指向idx位置的结点

	// 让前驱结点指向当前要删除结点的后继
	pre_node->next = curr_node->next;

	// 如果要删除的是尾结点, 则还需要更新尾指针
	if (idx == list->size - 1) {
		list->tail = pre_node;
	}
	free(curr_node);
	list->size--;
	return true;
}