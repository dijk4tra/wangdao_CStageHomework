#include <iostream>  // 引入输入输出流库，用于控制台输入输出
using namespace std; // 使用标准命名空间，避免重复写std::

class Tree {
private:
    int ages; // 树龄

public:
    // 构造函数，初始化树对象，当创建Tree对象时，自动调用此函数进行初始化
    Tree(int initialAge = 0) {
        ages = initialAge; // 将传入的初始年龄赋值给成员变量
        cout << "一棵树已被创建" << endl;
    }

    // 成员函数：生长
    void grow(int years) {
        ages += years; // 累加年份
    }

    // 成员函数：显示树龄
    void showAge() {
        cout << "当前树龄: " << ages << " 年" << endl;
    }
};

int main() {
    // 1.创建Tree对象并初始化
    Tree myTree(24); // 创建一棵初始年龄为24岁的树
    myTree.showAge(); // 显示初始年龄

    // 2.模拟生长过程
    cout << "过了6年后..." << endl;
    myTree.grow(6);  // 调用成员函数，让树生长6年

    // 3.显示生长后的年龄
    myTree.showAge();

    return 0;
}