#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "vector.h"

int main(void) {

	Vector *vec = vector_create();

	vector_add_after_tail(vec, 10);
	vector_add_after_tail(vec, 20);
	vector_add_after_tail(vec, 30);
	vector_add_after_tail(vec, 40);

	vector_add_before_head(vec, 1);
	vector_print(vec);
	vector_add_before_head(vec, 2);
	vector_print(vec);
	vector_add_before_head(vec, 3);
	vector_print(vec);
	vector_add_before_head(vec, 5);

	//  5  3   2 1 10  20  30  40 

	//for (int i = 0; i < 1000; i++) {
	//	vector_add_after_tail(vec, i * 10);
	//}

	vector_print(vec);

	return 0;
}