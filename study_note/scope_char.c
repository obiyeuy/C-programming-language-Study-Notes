#include<stdio.h>
#include<string.h>

int main(){
    char a[1000];
    int i;
    for(i = 0;i < 1000;i++){
        a[i] = -1-i;   // singed char范围为-1,-2...-128,127,126,...1,0  因为char中数值是-128~127 左闭右闭,其余的数都会截断至这个区间内
    }                  // unsiged char 范围是0~255 左闭右闭
    printf("%d\n", strlen(a));   //255  strlen()返回\0(0)前的个数

    return 0;
}