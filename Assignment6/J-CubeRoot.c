#include<stdio.h>
int absolutediff(int a,int b){
    if(a<b) return b-a;
    else if(a>=b) return a-b;
}
int cuberoot(int n){
    double start=0,end=n;
    double e =0.0000001; //precision
    while(1){
        double mid=(start+end)/2;
        double error=absolutediff(n,mid*mid*mid);
        if(error<e) return (int)mid;
        
        if((mid*mid*mid)>n) end=mid;
        else start=mid;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int c;
    if(n<0){
        c=-1*cuberoot(-1*n);
    }
    else c=cuberoot(n);
    printf("%d",c);
    return 0;
}