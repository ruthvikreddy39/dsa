#include<stdio.h>
struct per{
    int num;
    float x,y,slope;
};
void swap(struct per *arr, int n1,int n2){
    struct per temp;
    temp.x=arr[n1].x;
    temp.y=arr[n1].y;
    temp.num=arr[n1].num;
    temp.slope=arr[n1].slope;
    arr[n1].x=arr[n2].x;
    arr[n1].y=arr[n2].y;
    arr[n1].num=arr[n2].num;
    arr[n1].slope=arr[n2].slope;
    arr[n2].x=temp.x;
    arr[n2].y=temp.y;
    arr[n2].num=temp.num;
    arr[n2].slope=temp.slope;
}
float slope(struct per *a,int i,int j){
    float yd= a[j].y-a[i].y;
    float xd= a[j].x-a[i].x;
    return yd/xd;
}
void MaxHeapify(struct per *a,int i,int size){
    int l=2*i+1,r=2*i+2,largest;
    largest=i;

    if(l<size && a[l].slope>a[i].slope)largest =l;
    else if(l<size && a[l].slope==a[i].slope){
        if(a[l].x<a[i].x)largest=l;
    }

    if(r<size && a[r].slope>a[largest].slope)largest =r;
    else if(r<size && a[r].slope==a[largest].slope){
        if(a[r].x<a[largest].x)largest=r;
    }

    if(largest!=i){
        swap(a,i,largest);
        MaxHeapify(a,largest,size);
    }
}
void BuildMax(struct per *a,int size){
    for(int k=size/2-1;k>=0;k--){
        MaxHeapify(a,k,size);
    }
}
void HeapSort(struct per *a,int size){
    BuildMax(a,size);
    int len=size;
    for(int j=size-1;j>=1;j--){
        swap(a,0,j);
        len--;
        MaxHeapify(a,0,len);
    }
}
int main(){

    int n;
    scanf("%d",&n);
    struct per arr[n];
    for(int i=0;i<n;i++){
        scanf("%d %f %f",&arr[i].num,&arr[i].x,&arr[i].y);
    }
    int all=0;
    for(int i=0;i<n;i++){
        if(arr[i].y<arr[all].y) all=i;//gives index of all might
    }
    int q=arr[all].num;
    for(int i=0;i<n;i++){
        if(i!=all) arr[i].slope=slope(arr,all,i);
        else arr[i].slope=0;
    }
    HeapSort(arr,n);
    int p;
    for(int i=0;i<n;i++){
        if(arr[i].num==q)p=i;
    }
    for(int j=p+1;j<n;j++){
        printf("%d ",arr[j].num);
    }
    for(int j=0;j<p;j++){
        printf("%d",arr[j].num);
        if(j<p-1)printf(" ");
    }
    return 0;

}