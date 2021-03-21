#include<stdio.h>
int mod(int a,int b){
    if(a%b==0) return 0;
    else{
        int d=a/b;
        return (a-b*d);
    }
}
int lower(int *a,int ti, int current,int size){
    return mod(ti+current,size);
}
int upper(int *a,int lower,int size){
    if(lower==0) return size-1;
    else return lower-1;
}
int main(){
    int n,t;
    scanf("%d %d",&n,&t);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int ti,l,u,c=0;
    for(int j=0;j<t;j++){
        scanf("%d",&ti);
        l=lower(arr,ti,c,n);
        u=upper(arr,l,n);
        c=l;
        printf("%d %d",arr[l],arr[u]);
        if(j<t-1)printf("\n");
    }
    return 0;
}