#include<stdio.h>
#include<string.h>
#include<assert.h>

char* my_strcat(char* dest,char* src){
    char *ret = dest;
    assert(dest != NULL);
    assert(src != NULL);

    while(*dest !='\0'){
        dest++;
    }

    while(*dest++ = *src++){
        ;
    }
    return ret;
}
int main(){
    char arr1[30] = "hello \0xxxxxx";
    char arr2[] = "world";
    my_strcat(arr1, arr2);    //追加是在第一个\0处追加，自己追加自己程序会崩溃
    printf("%s\n", arr1);

    return 0;
}