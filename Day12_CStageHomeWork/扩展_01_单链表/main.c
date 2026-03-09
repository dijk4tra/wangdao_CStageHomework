#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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

// 删除单链表中连续出现的重复节点
// 当链表中有相邻的两个或多个节点的值相同时，删除后续的重复节点，只保留第一个出现的节点
void del_continuous_repeat(Node *head) {
	// 处理边界情况：如果链表为空，或者只有一个节点，直接返回
	if (head == NULL || head->next == NULL) {
		return;
	}

	Node *curr = head;
	while (curr != NULL && curr->next != NULL) {

		if (curr->data == curr->next->data) {
			Node *temp = curr->next;
			curr->next = temp->next;
			free(temp);
		}
		else {
			curr = curr->next;
		}

	}

}



int main(void) {
    

    return 0;
}