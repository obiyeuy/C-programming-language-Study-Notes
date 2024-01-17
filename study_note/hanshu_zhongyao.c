// IO函数：input,output
// 字符串操作函数：strlen,strcpy(字符串拷贝，包括\0)
// 字符操作函数
// 内存操作函数：memset(memory - 内存，set - 设置：要导入库string.h) 
// 时间/日期函数
// 数学函数    math.h
// 其他库函数

#include<stdio.h>
#include<string.h>

// void Swap1(int x, int y){
//     int tmp = 0;
//     tmp = x;
//     x = y;
//     y = tmp;
// }    只在函数内操作，但是外面没有改变

void Swap2(int *pa , int *pb){
    int tmp = 0;
    tmp = *pa;
    *pa = *pb;
    *pb = tmp;   //传指针可以实现
}


int main(){
    char arr[] = "hello world";

    memset(arr , '*' , 5);  //复制字符 c（一个无符号字符）到参数 str 所指向的字符串的前 n 个字符
    printf("%s\n" , arr);
     

    int a = 19;
    int b = 20;
    // Swap1(a , b); 
    //此函数无法交换a,b的值，因为x,y重新开辟了地址，只交换了x,y的值，没有交换a,b的值
    //即传值调用
    Swap2(&a , &b); //传址调用   传址调用可以实现
    printf("a = %d , b = %d" , a , b);

    return 0;
}


//传值调用：函数的形参与实参分别占有不同的内存块，对形参的修改不影响实参
//传址调用：把函数外部创建的内存地址传递给函数参数的一种使用函数的方式，这样函数内部才能真正调用函数外部的变量

// 常用函数
// assert()  #include<assert.h>  //断言，传入表达式为真，什么都不发生；为假，会抛出错误
// strcpy(1,2)  #include<string.h>   //将2复制给1
// strncpy(str1,str2,n)   将str2前n个字符拷贝给str1(str2不足n个，会在其后面补\0补够)
// strcat(arr1, arr2)   将arr2字符串追加在arr1后面(追加过程是找到arr2中\0后停止)  注：不能自己追加自己，不然会崩溃  char arr1[] = 'abc';
// strncat(arr1,arr2,n)   将arr2中n个字符追加在arr1后，追加完后会加上\0 (arr2不足n个，则不会补足，只将str2全部补在str1后)
// strncmp(str1,str2,n)   比较两字符串前n个字符，后面不比较
// strstr(str1,str2)  看str2是否是str1的字串，找到后返回第一个字串的起始地址，没找到返回NULL
// strtok(str1,str2)   按照str2分割str1，返回被分解的第一个字符串

// qsort(*s, n, sizeof(s[0]), cmp); - 可以排序任意类型的数据    //int (*cmp)(const void *,const void *);
    // 其中第一个参数s是一个地址，即参与排序的首地址；
    // n是需要排序的数量；
    // sizeof(s[0])则是每一个元素占用的空间大小；
    // 指向函数的指针，用于确定排序的顺序。
    // 简单的说：对一个长为1000的数组进行排序时，int a[1000];

// memcpy(void* dest, const void*src, size_t count)

// scanf()  遇到空格会停止读取

// gets()  读取一行

// malloc()  需要对其返回值的判断
// free()
// calloc()
// realloc()  最好用一个新变量来接受realloc函数的返回值





// char* p = "abcdef";     则p[0]==*(p+0)=='a';