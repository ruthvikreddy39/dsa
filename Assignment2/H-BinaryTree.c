#include<stdio.h>
//fynction to return aggregate
int agg(int a[],int p,int s,int n){
    if(n==0){
        return s;
    }
    int l=1;
    for(int j=0;j<p-1;j++){
        l = l*2;
    }
    for(int k=0;k<l;k++){
        s+=(a[k]*p);
    }
    agg(a+l,p+1,s,n-l);
}
int main(){
    int n,arr[n],sum;
    scanf("%d",&n);
    for(int k=0;k<n;k++){
        scanf("%d",&arr[k]);
    }
    sum=agg(arr,1,0,n);
    printf("%d",sum);
    return 0;
}