#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef int DataType;

typedef struct node_s {
    DataType data;
    struct node_s *next;
}Node;

void insert_before_head(Node **p_head, DataType data) {
	//*p_head = ...;
	Node *new_node = calloc(1, sizeof(Node));
	// if
	new_node->data = data;
	new_node->next = *p_head;
	*p_head = new_node;
}

int main(void) {
	// 现在，我们写 Node  LinkedList 
	// 如果不要这个LinkedList这个壳，其实也能写代码。 

	// 先实现头插法。

	// 在main函数中，肯定需要维护，链表的头指针。 
	Node *head = NULL;

	insert_before_head(&head, 10);
	insert_before_head(&head, 9);
	insert_before_head(&head, 8);

	// change_int_by_int
	// change_int_by_pointer
	// change_pointer_by_pointer
	// change_pointer_by_pointerpointer
    return 0;
}