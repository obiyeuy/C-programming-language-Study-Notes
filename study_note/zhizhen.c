#include<stdio.h>

int main(){
   printf("%d\n",sizeof(int*));  //64位系统指针变量内存大小为8字节，32位为4字节,是固定的
   printf("%d\n",sizeof(short*));
   printf("%d\n",sizeof(char*));
   printf("%d\n",sizeof(double*));

   int a = 0x11223344;
   int* pa = &a;        // const int* p     const放在指针变量*左边时，修饰的是*p也就是说不能通过p来改变*p(num)的值
                        // int *const p      const放在指针变量*右边时，修饰的是指针变量p本身，p不能被改变了
   char* pc = (char*)&a;   // char* pc = &a;编译不通过，需要强制类型转换  error: cannot convert 'int*' to 'char*' in initialization
    
   printf("%p\n", pa);
   printf("%p\n", pc); // 编译通过后两个一样，都能存地址，但意义不同，步长不一样，如下

   printf("%p\n",pa+1);   //加4
   printf("%p\n",pc+1);   //加1   

   *pa = 0;  // 能访问四个字节，即为0x00000000
   *pc = 0;  // 只改变了一个字节，即为0x11223300   (编译通过后两者的区别，不能过会报错)
             // double* 可以访问8个字节
             
   // 指针类型决定了指针解引用操作时，能够访问空间的大小,还决定了指针的步长(即一次走多远)

   return 0;
}