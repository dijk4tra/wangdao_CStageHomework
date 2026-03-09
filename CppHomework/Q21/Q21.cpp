#define _CRT_SECURE_NO_WARNINGS //防止编译报错
#include <stdio.h>

int isLeapYear(int year) {
	// 能被4整除但不能被100整除，或者能被400整除的年份是闰年
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
	int y, m, d, h, min, s;
	int days_in_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	printf("请输入日期和时间（格式：年 月 日 时 分 秒（空格隔开，需要是纯数字））：");
	scanf("%d %d %d %d %d %d", &y, &m, &d, &h, &min, &s);

	s++; // 加一秒
	if (s >= 60) {
		s = 0;
		min++;
		if (min >= 60) {
			min = 0;
			h++;
			if (h >= 24) {
				h = 0;
				d++;
				// 检查月份天数
				if (m == 2 && isLeapYear(y)) { // 闰年2月
					if (d > 29) { 
						d = 1;
						m++;
					}
				}
				else {
					if (d > days_in_month[m]) {
						d = 1;
						m++;
					}
				}
				if (m > 12) {
					m = 1;
					y++;
				}
			}
		}
	}

	printf("下一秒是: %d年%d月%d日 %02d:%02d:%02d\n", y, m, d, h, min, s);
	return 0;
}