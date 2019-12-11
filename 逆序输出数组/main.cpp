#include<stdio.h>
//cstdlib库  这里用来创建伪随机数   详细:https://baike.baidu.com/item/cstdlib/5519425?fr=aladdin
#include<cstdlib>
//定义全局变量 N = 10 用于确定数组大小
#define N 10

int main() {
    //声明数组 array 长度为 N = 10
    int array[N];

    printf("创建随机数组:\n");
    //通过循环向 array 数组中添加(修改)元素
    for (int i = 0; i < N; i++) {
        //给数组 array 的元素添加值，rand()为cstdlib库内函数，用于生成(伪)随机数
        //array[i] 表示 数组 array 的第 i 个元素，例：array[0] 为第一个，array[1] 为第二个，array[大小 - 1] 为最后一个
        array[i] = rand();
        printf("%d ", array[i]);
    }

    printf("\n逆序输出数组:\n");
    //逆序输出，使循环量 i 通过从 数组 array 的最后一个(N - 1)减小到第 0 个
    //Q：为什么从 N - 1 开始，而不从 N 开始
    //S：因为数组从 0 开始为第一个元素，当数组大小为 N 时，数组的最后一个元素编号为 N - 1
    for (int i = N - 1; i >= 0; i--) {
        //简单的输出
        printf("%d ", array[i]);
    }
    //别管这一行...有没有都无所谓...
    printf("\n");
    
    return 0;
}