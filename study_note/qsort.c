#include<stdio.h>
#include<stdlib.h>

struct Stu{    
    char name[20];    
    int age;
};

int cmp_int(const void* e1,const void* e2){
    return *(int *)e1 - *(int *)e2;
}

float cmp_float(const void* e1,const void* e2){
    return *(float *)e1 - *(float *)e2;
}


int cmp_stu_by_age(const void* e1,const void* e2){
    return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

void test2(){
    float f[] = {3.0, 4.0, 1.0, 5.0};
    int sz = sizeof(f) / sizeof(f[0]);
    qsort(f, sz, sizeof(f[0]), cmp_float);
}
void test3(){
    struct Stu s[3] = {{"张三", 20}, {"李四", 30}, {"王五", 10}};
    int sz = sizeof(s) / sizeof(s[0]);
    qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
}

// int main(){
//     // void*类型的指针 可以接收任意类型的地址(int*  char*)
//     // void*类型的指针不能进行解引用操作,也不能进行+-整数操作

//     // int a = 10;
//     // void *p = &a;

//     int arr[10] = {3, 4, 1, 6, 5, 7, 9, 2, 8, 0};
//     int sz = sizeof(arr) / sizeof(arr[0]);
    

//     qsort(arr, sz, sizeof(arr[0]), cmp_int);

//     int i = 0;
//     for (i = 0; i < 10;i++){
//         printf("%d ", arr[i]);
//     }
    
//     return 0;
// }   

