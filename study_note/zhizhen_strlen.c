#include<stdio.h>

int my_strlen(char* str){
    char* start = str;
    char* end = str;
    while(*end != '\0'){
        end++;
    }
    return end - start;  // 两指针相减为元素个数
}

int main(){
    char arr[] = "bit";
    int len= my_strlen(arr);
    printf("%d\n",len);

    return 0;
} 