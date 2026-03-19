#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef int DataType;
typedef struct node {
	DataType data;
	struct node *next;
}Node;


Node *reverse_linkedlist(Node *head) {

	// 直接将数据一个一个拿出来。然后头插就行。 
	// 准备一个哑结点。 然后将数据依次头插。 最终，将哑结点的下一个返回。 

}


int main(void) {

	return 0;
}