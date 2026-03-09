#include <iostream>  // 引入输入输出流库，用于控制台输入输出
using namespace std; // 使用标准命名空间，避免重复写std::

// 盒子类，用于表示一个三维盒子的属性和相关操作
// 封装了盒子的基本属性（长、宽、高）和计算功能（体积、表面积）

class Box {
private:
    double length; // 盒子的长度
    double width;  // 盒子的宽度
    double height; // 盒子的高度

public:
    // 成员函数：设置盒子形状
    void setShape(double l, double w, double h) {
        length = l;
        width = w;
        height = h;
    }

    // 成员函数：计算体积 (长 * 宽 * 高)
    double getVolume() {
        return length * width * height;
    }

    // 成员函数：计算表面积 (2 * (长*宽 + 长*高 + 宽*高))
    double getSurfaceArea() {
        return 2 * (length * width + length * height + width * height);
    }
};

int main() {
    Box box;
    box.setShape(2026.0, 2.0, 10.0); // 设置盒子尺寸

    cout << "盒子体积: " << box.getVolume() << endl;
    cout << "盒子表面积: " << box.getSurfaceArea() << endl;

    return 0;
}