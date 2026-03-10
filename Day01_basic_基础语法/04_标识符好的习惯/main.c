#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {

	// 使用合法的英文单词，除非迫不得已，禁止使用汉语拼音（特殊情况如baidu）。
	// 见名知意是标识符命名的核心原则。标识符的目的是命名，这个名字显然应该是一个描述性强的、易于理解的字符串。
	// 命名风格：如果出现多个单词，保持所有单词字母小写，然后用下划线分隔的方式以示区分。比如my_name、team_num等。

	// 不太建议使用拼音。更不建议使用缩写。 
	// int hubeixueshenggeshu = 10;
	// hbxsgs
	// dhsajkhjdjksa
	// kjlkdsdl

	// int hubei_student_count
	// 建议取名不要偷懒，应该尽量用描述性强的单词来，不要使用无意义的字母或者首字母缩写！
	// a b c d e f g .... z   ab ac 

	// hubeilowaveragescorecount
	// 命名风格： 就是多个英文单词组合在一起的时候，怎么组合。 
	// 第一种组合策略： 使用下划线进行分割是C中比较常用的一种方式。 
	// hubei_low_average_score_count

	// 第二种组合策略： 驼峰命名法。 单词的界限处，使用大写来区分。 
	// hubeiLowAverageScoreCount

	// 小驼峰： 第一个单词，第一个字母小写。 
	// hubeiLowAverageScoreCount
	// 大驼峰： 第一个单词的第一个字母，大写。 
	// HubeiLowAverageScoreCount

	int num = 10;

	return 0;
}