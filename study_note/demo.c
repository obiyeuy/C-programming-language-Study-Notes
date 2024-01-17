#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

int main(){

    char arr1[] = "welcome to bit!!!!!!";
    char arr2[] = "                    ";  //strcmp(arr1,arr2)  ,左等于右返回0，左大于右返回正数，小于则返回负数。

    int left = 0;
    int right = strlen(arr1) - 1; //int right = sizeof(arr1)/sizeof(arr1[0]) - 2;

    while(left<=right){
        arr2[left] = arr1[left];
        arr2[right] = arr1[right];
        
        //休息一秒
        Sleep(1000);  //windows.h
        system("cls");  //执行系统命令的一个函数，cls----清空屏幕
        printf("%s\n", arr2);
        left++;
        right--;
        
    }
    return 0;

    
}