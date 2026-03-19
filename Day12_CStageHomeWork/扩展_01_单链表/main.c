#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ARR_LEN(arr) ((sizeof(arr))/(sizeof(arr[0])))

typedef struct Node {
	int data;
	struct Node *next;
} Node;

// 尾插法
void insert_tail(Node **head, int val) {
	Node *new_node = calloc(1, sizeof(Node));	// 用calloc避免忘记设置next域为NULL
	if (new_node == NULL) {
		printf("malloc failed in insert_tail.\n");
		exit(1);
	}
	new_node->data = val;
	if (*head == NULL) {
		*head = new_node;
	}
	else {
		Node *curr = *head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = new_node;
	}
}

// 删除单链表中连续出现的重复结点
// 当链表中有相邻的两个或多个结点的值相同时，删除后续的重复结点，只保留第一个出现的结点
void del_continuous_repeat(Node *head) {
	// 1.处理边界情况：如果链表为空，或者只有一个结点，直接返回
	if (head == NULL || head->next == NULL) {
		return;
	}
	// 2.定义一个遍历指针 curr，从头结点开始
	Node *curr = head;
	// 3.循环遍历，条件是：当前结点不为空且下一个结点也不为空
	// 因为我们需要对比 curr 和 curr->next，如果 curr->next 为空就没必要对比了
	while (curr != NULL && curr->next != NULL) {
		// 4.判断当前结点的值和下一个结点的值是否相同
		if (curr->data == curr->next->data) {
			// 发现相邻的重复结点，准备删除 curr->next 这个结点
			// 暂存需要删除的结点
			Node *temp = curr->next;
			// 将当前结点的 next 指向被删除结点的下一个结点
			curr->next = temp->next;
			// 释放被删除结点的内存
			free(temp);
		}
		else {
			// 如果相邻的两个结点值不同，说明没有重复
			// curr 指针安全地向后移动一位，去检查后面的结点
			curr = curr->next;
		}
	}
}


// 打印单链表
void print_list(Node *head) {
	Node *curr = head;
	while (curr != NULL) {
		printf("%d", curr->data);
		if (curr->next != NULL) {
			printf(" -> ");
		}
		curr = curr->next;
	}
	printf("\n");
}

// 释放整个链表的内存
void free_list(Node *head) {
	Node *curr = head;
	while (curr != NULL) {
		Node *temp = curr;
		curr = curr->next;
		free(temp);
	}
}


int main(void) {
	Node *head = NULL;

	// 测试用例：1 -> 2 -> 2 -> 3 -> 4 -> 4 -> 4 -> 5
	int arr1[] = { 1,2,2,3,4,4,4,5 };
	for (int i = 0; i < ARR_LEN(arr1); i++) {
		insert_tail(&head, arr1[i]);
	}
	printf("原始链表：\n");
	print_list(head);

	del_continuous_repeat(head);
	printf("去重后链表:\n");
	print_list(head);

	free_list(head); // 清理内存
	head = NULL;     // 重置指针


    return 0;
}