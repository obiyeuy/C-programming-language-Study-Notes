#include<stdio.h>
#include<string.h>

int main(){
    if(strlen("abc") - strlen("abcdef")>0){
        printf("hehehe");   // hhh strlen()返回无符号数
    }else{
        printf("hahaha");
    }
    
    return 0;
}