#include <stdio.h>

int check_sys()
{ // 弄成函数，方便别人使用
    int a = 1;
    // char*p = (char*)&a;  // 需要强制类型转换  initialization of 'char *' from incompatible pointer type 'int *'
    // //返回1，小端；返回0，大端
    // return *p;

    return *(char *)&a; // 简化
}

int main()
{
    int ret = check_sys();
    if (ret == 1)
    {
        printf("小端\n"); // 不要在函数中打印，万一别人不需要打印就比较麻烦
    }                     //小端0x12345678 存储为0x12345678
    else
    {
        printf("大端\n");
    }

    return 0;
}