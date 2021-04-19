//uses stack
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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
void pop(struct Node** root){
    struct Node* temp=*root;
    if(*root==NULL)return;
    else{
        *root=(*root)->next;
        free(temp);
    }
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
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    struct Node *root=NULL;
    printf("-1 ");
    push(&root,arr[0],0);
    for(int i=1;i<n;i++){
        if(arr[i]>=listmin(root)){
            if(arr[i]==arr[peek(root)]) pop(&root);
            printf("%d",peek(root)+1);
        }
        else printf("-1");
        if(i<n-1){
            if(arr[i]<arr[i+1]) push(&root,arr[i],i);
        }
        if(i<=n-1) printf(" ");
    }
    return 0;
}