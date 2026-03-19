#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int DataType;
typedef struct node {
	DataType data;
	struct node *next;
}Node;

bool has_circle(Node *head) {
	if (head == NULL || head->next == NULL || head->next->next == NULL) {
		// head == NULL || head->next == NULL || head->next->next == NULL
		// 不能调整它的顺序，因为存在短路效果
		return false;
	}

	// 怎样确定？
	Node *fast = head->next->next;
	Node *slow = head->next;

	while (true) {
		if (fast == slow) {
			return true;
		}

		if (fast == NULL || fast->next == NULL || fast->next->next == NULL) {
			return false;
		}
		fast = fast->next->next;
		slow = slow->next;
	}

}

void test1() {
	// 可以使用快慢指针来确定是否有环。 

	Node n1 = { 10, NULL };
	Node n2 = { 20, &n1 };
	Node n3 = { 30, &n2 };
	Node n4 = { 40, &n3 };
	Node n5 = { 50, &n4 };

	//50-->40-->30 --> 20 --> 10
	printf("has_circle=%d\n", has_circle(&n5));

	//n1.next = &n4;
	//n1.next = &n3;
	n1.next = &n2;
	printf("has_circle=%d\n", has_circle(&n5));
}


int main(void) {

	test1();

	return 0;
}