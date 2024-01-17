# include<stdio.h>
# include<math.h>

int main(){
    int i = 0;
    for (i = 0; i <= 100000;i++){

        int n = 1;
        int tmp = i;
        int sum = 0;
        while(tmp /= 10){
            n++;
        }
        tmp = i;
        while(tmp){
            sum += pow(tmp % 10, n);  // pow 返回float数  
            tmp /= 10;
        }
        if(i==sum){
            printf("%d ", i);
        }
    }
    return 0;
}