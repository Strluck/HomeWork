#include<iostream>
#include<stdio.h>
#define SPACE 32
#define ZERO_ASCII 48
#define TITLE "一 二 三 四 五 六 日"
#define LEAP1940 470 // 0到1940年间一共470个闰年
void monthPrintf(int year, int month);
void yearPrintf(int year);
void monthPrintfByLine(int year, int month, int line);
char* doubleNumberToChar(int num, bool is);
int getMonthDays(int year, int month);
bool isLeapYear(int year);
int oneDayIsWeek(int year, int month);

int main()
{
    while (true) {
        printf("输入你要查询的日历年(2020)或年月(2020-5)\n");
        printf("输入0或空白结束\n");
        printf(": ");

        char str[256] = {48, 48, 48, 48, 48, 48, 48};
        scanf("%[^\n]", &str);
        getchar();

        if (str[0] == '0') { // 是否退出
            return 0;
        }

        int year = (str[0] - 48) * 1000;
        year = year + (str[1] - 48) * 100;
        year = year + (str[2] - 48) * 10;
        year = year + (str[3] - 48);

        if (str[4] == '-') {
            int month = 0;
            if (str[5] == '1'&& (str[6] == '0' || str[6] == '1' || str[6] == '2')) {
                month = (str[5] - 48) * 10;
                month = month + (str[6] - 48);
            }
            else {
                month = str[5] - 48;
            }
            
            monthPrintf(year, month); // 打印月日历
        }
        else {
            yearPrintf(year); // 打印年日历
        }

        system("pause");
    }
}

/*
 * monthPrintf 打印月份日历
 * parameter: year  int 年份
 * parameter: month int 月份
 */
void monthPrintf(int year, int month) {
    char* str = doubleNumberToChar(month, false);
    printf("+------ %d-%c%c -------+\n", year, str[0], str[1]);
    printf("| 一 二 三 四 五 六 日 |\n|"); 
    for (int i = 1; i <= 6; i++) {
        monthPrintfByLine(year, month, i); // 打印月行数据
        printf(" |\n%c", i == 6 ? '+' : '|');
    }
    printf("----------------------+\n");
}

/*
 * yearPrintf 打印年份日历
 * parameter: year int 年份
 */
void yearPrintf(int year) {
    printf("+--------------------- %d ----------------------+\n", year);
    for (int i = 1; i <= 6; i++) {
        char* str = doubleNumberToChar(i + 6, true);
        printf("| %d 一 二 三 四 五 六 日  %c%c 一 二 三 四 五 六 日 |\n|  ", i, str[0], str[1]);
        for (int j = 1; j <= 6; j++) {
            monthPrintfByLine(year, i, j);
            printf("    ");
            monthPrintfByLine(year, i + 6, j);
            if (j == 6) {
                printf(" |\n");
            }
            else {
                printf(" |\n|  ");
            }
        }
    }
    printf("+-------------------------------------------------+\n");
}

/* 
 * monthPrintfByLine 打印月份日历中的某一行
 * parameter: year  int 年份
 * parameter: month int 月份
 * parameter: line  int 输出月份日历的行号(1-6)
 */
void monthPrintfByLine(int year, int month, int line) {
    int week = oneDayIsWeek(year, month);

    char monthString[21] = {};
    int lineOne = 7 - week + 1; // 第一行有几天
    int n = 0;
    if (line == 1) {
        // 打印第一行前面的空格
        for (int i = 0; i < week - 1; i++) {
            for (int j = 0; j < 3; j++) {
                monthString[n++] = SPACE;
            }
        }
        // 打印第一行剩余的天数
        for (int i = 1; i <= lineOne; i++) {
            monthString[n++] = SPACE;
            char* tooNum = doubleNumberToChar(i, true);
            monthString[n++] = tooNum[0];
            monthString[n++] = tooNum[1];
        }
    }
    else {
        int dayMax = getMonthDays(year, month); // 获取本月最大天数
        line = (line - 2) * 7;
        for (int i = 1; i <= 7; i++) { // 打印一行共7天
            monthString[n++] = SPACE;
            int day = i + lineOne + line;
            if (day > dayMax) { // 超过最大天数后打印空格
                monthString[n++] = SPACE;
                monthString[n++] = SPACE;
                continue;
            }
            // 打印日期
            char* tooNum = doubleNumberToChar(day, true);
            monthString[n++] = tooNum[0];
            monthString[n++] = tooNum[1];
        }
    }

    for (int i = 0; i < 21; i++) {
        printf("%c", monthString[i]);
    }
}

/*
 * doubleNumberToChar 将两位数int转换为Char
 * parameter: num int  两位数
 * parameter: is  bool 是否使用空格替换0
 * return:    char*    两位数的Char数组，长度2
 */
char* doubleNumberToChar(int num, bool is) {
    int too = num / 10 + ZERO_ASCII;
    if (is) {
        too = too == ZERO_ASCII ? SPACE : too;
    }
    int one = num % 10 + ZERO_ASCII;
    char r[2] = { too, one };
    return r;
}

/*
 * getMonthDays 获取某年中某月的天数
 * parameter: year  int 年份
 * parameter: month int 月份
 * return:    int       天数
 */
int getMonthDays(int year, int month) {
    if (month == 2) { // 二月进行闰年判断
        return isLeapYear(year) ? 29 : 28;
    }
    month = month > 7 ? month : month - 7;
    return month % 2 ? 30 : 31;
}

/*
 * isLeapYear 是否为闰年
 * parameter: year int 年份
 * return:    bool
 */
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

/*
 * oneDayIsWeek 获取某个月的第一天是周几
 * parameter: year  int 年份
 * parameter: month int 月份
 * return:    int       周
 */
int oneDayIsWeek(int year, int month) {
    /* 
     * 已知1940年1月1日为周一，且为闰年
     * 通过逐年增加天数计算其他月份
     */

    // 计算当前月距离当前年1月1日有多少天
    int day = 0;
    for (int i = 1; i < month; i++) {
        day = day + getMonthDays(year, i);
    }

    // 计算0到year之间有多少个闰年
    int leap = year / 4;
    leap = leap - (year / 100);
    leap = leap + (year / 400);
    // 减去0到1940年间一共的闰年数量 得到1940到year间闰年数
    leap -= LEAP1940;
    // 计算距离1940年1月1日有多少天
    day = day + leap + (year - 1940) * 365;
    return (day % 7) + 1;
}