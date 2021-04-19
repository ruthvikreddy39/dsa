//uses stack
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 100000
struct Node{
    int data,index;
    struct Node* next;
};
struct Node* addNode(int d,int i){
    struct Node* stackNode=(struct Node*)malloc(sizeof(struct Node));
    stackNode->data=d;
    stackNode->index=i;
    stackNode->next=NULL;
    return stackNode;
}
int isEmpty(struct Node *root){
    return !root;
}
void push(struct Node **root,int d,int i){
    struct Node* temp= addNode(d,i);
    temp->next=*root;
    (*root)=temp;
}
int peek(struct Node *root){
    if(isEmpty(root)) return INT_MIN;
    return root->index;
}
int listmin(struct Node* root){
    struct Node* temp=root;
    int min=root->data;
    while(temp!=NULL){
        if(temp->data<=min)min=temp->data;
        temp=temp->next;
    }
    return min;
}
int largestcont(int *b,int n,int *result,int *a){
    int i,count,max=0,min1,min2=MAX;
    for(int j=0;j<n;j++){
        if(b[j]!=-1 && j<n-1){
            count=0;i=j;min1=a[j];
            while(b[i]!=-1 && i<n){
                count++; 
                if(a[i]<min1)min1=a[i];
                i++;
            }
            if(count>max)max=count;
            if(min1<min2)min2=min1;
        }
    }
    result[1]=min2;
    result[0]=max;
    return result[0]*result[1];
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n],b[n],r[2];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    struct Node *root=NULL;
    //printf("-1 ");
    b[0]=-1;
    push(&root,arr[0],0);
    for(int i=1;i<n;i++){
        if(arr[i]>=listmin(root)){
            if(arr[i]==arr[peek(root)]) pop(&root);
            b[i]=peek(root)+1;
        }//printf("%d",peek(root)+1);
        else b[i]=-1;//printf("-1");
        if(i<n-1){
            if(arr[i]<arr[i+1]) push(&root,arr[i],i);
        }
    }
    /*for(int i=0;i<n;i++){
        printf("%d",b[i]);
    }*/
    int g=largestcont(b,n,r,arr);
    printf("\%d",g);
    return 0;
}