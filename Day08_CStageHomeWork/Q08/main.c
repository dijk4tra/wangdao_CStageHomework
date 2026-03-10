#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
第一题：
下面结构体类型的变量的内存布局是怎样的？请使用VS的Debug模式查看它的内存布局
typedef struct stundent_s {
	int number;
	char name[25];
	char gender;
	int chinese;
	int math;
	int english;
} Student;
// 结构体对象的声明和初始化
Student s1 = { 1, "Jack", 'm', 100, 100, 100 };

第二题：
基于上述的结构体类型的定义，实现以下功能：
1.从键盘输入5个学生的信息，将这些同学的信息采用结构体数组的方式存储起来。（代码直接写在main函数里）
2.编写一个函数，用于打印单个结构体信息。然后在main函数里调用该函数，打印这个结构体数组。
3.编写一个函数，用于求三个学科的平均分。然后在main函数里调用该函数，打印这三个学科的平均分。
*/

typedef struct stundent_s {
	int number;
	char name[25];
	char gender;
	int chinese;
	int math;
	int english;
} Student;

// 打印单个学生的信息
void print_single_student_info(Student s) {
	printf("学号:%d 姓名:%s 性别:%c 语文:%d 数学:%d 英语:%d\n", s.number, s.name, s.gender, s.chinese, s.math, s.english);
}

// 计算三门课的平均分
void print_average_score(Student arr[], int size) {
	float sumChinese = 0, sumMath = 0, sumEnglish = 0;

	for (int i = 0; i < size; i++) {
		sumChinese += arr[i].chinese;
		sumMath += arr[i].math;
		sumEnglish += arr[i].english;
	}

	printf("\n三个学科的平均分为：\n");
	printf("语文平均分: %.2f\n", sumChinese / size);
	printf("数学平均分: %.2f\n", sumMath / size);
	printf("英语平均分: %.2f\n", sumEnglish / size);
}


int main(void) {
	// 声明一个可以存放5个学生的结构体数组
	Student students[5];
	printf("请输入5个学生的信息（格式：学号 姓名 性别 语文 数学 英语）:\n");
	for (int i = 0; i < 5; i++) {
		printf("请输入第%d个学生的信息: ", i + 1);
		scanf("%d %s %c %d %d %d",
			&students[i].number,
			students[i].name,		// 数组名已经是指针
			&students[i].gender,
			&students[i].chinese,
			&students[i].math,
			&students[i].english);
	}
	// 依次打印学生信息
	for (int i = 0; i < 5; i++) {
		print_single_student_info(students[i]);
	}
	// 计算各学科平均分
	print_average_score(students, 5);

    return 0;
}