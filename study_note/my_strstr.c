#include<stdio.h>
#include<string.h>
#include<assert.h>

char* my_strstr(char* p1,char* p2){
    assert(p1 != NULL);
    assert(p2 != NULL);
    char *s1 = p1;
    char *s2 = p2;
    char *cur = (char *)p1;
    if(*p2 == '\0')
    {
        return p1;
    }
    while(*cur)
    {
        s1 = cur;
        s2 = (char *)p2;
        while(*s1 &&*s2 &&(*s1 == *s2))
        {
            s1++;
            s2++;

        }
        if(*s2 =='\0')
        {
            return cur;
        }
        cur++;
    }
    return NULL;
}

int main(){
    char* p1="abcdefabcdef";
    char *p2 = "def";

    char *ret = my_strstr(p1, p2);

    if(ret==NULL){
        printf("字串不存在。");


    }else{
        printf("字串存在，起始之后为%s\n", ret);

    }

    return 0;
}