#include "LinkedList.h"

// 创建一个空的链表
LinkedList *create_linked_list() {
	LinkedList *list = malloc(sizeof(LinkedList));
	if (list == NULL) {
		printf("malloc failed in create_linked_list.\n");
		return NULL;
	}
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

// 销毁链表
void destroy_linked_list(LinkedList *list) {
	Node *curr_node = list->head;
	// 遍历逐一释放结点
	while (curr_node != NULL) {
		Node *temp = curr_node->next;
		free(curr_node);
		curr_node = temp;
	} // while循环结束时，curr指针指向NULL
	// 所有结点均释放完毕，最后释放链表结构
	free(list);
}

// 打印单链表 格式为：1 -> 2 -> 3 ->...
void print_list(LinkedList *list) {
	Node *curr_node = list->head;
	// 遍历此单链表
	while (curr_node != NULL) {
		printf("%d", curr_node->data);
		// 如果不是链表的最后一个结点，就打印箭头
		if (curr_node->next != NULL) {
			printf(" -> ");
		}
		curr_node = curr_node->next;
	}
	printf("\n");
}

// 头插法
bool add_before_head(LinkedList *list, DataType new_data) {
	// 分配一个新结点
	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("malloc failed in add_before_head.");
		return false;
	}
	// 新结点初始化
	new_node->data = new_data;
	new_node->next = list->head;
	// 更新头指针指向新结点
	list->head = new_node;
	// 如果尾指针为NULL，说明在插入新结点前该链表为空，此时新结点即是头结点也是尾结点
	if (list->tail == NULL) {
		// 更新尾指针指向新结点
		list->tail = new_node;
	}
	list->size++;
	return true;
}

// 尾插法
bool add_after_tail(LinkedList *list, DataType new_data) {
	// 分配一个新结点
	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("malloc failed in add_behind_tail.");
		return false;
	}
	// 新结点初始化，指针域初始为NULL
	new_node->data = new_data;
	new_node->next = NULL;

	// 如果尾指针为空，则说明当前链表为空，该节点插入后同时成头结点和尾节点
	if (list->tail == NULL) {
		list->head = new_node;
		list->tail = new_node;
		list->size++;
		return true;
	}
	// 尾指针不为空，就需要先让尾节点指向新插入节点，再更新尾指针
	list->tail->next = new_node;
	list->tail = new_node;
	list->size++; // 更新size
	return true;
}

// 根据索引插入一个新结点
bool add_by_idx(LinkedList *list, int idx, DataType new_data) {
	// 索引取值范围应该是[0, 链表长度]
	if (idx < 0 || idx > list->size) {
		printf("illegal index in add_by_idx.");
		return false;
	}
	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("malloc failed in add_by_idx.");
		return false;
	}
	new_node->data = new_data;
	new_node->next = NULL;

	if (idx == 0) {
		add_before_head(list, new_data);
		return true;
	}

	if (idx == list->size) {
		add_after_tail(list, new_data);
		return true;
	}

	Node *pre_node = list->head;
	for (int i = 0; i < idx - 1; i++) {
		pre_node = pre_node->next;
	} // 循环结束后, prev指针指向idx索引前面的一个结点
	
	// 在idx位置, 插入新结点
	// 先让新结点指向prev的后继结点, 再让prev结点指向新结点
	new_node->next = pre_node->next;
	pre_node->next = new_node;
	list->size++; // 更新size
	return true;
}

// 根据索引搜索一个结点
Node *search_by_idx(LinkedList *list, int idx) {
	// 索引取值范围应该是[0, 链表长度-1]
	if (idx < 0 || idx > list->size - 1) {
		printf("illegal index in search_by_idx.");
		return NULL;
	}
	Node *curr_node = list->head;
	for (int i = 0; i < idx; i++) {
		curr_node = curr_node->next;
	} // while循环结束时, curr指针就指向idx位置的结点
	return curr_node;
}

// 根据数据搜索一个结点
Node *search_by_data(LinkedList *list, DataType data) {
	Node *curr_node = list->head;
	for (int i = 0; i < list->size; i++) {
		if (curr_node->data == data) {
			// 找到目标结点，返回该结点
			return curr_node;
		}
		curr_node = curr_node->next;
	}
	// 遍历完整条链表都没找到, 说明目标结点不存在
	return NULL;
}

// 根据数据删除一个结点
bool delete_by_data(LinkedList *list, DataType data) {
	Node *curr_node = list->head;
	// 如果要删除的结点是第一个结点
	if (curr_node->data == data) {
		// 更新头指针
		list->head = curr_node->next;
		// 如果该链表只有一个结点
		if (list->head == NULL) {
			// 更新尾指针
			list->tail = NULL;
		}
		free(curr_node);
		list->size--;
		return true;
	}

	// 如果要删除的结点不是第一个结点，则需要从第二个结点开始遍历，找到需要删除的结点
	// 删除节点的操作需要两个指针：curr_node用于查找待删除目标结点，pre_node指向待删除结点的前驱结点
	Node *pre_node = curr_node;
	curr_node = curr_node->next;
	while (curr_node != NULL) {
		if (curr_node->data == data) {
			pre_node->next = curr_node->next; // 让待删除结点的前驱结点指向待删除结点的后继
			if (curr_node->next == NULL) {
				// 如果删除的是尾结点，还需要更新尾指针
				list->tail = pre_node;
			}
			free(curr_node);
			list->size--;
			return true;
		}
		// 当前结点不是目标结点，继续遍历
		pre_node = curr_node;
		curr_node = curr_node->next;
	}
	// 遍历完链表都没找到目标结点
	return false;
}

// 根据索引删除结点
bool delete_by_idx(LinkedList *list, int idx) {
	// 索引的合法范围是[0, list->size - 1]
	if (idx < 0 || idx > list->size - 1) {
		printf("illegal index in delete_by_idx.");
		return false;
	}
	Node *curr_node = list->head;
	// 如果要删除的结点是第一个结点
	if (idx == 0) {
		// 更新头指针
		list->head = curr_node->next;
		// 如果该链表只有一个结点
		if (curr_node->next == NULL) {
			// 更新尾指针
			list->tail = NULL;
		}
		free(curr_node);
		list->size--;
		return true;
	}

	// 如果要删除的结点不是第一个结点，则需要遍历，找到目标结点
	// 删除节点的操作需要两个指针：curr_node用于查找待删除目标结点，pre_node指向待删除结点的前驱结点
	Node *pre_node = curr_node;
	curr_node = curr_node->next;
	// 从第二个结点开始遍历
	for (int i = 0; i < idx - 1; i++) {
		pre_node = curr_node;
		curr_node = curr_node->next;
	} // 循环结束后，curr_node 指向要删除的目标结点
	// 让待删除结点的前驱结点指向待删除结点的后继
	pre_node->next = curr_node->next;
	// 如果删除的是尾结点，还有更新尾指针
	if (curr_node->next == NULL) {
		list->tail = pre_node;
	}
	free(curr_node);
	list->size--;
	return true;
}