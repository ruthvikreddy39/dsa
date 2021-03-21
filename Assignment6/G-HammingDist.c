#include<stdio.h>
int hammingdist(int a,int b){
    int x=a^b;
    int set=0;
    while(x>0){
        set += x&1;
        x >>=1;
    }
    return set;
}
int minham(int *a,int n1,int n2,int n){
    if(2*n1+1<n && 2*n1+2<n && 2*n2+1<n && 2*n2+2<n){
       if(a[2*n1+1]==-1)a[2*n1+1]=a[n1];
    if(a[2*n1+2]==-1)a[2*n1+2]=a[n1];
    if(a[2*n2+1]==-1)a[2*n2+1]=a[n2];
    if(a[2*n2+2]==-1)a[2*n2+2]=a[n2];
    int min=hammingdist(a[2*n1+1],a[2*n2+1]);
    for(int j=1;j<3;j++){
        for(int k=1;k<3;k++){
            if(hammingdist(a[2*n1+j],a[2*n2+k])<min) min=hammingdist(a[2*n1+j],a[2*n2+k]);
        }
    }
    return min; 
    }
}
int main(){
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int aloc=0,bloc=0;
    for(int i=0;i<n;i++){
        if(arr[i]==a)aloc=i;
        else if(arr[i]==b)bloc=i;
    }
    if(aloc==0 || bloc==0){
        printf("-1"); return 0;
    }
    printf("%d",minham(arr,aloc,bloc,n));
    return 0;
}