#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//function to check if a number is prime or not
int prime(int n){
    int count=0;
    for(int j=1; j<=n/2;j++){
        if(n%j==0)count++;
    }
    if(count==1)return 1;
    else return 0;
}
int main(){
    int p,q,i,arr[10]={0},d,k;
    scanf("%d %d", &p,&q);
    for(i=p;i<=q;i++){
        k=i;
        if(prime(i)==1){
            while((k/10)>0){
                d= k%10;
                arr[d]+=1;
                k=k/10;
            }
            arr[k]+=1;
        }
        else continue;
    }
    int max = arr[0];
    int digit =0 ;
    for(i=0;i<10;i++){
        if(arr[i]>max){
             max = arr[i];
             digit=i;
        }
    }
    printf("%d %d", digit,max);
    return 0;
}
