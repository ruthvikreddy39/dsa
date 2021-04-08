#include<stdio.h>
int maxsubSum(int *a,int n){
    int prevsum=a[0],maxcont=a[0];
    for(int i=1;i<n;i++){
        prevsum+=a[i];
        if(prevsum>maxcont){
            maxcont=prevsum;
            prevsum=maxcont;
        }
        if(prevsum<0) prevsum=0;
    }
    return maxcont;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",maxsubSum(arr,n));
    return 0;
}