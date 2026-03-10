#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_triangle(double a, double b, double c) {
    if (a + b > c && a + c > b && b + c > a) {
        return true; // 是三角形
    }
    else {
        return false; // 不是三角形
    }
}

double get_area(double a, double b, double c) {
    double p = (a + b + c) / 2.0; // 三角形的半周长
    double area = sqrt(p * (p - a) * (p - b) * (p - c)); // 求三角形的面积
    return area;
}

int main(void) {
    double a, b, c;
    printf("请输入三角形的边长（用空格隔开）：");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (is_triangle(a, b, c)) {
        printf("该三角形的面积为：%lf", get_area(a, b, c));
    }
    else {
        printf("输入的边长无法组成三角形！");
    }
    return 0;
}