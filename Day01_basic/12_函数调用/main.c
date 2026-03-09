#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define INVALID_TRIANGLE -1.0

double calculate_triangle_area(double a, double b, double c) {
    // 怎么算面积？
    // 假设你不知道这个公式？ 怎么办？

    // 要注意: 有些时候，不知道这玩意怎么搞，也要搞出来
    // 1.上网查。 
    // 2.AI  

    double s, area;

    // 检查是否能构成三角形
    if (a <= 0 || b <= 0 || c <= 0) {
        return INVALID_TRIANGLE;  // 边长不能为负数或零
    }

    if (a + b <= c || a + c <= b || b + c <= a) {
        return INVALID_TRIANGLE;  // 两边之和小于等于第三边
    }

    // 计算半周长
    s = (a + b + c) / 2;

    // 使用海伦公式计算面积
    area = sqrt(s * (s - a) * (s - b) * (s - c));

    return area;
}

double calculate_triangle_area2() {
    // 假设，知道三个点的坐标。怎么算面积。 自己试一下。 
}

int main(void) {
    // 现在，想写一个三角形的面积计算公式。 
    // 假设，你们公司，经常涉及，三角形面积的计算。 

    double res = calculate_triangle_area(3, 4, 5);

    printf("res = %lf\n", res);

    double res2 = calculate_triangle_area(3, 4, 12);
    printf("res = %lf\n", res2);

    int arr[] = { 10,20,30 };

    int* p = NULL;
    printf("%d\n", *p);

    return 0;
}