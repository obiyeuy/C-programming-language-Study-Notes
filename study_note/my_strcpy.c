#include<stdio.h>
#include<string.h>
#include<assert.h>

void my_strcpy(char* dest, char* src){
    assert(dest != NULL);
    assert(src != NULL);

    while(*dest++ = *src++){
        ;
    }
    *dest = *src;   //将\0复制给dest
}
int main(){
    char arr1[] = "abcdefgh";
    char arr2[] = "bit";

    my_strcpy(arr1, arr2);
    printf("%s\n", arr1);
    printf("bit\0yyb");   //此时输出bit  所有的【字符串操作函数】，都会遇0而止
    return 0;
}