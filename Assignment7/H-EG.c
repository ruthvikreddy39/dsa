#include<stdio.h>
int absolute(int a,int b){
    if(a>=b) return a-b;
    else return b-a;
}
int parent(int i){
    if(i%2==1) return (i-1)/2;
    else return (i-2)/2;
}
int leftchild(int *a,int i,int n){
    int l=2*i+1,c=0;
    if(l<n){
        if(a[l]!=-1)c++;
    }
    return c;
}
int rightchild(int *a,int i,int n){
    int l=2*i+2,c=0;
    if(l<n){
        if(a[l]!=-1)c++;
    }
    return c;
}
int leftview(int *a,int n){
    int sum=a[0],i=1;
    while(i<n){
        if(a[i]!=-1)sum+=a[i];
        else if(a[i]==-1 && a[i+1]!=-1)sum+=a[i+1];
        i+=2;
    }
    return sum;
}
int rightview(int *a,int n){
    int sum=a[0],i=2;
    while(i<n){
        if(a[i]!=-1)sum+=a[i];
        else if(a[i]==-1 && a[i-1]!=-1)sum+=a[i-1];
        i+=2;
    }
    return sum;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int lsum=leftview(arr,n);
    int rsum=rightview(arr,n);
    printf("%d",absolute(lsum,rsum));
    return 0;
}