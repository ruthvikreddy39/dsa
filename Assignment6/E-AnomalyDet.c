#include<stdio.h>
#include<stdlib.h>
struct point{
    int norm,index;
};
struct Node{
    float data;
    struct Node* next;
};
struct Node* addNode(float data){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data= data;
    temp->next=NULL;
    return temp;
}
void push(struct Node** root, float data){
    struct Node* node= addNode(data);
    node->next=*root;
    *root=node;
}
int size(struct Node* root){
    int s=0;
    struct Node* temp=root;
    while(temp!=NULL){
        s++;
        temp=temp->next;
    }
    return s;
}
void swap(struct point *a,int i,int j){
    struct point temp;
    temp.norm=a[i].norm;
    temp.index=a[i].index;
    a[i].norm =a[j].norm;
    a[i].index = a[j].index;
    a[j].norm = temp.norm;
    a[j].index=temp.index;
}
void MaxHeapify(struct point *a,int i,int size){
    int l=2*i+1,r=2*i+2,largest;
    largest=i;
    if(l<size && a[l].norm>a[i].norm)largest =l;
    else if(l<size && a[l].norm==a[i].norm){
        if(a[l].index>a[i].index)largest=l;
    }

    if(r<size && a[r].norm>a[largest].norm)largest =r;
    else if(r<size && a[r].norm==a[largest].norm){
        if(a[r].index>a[largest].index)largest=r;
    }
    if(largest!=i){
        swap(a,i,largest);
        MaxHeapify(a,largest,size);
    }
}
void BuildMax(struct point *a,int size){
    for(int k=size/2-1;k>=0;k--){
        MaxHeapify(a,k,size);
    }
}
void HeapSort(struct point *a,int size){
    BuildMax(a,size);
    int len=size;
    for(int j=size-1;j>=1;j--){
        swap(a,0,j);
        len--;
        MaxHeapify(a,0,len);
    }
}
int main(){
    int n,c,d,k;
    scanf("%d %d %d %d",&n,&c,&d,&k);
    float x[n],y[n];
    for(int i=0;i<n;i++){
        scanf("%f %f",&x[i],&y[i]);
    }
    struct point arr[n];
    struct Node* listx[c];
    struct Node* listy[d];
    for(int i=0;i<c;i++){
        listx[i]=NULL;
    }
    for(int i=0;i<d;i++){
        listy[i]=NULL;
    }
    int j,p;
    for(int i=0;i<n;i++){
        j=(int)x[i];p=(int)y[i];
        push(&listx[j],x[i]);
        push(&listy[p],y[i]);
    }
    int s1,s2;
    for(int i=0;i<n;i++){
        j=(int)x[i];p=(int)y[i];
        s1=size(listx[j]);
        s2=size(listy[p]);
        arr[i].norm=s1*s2;
        arr[i].index=i;
    }
    HeapSort(arr,n);
    for(int i=0;i<k;i++){
        printf("%d",arr[i].index);
        if(i<k-1)printf(" ");
    }
    return 0;
}