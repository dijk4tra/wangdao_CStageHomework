#define _CRT_SECURE_NO_WARNINGS //防止编译报错
#include <iostream> // 引入输入输出流库，用于控制台输入输出
#include <cstring> // 引入处理字符串函数的库，用于strcpy、strlen等

// 可以使用标准命名空间，从而可以直接使用标准库中的标识符（如 cout、endl、string 等）而无需加上 std:: 前缀，简化代码编写
// using namespace std;     

class String {
private:    //私有成员：只能在类的内部被访问，类的外部代码不能直接访问私有成员
    char head[100];     // 存储字符串的字符数组，固定大小为100字节

public:     //公有成员：可以在类的内部和外部被访问。公有成员函数通常构成了类的接口，供外部代码使用。
    // 构造函数：初始化字符串
    String(const char* Head) {
        // 使用 strcpy 把传入的字符串内容复制到 head 数组中
        std::strcpy(head, Head);
    }

    // 成员函数：实现倒序
    void reverse() {
        int len = std::strlen(head);          // 获取字符串长度（不包含结束符）

        // 遍历字符串的前半部分，与对应的后半部分字符交换
        for (int i = 0; i < len / 2; i++) {
            char temp = head[i];              // 临时存储当前字符
            head[i] = head[len - 1 - i];      // 将后半部分字符移到前面
            head[len - 1 - i] = temp;         // 将前半部分字符移到后面
        }
    }

    // 成员函数：输出
    void print() {
        // 使用cout输出当前存储的字符串，并自动换行
        std::cout << head << std::endl;
    }
};

int main() {
    // 创建String对象并初始化
    String s("Hello World");
    // 打印原始字符串
    std::cout << "原始字符串: ";
    s.print();
    // 调用倒序函数
    s.reverse(); 
    // 打印反转后的字符串
    std::cout << "倒序后: ";
    s.print();

    return 0;
}