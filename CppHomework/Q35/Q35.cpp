#include <iostream>   // 引入输入输出流库，用于控制台输入输出
using namespace std;  // 使用标准命名空间，避免重复写std::

// 定义一个复数类 Complex
class Complex {
private:
    double real; // 实部，用于存储复数的实数部分
    double imag; // 虚部，用于存储复数的虚数部分（i的系数）

public:
    // 构造函数，用于初始化复数对象
    // 参数 r：实部值，默认值为0
    // 参数 i：虚部值，默认值为0
    // 使用初始化列表初始化成员变量
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // 声明友元函数，重载 + 运算符
    // friend 关键字允许此函数访问类的私有成员
    // 参数使用 const 引用，避免不必要的拷贝，提高效率
    friend Complex operator+(const Complex& c1, const Complex& c2);

    // 成员函数：输出复数到控制台
    // 格式为：(实数部分 + 虚数部分i)
    void display() {
        // 输出复数格式，例如：(3 + 4i)
        cout << "(" << real << " + " << imag << "i)" << endl;
    }
};

// 实现全局运算符重载函数：复数加法
// 功能：将两个复数相加，返回新的复数对象
// 参数说明：
// c1 - 第一个复数（左操作数）
// c2 - 第二个复数（右操作数）
// 返回值：新的 Complex 对象，其值为两个复数的和
Complex operator+(const Complex& c1, const Complex& c2) {
    // 创建并返回一个新的复数对象
    // 新复数的实部 = c1的实部 + c2的实部
    // 新复数的虚部 = c1的虚部 + c2的虚部
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    // 创建第一个复数对象 c1，实部=3.0，虚部=4.0
    Complex c1(3.0, 4.0);
    // 创建第二个复数对象 c2，实部=1.0，虚部=2.0
    Complex c2(1.0, 2.0);
    // 使用重载的 + 运算符计算两个复数的和
    // 相当于调用：operator+(c1, c2)
    Complex sum = c1 + c2; 

    // 输出原始复数和计算结果
    cout << "c1: "; c1.display(); // 显示 c1
    cout << "c2: "; c2.display(); // 显示 c2
    cout << "相加结果: "; sum.display(); // 显示和

    return 0;
}