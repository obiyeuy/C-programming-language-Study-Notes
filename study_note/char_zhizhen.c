#include <stdio.h>

int main()
{
       // const char* p = "abcdef";
       // // 不加const 则*p = 'y';  调试时Segmentation fault

       // printf("%c\n", *p);   // a
       // printf("%s\n", p);    // abcdef

       // return 0;
       char arr1[] = "abcdef";
       char arr2[] = "abcdef";

       const char *p1 = "abcdef"; // ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]  即最好加const
       const char *p2 = "abcdef";

       if (p1 == p2)
       {
              printf("haha\n");
       }
       else
       {
              printf("hehe\n");
       } // haha  p1与p2为常量字符串，不会再改变，且比较后字符串一样，则p1与p2存的首地址一样

       // if(arr1 ==arr2){
       //        printf("haha\n");
       // }else{
       //        printf("hehe\n");
       // }   // hehe  因为arr1与arr2存地址，两者相比是比较地址一定不一样
       return 0;  

}