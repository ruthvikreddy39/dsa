#include<stdio.h>
// a mod b
int mod(int a,int b){
    if(a%b==0) return 0;
    else{
        int d=a/b;
        return (a-b*d);
    }
}
void swap(int *a,int *b){
    int temp;
    temp=*a;*a=*b;*b=temp;
}
//max-heapify
void MaxHeapify(int *a,int i,int size,int k){
    int l=2*i+1;
    int r=2*i+2;
    int largest=i;
    if(l<size && mod(a[l],k)>mod(a[i],k))largest=l;
    else if(l<size && mod(a[l],k)==mod(a[i],k)){
        if(a[l]>a[i])largest=l;
    }
    else largest=i;
    
    if(r<size && mod(a[r],k)>mod(a[largest],k))largest=r;
    else if(r<size && mod(a[r],k)==mod(a[largest],k)){
        if(a[r]>a[largest])largest=r;
    }

    if(largest!=i){
        swap(&a[largest],&a[i]);
        MaxHeapify(a,largest,size,k);
    }
}
//buil max heap
void BuildMax(int *a,int size,int k){
    for(int j=size/2-1;j>=0;j--){
        MaxHeapify(a,j,size,k);
    }
}
void Heapsort(int *a,int size,int k){
    BuildMax(a,size,k);
    int len=size;
    for(int j=size-1;j>=1;j--){
        swap(&a[0],&a[j]);
        len--;
        MaxHeapify(a,0,len,k);
    }
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    Heapsort(arr,n,k);
    //BuildMax(arr,n,k);
    //MaxHeapify(arr,1,5,2);
    for(int i=0;i<n-1;i++){
        printf("%d ",arr[i]);
    }
    printf("%d",arr[n-1]);
    return 0;
}