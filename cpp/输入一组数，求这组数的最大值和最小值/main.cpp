#include<stdio.h>

int main() {
    //定义变量 n 用于输入数组长度
    int n;
    printf("请输入您数据的总个数:");
    scanf("%d", &n);

    //声明数组 array 长度为 n
    int array[n];

    printf("请输入您要比较的数据:\n");

    //其实接下来可以不用数组，但是本着学习的态度，用一下
    //通过循环向 array 数组中添加(修改)元素
    for (int i = 0; i < n; i++) {
        //array[i] 表示 数组 array 的第 i 个元素，例：array[0] 为第一个，array[1] 为第二个，array[大小 - 1] 为最后一个
        //给数组 array 输入值
        scanf("%d", &array[i]);
    }

    //定义变量 min 用于存放最小值，定义变量 max 用于存放最大值
    int min = __INT_MAX__, max = 0;

    //从 0 开始依次循环(遍历)数组 array
    for (int i = 0; i < n; i++) {
        //判断数组中的第 i 个元素是否比 min 小
        if (array[i] < min) {
            //有一说一，如果，array[i] 确实比已经记录的 min 还小，那么就将 array[i] 储存到 min 里
            min = array[i];
        }
        //同上比大
        if (array[i] > max) {
            max = array[i];
        }
    }

    //输出最小值 min 和最大值 max
    printf("最小值=%d, 最大值=%d\n", min, max);
    
    return 0;
}