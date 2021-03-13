#include<stdio.h>
//floor function
int floor3(int a){
    if(a%3==1) return (a-1)/3;
    else if(a%3==2) return (a-2)/3;
    else return a/3;
}
//function to find max
int maxof(int a[],int len,int *index){
    *index=0;
    int max=a[0];
    for(int k=0;k<len;k++){
        if(a[k]>=max){
            max=a[k];
            *index=k;
        }
    }
    return max;
}
int main(){
    int n,d,max=0,index;
    scanf("%d %d",&n,&d);
    int b[n];
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    for(int i=0;i<d;i++){
        max+=maxof(b,n,&index);
        b[index]=floor3(b[index]);
    }
    printf("%d",max);
    return 0;
}