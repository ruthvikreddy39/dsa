#include<stdio.h>
unsigned int hash(unsigned int x){
    x = x%65535;
    x *= (x+13);
    x = x%(65535);
    return x;
}
int iteration(unsigned int *arr, int size){
    if(size==1) return arr[0];
    int len= size/2;
    if(size%2==1) len++;
    unsigned int buf[len];
    int c=0,i=0;
    unsigned int mul;
    while(i<size){
        if(i==size-1)mul=arr[i];
        else mul=arr[i]*arr[i+1];
        buf[c]=hash(mul);
        c++; i+=2;
    }
    iteration(buf,len);
}
int main(){
    int n;
    scanf("%d",&n);
    unsigned int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",iteration(arr,n));
    //printf("%d",hash(n));
    return 0;
}