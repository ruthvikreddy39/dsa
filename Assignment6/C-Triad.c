#include<stdio.h>
#include<stdlib.h>
struct machines{
    int time,number;
};
void swap(struct machines *a,int i,int j){
    struct machines temp;
    temp.time=a[i].time;
    temp.number=a[i].number;
    a[i].time =a[j].time;
    a[i].number = a[j].number;
    a[j].time = temp.time;
    a[j].number=temp.number;
}
void MaxHeapify(struct machines *a,int i,int size){
    int l=2*i+1;
    int r=2*i+2;
    int largest=i;
    if(l<size && a[l].time>a[i].time)largest=l;
    else largest=i;
    if(r<size && a[r].time>a[largest].time)largest=r;
    if(largest!=i){
        swap(a,largest,i);
        MaxHeapify(a,largest,size);
    }
}
void BuildMax(struct machines *a,int size){
    for(int k=size/2-1;k>=0;k--){
        MaxHeapify(a,k,size);
    }
}
void HeapSort(struct machines *a,int size){
    BuildMax(a,size);
    int len=size;
    for(int j=size-1;j>=1;j--){
        swap(a,0,j);
        len--;
        MaxHeapify(a,0,len);
    }
}
int finish(struct machines *a,int sec,int j){
    int finish=0;
    if(sec%a[j].time==0)finish++;
    return finish;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    struct machines arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i].time);
        arr[i].number=0;
    }
    HeapSort(arr,n);
    
    int count=k,i=1;
    arr[0].number+=1; count--;
    while(count>0){
        for(int j=0;j<n;j++){
            if(finish(arr,i,j)==1){
                arr[j].number+=1;
                count--;
            }
        }
        i++;
    }
    int max=0;
    for(int j=0;j<n;j++){
        if(arr[j].number*arr[j].time>max)max=arr[j].number*arr[j].time;
    }
    printf("%d",max);
    return 0;
}