#include <iostream>   // 引入输入输出流库，用于控制台输入输出
#include <string>     // 引入字符串类，用于处理姓名信息
using namespace std;  // 使用标准命名空间，避免重复写std::

class Student {
private: // 私有访问权限，外部不能直接访问
    string name; // 学生姓名
    int score;   // 学生成绩

public: // 公有访问权限，外部可以访问
    // 使用初始化列表：name(n)将参数n赋值给成员name，score(s)同理
    Student(string n, int s) : name(n), score(s) {}

    // 声明友元函数：注意它在类里面声明，但不是类的成员
    // 友元函数不是类的成员函数，但可以访问类的私有成员
    // friend关键字表示showGrade函数是该类的"朋友"，拥有特殊访问权限
    friend void showGrade(Student &s);
};

// 定义友元函数
void showGrade(Student &s) {
    // 作为友元函数，可以直接访问私有成员 s.score 和 s.name
    cout << "学生: " << s.name << " 的成绩对应的等级是: ";

    // 根据分数判断等级
    if (s.score >= 90) cout << "优";
    else if (s.score >= 80) cout << "良";
    else if (s.score >= 70) cout << "中";
    else if (s.score >= 60) cout << "及格";
    else cout << "不及格";

    cout << endl;
}

int main() {
    Student stu("马画藤", 85);
    // 调用友元函数显示学生成绩等级
    // 注意：showGrade不是stu的成员函数，而是普通函数
    showGrade(stu);
    return 0;
}