#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
利用快慢指针法，直接求解下列两个问题：
1.求链表中间结点的值
2.判断单链表是否有环

原理：
问题一：求链表中间结点
策略：fast指针每次走2步，slow指针每次走1步。
原理：由于速度是两倍关系，当fast到达链表末尾（NULL）时，slow恰好指向链表的中点。
注意点：
奇数个结点：slow正好在正中间。
偶数个结点：通常返回中间两个结点的第二个（取决于循环终止条件）。

问题二：判断链表是否有环
策略：fast指针每次走2步，slow指针每次走1步。
原理：如果链表有环，fast会进入环并最终“追上”slow（就像操场跑步圈内追及）。如果fast遇到NULL，则说明无环。
*/

typedef struct node {
	int data;
	struct node *next;
} Node;

// 实现尾插法构建链表
void insert_tail(Node **head, int new_data) {
	// 1.分配新结点，初始化它
	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("error: malloc failed in insert_tail.\n");
		exit(1);
	}
	new_node->data = new_data;
	new_node->next = NULL;
	// 3.链表非空时,让原本最后一个结点指向新结点
	if (*head != NULL) {
		// 2.遍历找到最后一个结点
		Node *end = *head;
		while (end->next != NULL) {
			end = end->next;
		} // while循环结束时, end指向最后一个结点
		end->next = new_node;
		return;
	}
	// 链表尾插之前是空的,那就直接更新头指针就行了
	*head = new_node;
}

// 函数：求链表中间结点的值
int find_middle_value(Node *head) {
	if (head == NULL) {
		// 当链表为空
		return -1;
	}

	Node *slow = head;
	Node *fast = head;
	// 当快指针没走到头，且快指针的下一个也不为空时继续
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;			// 走一步
		fast = fast->next->next;	// 走两步
	}	// 循环结束时，slow指向的就是中间结点
	return slow->data;
}

// 函数：判断链表是否有环
bool has_cycle(Node *head) {
	if (head == NULL) {
		// 当链表为空
		return false;
	}

	Node *slow = head;
	Node *fast = head;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;			// 走一步
		fast = fast->next->next;	// 走两步

		// 如果快指针和慢指针相遇，说明有环
		if (slow == fast) {
			return true;
		}
	}
	return false;
}

// 打印链表
void print_list(Node *head) {
	Node *curr = head;
	while (curr != NULL) {
		printf("%d -> ", curr->data);
		curr = curr->next;
	}
	printf("NULL\n");
}


int main(void) {
    
	// 求链表中间结点
	Node *list1 = NULL;
	for (int i = 1; i <= 5; i++) {
		insert_tail(&list1, i * 10); // 10, 20, 30, 40, 50
	}
	printf("链表内容: ");
	print_list(list1);
	printf("中间结点的值: %d\n", find_middle_value(list1)); // 中间结点为30

	// 判断链表是否有环  
	printf("测试无环链表: %s\n", has_cycle(list1) ? "有环" : "无环");

	// 构造有环链表
	Node *list2 = NULL;
	insert_tail(&list2, 1); // 这里应该更新头指针指向头结点1
	insert_tail(&list2, 2);
	insert_tail(&list2, 3);
	insert_tail(&list2, 4);

	// 此时链表: 1 -> 2 -> 3 -> 4 -> NULL
	// 让 4 指向 2，形成环
	Node *node4 = list2->next->next->next;
	Node *node2 = list2->next;
	node4->next = node2;

	printf("测试有环链表: %s\n", has_cycle(list2) ? "有环" : "无环");

    return 0;
}