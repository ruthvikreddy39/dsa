#include<stdio.h>

int div(int n,int d[]){
    //returns number of divisors other than one and itself
    int count=0,max=0;
    for(int j=2; j<=n/2;j++){
        if(n%j==0){
            if(count==0){
                d[1]=n/j; 
                d[0]=j; 
            }
            else if(count!=0 && j>d[0] && j<d[1]){
                d[0]=j;
            }
            count++;
        }
    }
    if(count>0)return count;
    else return 0;
}
int main(){
    int n,d[2]={0};
    //d[]=max2,max1
    scanf("%d",&n);
    if(div(n,d)<=1){
        printf("%d",n);
    }
    else if(div(n,d)>=2){
        printf("%d",d[0]+d[1]);
    }
    return 0;
}