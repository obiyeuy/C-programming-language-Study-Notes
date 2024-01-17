#include<stdio.h>
 
int Add(int x, int y){
    return x + y;
}

int Sub(int x, int y){
    return x - y;
}

int Mul(int x, int y){
    return x*y;
}

int Div(int x, int y){
    return x/y;
}

void menu(){
    printf("--------------------\n");
    printf("----1.add  2.sub----\n");
    printf("----3.mul  4.div----\n");
    printf("-------0.exit-------\n");
    printf("--------------------\n");
}


void Calc(int (*pf)(int,int)){  //可以将函数指针传入
    int x = 0;
    int y = 0;
    printf("请输入两个操作数：");
    scanf("%d %d", &x, &y);
    printf("%d\n", pf(x, y));  //在calc函数中调用其他函数，调用同(*pf)(x, y)
}


int main(){
    int (*pa)(int, int) = Add;   //存函数的地址，需要先声明是一个指针，如int* pa(int, int)就是一个函数，不能存地址，与数组指针类似
    // 函数指针是存放函数地址的指针,格式：前面int是返回类型，后面两个int是传入参数类型

    int z = (*pa)(8,9);  //使用函数时先解引用
    printf("%d\n", z);

    // (*(void (*)()0))();
    // void (*signal(int, void (*)(int)))(int); 有趣的代码

    // typedef void(*pfun_t)(int);  //typedef关键字，将这种函数指针重定义为pfun_t类型
    // pfun_t signal(int,pfun_t);  即为void (*signal(int, void (*)(int)))(int);


    printf("%d\n", (pa)(2, 3));
    printf("%d\n", (*pa)(2, 3));
    // printf("%d\n", (**pa)(2, 3));  //均可，*对函数指针调用时没有影响
    // printf("%d\n", (***pa)(2, 3));

    int input = 0;
    int x = 0;
    int y = 0; 

     do{
        menu();
        printf("请选择：");
        scanf("%d", &input);

        switch(input){
            case 1:
                Calc(Add);  // 回调函数,此时Add被称为回调函数
                break;     // 回调函数就是一个通过函数指针调用的函数。
            case 2:        //如果你把函数的指针（地址）作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。
                Calc(Sub); //回调函数不是由该函数的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应
                break;
            case 3:
                Calc(Mul);
                break;
            case 4:
                Calc(Div);
                break;
            case 0:
                printf("退出。");
                break;
        }
    } while (input);

   
    int (*parr[4])(int, int) = {Add, Sub, Mul, Div};   //parr是函数指针的数组
    int i = 0;
    for (i = 0; i < 4;i++){
        printf("%d\n", parr[i](9, 3));  //函数指针数组的使用 
    }   //函数指针数组 - 转移表  （case时调用函数较多时可以使用,使代码不显得繁杂）

    return 0;
}



