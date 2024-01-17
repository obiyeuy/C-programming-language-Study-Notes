#include<stdio.h>
#include<string.h>

int main(){
    char arr[]={'a','b','c','d','e','f'};
    // strlen传入一个地址，然后从此地址向后找，会找到\0才会停止，不包括\0
    // sizeof是计算变量(先看变量是什么类型，地址为4/8，不同类型则所占内存不同)在内存的占空间的大小，单位是字节(地址是4/8字节)


    printf("%d\n", strlen(arr));  //随机值
    printf("%d\n", strlen(arr+0));  //随机值
    // printf("%d\n", strlen(*arr));  //err
    // printf("%d\n", strlen(arr[1]));  //err  内存非法访问

    // printf("%d\n", strlen(&arr));      // 随机值
    // printf("%d\n", strlen(&arr + 1));  // 随机值-6  会警告，但能编译运行
    printf("%d\n", strlen(&arr[0] + 1));   //随机值-1

    return 0;
}