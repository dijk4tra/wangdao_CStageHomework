#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "vector.h"

void test1() {
    Vector *vec = vector_create();

	//vector_add_after_tail(vec, 10);
	//vector_add_after_tail(vec, 20);
	//vector_add_after_tail(vec, 30);
	//vector_add_after_tail(vec, 40);
	//vector_add_after_tail(vec, 50);
	//vector_add_after_tail(vec, 60);
	//vector_add_after_tail(vec, 70);
	//vector_add_after_tail(vec, 80);
	//vector_add_after_tail(vec, 90);
	//vector_add_after_tail(vec, 100);
	//vector_add_after_tail(vec, 110);
	//vector_add_after_tail(vec, 110);
	//vector_add_after_tail(vec, 110);
	//vector_add_after_tail(vec, 110);
	//vector_add_after_tail(vec, 110);
	//vector_add_after_tail(vec, 110);
	//vector_add_after_tail(vec, 110);

    for (int i = 0; i < 10; i++) {
        vector_add_after_tail(vec, i * 10);
    }

    vector_print(vec);
}

int main(void) {

	test1();

    return 0;
}