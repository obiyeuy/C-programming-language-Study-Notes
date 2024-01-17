#include<stdlib.h>
#include<time.h>
#include <stdio.h>
int main(){
    int ret = 0;
    srand((unsigned int)time(NULL));
    ret = rand();  //0到32767之间的随机数
    printf("%d\n", ret);

    return 0;
}