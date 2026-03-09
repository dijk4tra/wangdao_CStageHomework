#ifndef TEST1_H   // 检查是否以及引入该头文件，若为引入，则将if---end之间的内容复制过去
#define TEST1_H   // 未引入该头文件，此时引入该头文件

// #ifndef 是一个预处理指令
// #ifndef：if not define
// 如果没有这个宏定义，就将if---end之间的内容复制过去
// 如果有这个宏定义，就不复制粘贴过去

struct student {
	int id;
	char name[20];
};

#endif // !TEST1_H
