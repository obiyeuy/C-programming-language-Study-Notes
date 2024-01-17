 #include<stdio.h>

// int main(){
//     int arr[10] = {0, 1, 2, 3, 4, 5, 6,7, 8, 9};
//     int(*p)[10] = &arr;  // int* p[10] 会报错,因为p先与括号结合成为数组，再与*结合成为指针数组，但&arr为地址，矛盾  invalid initializer
//     // 此时p是数组指针，是指向数组的指针

//     // 注意：&数组名表示的是取出整个数组的地址，而不是首元素地址，所以它+1步长跳过整个数组
//     return 0;
// }    

void print1(int arr[3][5], int x, int y){
    int i = 0;
    int j = 0;
    for (i = 0; i < x;i++){
        for (j = 0; j < y;j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void print2(int(*p)[5],int x,int y){    // 数组指针一般用于二维数组
    int i = 0;
    for (i = 0; i < x; i++)
    {
        int j = 0;
        for (j = 0; j < y; j++)
        {
            printf("%d ", (*(p + i))[j]);
        }
        printf("\n");
    }
}

int main(){
    int arr[3][5] = {{1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}, {3, 4, 5, 6, 7}};
    print1(arr, 3, 5);  // arr - 数组名 - 数组名就是首元素地址(二维数组首元素是第一个数组的地址)
    printf("\n");
    print2(arr, 3, 5);

    return 0;
}


// int main(){
//     char* arr[5];
//     char* (*pa)[5] = &arr;  //&arr为指针，所以为(*pa),又为数组指针，则加上[5],而数组中类型为char*,即最后加上char*

//     return 0;
// }