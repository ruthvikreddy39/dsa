#include<stdio.h>
int floor2(int a){
    if(a%2==0) return a/2;
    else (a-1)/2;
}
void swap(int *a,int *b){
    int temp;
    temp=*a;*a=*b;*b=temp;
}
//min-heapify function
void MinHeapify(int a[],int i,int n){
    int l= 2*i;
    int r= (2*i)+1;
    int min;
    if(l<=n && a[l]<=a[i]) min=l;
    else min=i;
    if(r<=n && a[r]<=a[min])min=r;
    if(min!=i){
        swap(&a[i],&a[min]);
        MinHeapify(a,min,n);
    }
}
//build min-heap
void Buildmin(int a[],int n){
    for(int j=floor2(n)-1;j>=0;j--){
        MinHeapify(a,j,n);
    }
}
//heapsort-modified
void Heapsortm(int a[],int n,int k){
    Buildmin(a,n);
    int len=n;
    for(int p=n-1;p>=n-k;p--){
        swap(&a[0],&a[p]);
        len=len-1;
        MinHeapify(a,0,len);
    }
}
int main(){
    int t,k,count;
    scanf("%d %d",&t,&k);
    int e[t],pr[t],done[t],indices[k];
    for(int i=0;i<t;i++){
        done[t]=0;
    }
    for(int i=0;i<t;i++){
        scanf("%d %d",&e[i],&pr[i]);
    }
    Heapsortm(pr,t,k);
    /*for(int i=0;i<t;i++){
        printf("%d ",pr[i]);
    }*/
    
    return 0;
}