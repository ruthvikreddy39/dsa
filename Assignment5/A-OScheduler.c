#include<stdio.h>
struct task{
    int e,p,pos;
};
void swap(struct task *arr, int n1,int n2){
    struct task temp;
    temp.e=arr[n1].e;
    temp.p=arr[n1].p;
    temp.pos=arr[n1].pos;
    arr[n1].e=arr[n2].e;
    arr[n1].p=arr[n2].p;
    arr[n1].pos=arr[n2].pos;
    arr[n2].e=temp.e;
    arr[n2].p=temp.p;
    arr[n2].pos=temp.pos;
}
int comp(struct task *arr,int a,int b){
    if(arr[a].p<arr[b].p) return 1;
    else if(arr[a].p==arr[b].p){
        if(arr[a].e<arr[b].e){
            return 1;
        }
    }
    return 0;
}
//min-heapify function
void MinHeapify(struct task *a,int i,int size){
    int l= 2*i+1;
    int r= 2*i+2;
    int smallest=i;
    if((l<size)&&comp(a,l,i))smallest=l;
    else smallest =i;
    if((r<size)&&comp(a,r,smallest))smallest =r;
    if(smallest!=i){
        swap(a,i,smallest);
        MinHeapify(a,smallest,size);
    }
}
//build min-heap function
void BuildMin(struct task *a,int size){
    for(int k=size/2-1;k>=0;k--){
        MinHeapify(a,k,size);
    }
}
int main(){
    int t,k;
    scanf("%d %d",&t,&k);
    struct task arr[t];
    for(int i=0;i<t;i++){
        scanf("%d %d",&arr[i].e,&arr[i].p);
        arr[i].pos=i;
    }
    BuildMin(arr,t);
    int size=t;
    for(int j=t-1;j>t-k;j--){
        printf("%d ",arr[0].pos);
        swap(arr,0,j);
        size--;
        MinHeapify(arr,0,size);
    }
    //swap(arr,2,3);
    printf("%d",arr[0].pos);
    return 0;
}