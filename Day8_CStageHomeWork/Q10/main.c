#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_BOOKS 10

// 定义书籍类别的枚举类型
typedef enum {
    SCIENCE_FICTION, // 0: 科幻
    LITERATURE,      // 1: 文学
    HISTORY,         // 2: 历史
    TECHNOLOGY,      // 3: 科技
    OTHER            // 4: 其他
} Genre;

// 定义书籍信息的结构体
typedef struct {
    int id;
    char title[100];
    char author[100];
    Genre genre;
} Book;

// 将书籍类别的枚举值转换成中文表示的类别
// char * 表明函数返回一个内存地址，该地址指向字符串的第一个字符
// 例如return "科幻" 中的 "科幻" 是一个字符串字面量，存储在只读数据区，其类型为 char[]，但在表达式中会退化为指向首字符的指针
char *get_genre_name(Genre genre) {
    switch (genre) {
    case SCIENCE_FICTION:
        return "科幻";
        break;
    case LITERATURE:
        return "文学";
        break;
    case HISTORY:
        return "历史";
        break;
    case TECHNOLOGY:
        return "科技";
        break;
    case OTHER:
        return "其他";
        break;
    default:
        return "未知";
        break;
    }
}

// 打印所有书籍信息
void print_book_info(Book *books, int count) {
    printf("------------------所有的书籍信息------------------\n");
    for (int i = 0; i < count; i++){
        printf("编号：%d，书名：%s，作者：%s，类别：%s\n", books[i].id, books[i].title, books[i].author, get_genre_name(books[i].genre));
    }
}

// 根据书籍类别打印书籍
void find_books_by_genre(Book *books, int count, Genre genre) {
    for (int i = 0; i < count; i++) {
        if (books[i].genre == genre) {
            printf("编号：%d，书名：%s，作者：%s\n", books[i].id, books[i].title, books[i].author);
        }
    }
}


int main(void) {
    
    Book books[MAX_BOOKS] = {
    {1, "三体", "刘慈欣", SCIENCE_FICTION},
    {2, "红楼梦", "曹雪芹", LITERATURE},
    {3, "中国通史", "吕思勉", HISTORY},
    {4, "时间简史", "史蒂芬·霍金", TECHNOLOGY},
    {5, "围城", "钱钟书", LITERATURE},
    {6, "傲慢与偏见", "简·奥斯汀", LITERATURE},
    {7, "呼啸山庄", "艾米莉·勃朗特", LITERATURE},
    {8, "活着", "余华", LITERATURE},
    {9, "明朝那些事儿", "当年明月", HISTORY},
    {10, "乌合之众", "古斯塔夫·勒庞", OTHER}
    };

    print_book_info(books, MAX_BOOKS);
    printf("\n");

    int choice;
    printf("请输入书籍类别编号 (0: 科幻, 1: 文学, 2: 历史, 3: 科技, 4: 其他)来查询书籍：");
    scanf("%d", &choice);
    // 注意需要将输入的整数强制转换为枚举类型
    printf("类别为 %s 的书籍有：\n", get_genre_name((Genre)choice));
    find_books_by_genre(books, MAX_BOOKS, (Genre)choice);

    return 0;
}