#include<stdio.h>

// struct Stu{  
//     char name[20];
//     int age;
//     char id[20];
// }s1,s2,s3;   //定义类型的同时定义变量s1,s2,s3

typedef struct Stu{    //结构体  //typedef将struct Stu类型重命名为Stu.
    char name[20];    //结构体中变量可以是结构体
    int age;
    char id[20];

}Stu;  //注意：Stu处还可以用于可变列表输入，注意两者区别

int main(){
    int a = 10;
    // struct Stu s1 = {"张三" , 20 , "123456783456"};

    Stu s1 = {"张三", 20 , "123456783456"};  //两者均可

    // printf("%s\n",s1.name);
    // printf("%d\n",s1.age);
    // printf("%s\n",s1.id);   //1.结构体变量.成员变量

    struct Stu* ps = &s1;
    // printf("%s\n" , (*ps).name); //*ps解引用，找到s1
    // printf("%d\n" , (*ps).age);
    printf("%s\n" , ps->name);
    printf("%d\n" , ps->age);   //2这种方法更好，不会开辟临时空间，占空间更小
    //2.结构体指针->成员变量

    return 0;
}