//uses stack
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* addNode(int data){
    struct Node* stackNode= (struct Node*)malloc(sizeof(struct Node));
    stackNode->data=data;
    stackNode->next=NULL;
    return stackNode;
}
int isEmpty(struct Node* root){
    return !root;
}
void push(struct Node** root, int data){
    struct Node* stackNode = addNode(data);
    stackNode->next = *root;
    *root = stackNode;
}
int pop(struct Node** root){
    if(isEmpty(*root)) return INT_MIN;
    struct Node* temp=*root;
    *root=(*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}
int peek(struct Node* root){
    if(isEmpty(root)) return INT_MIN;
    return root->data;
}
int size(struct Node* root){
    int s=0;
    struct Node* temp = root;
    while(temp!=NULL){
        s++;
        temp = temp->next;
    }
    return s;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    struct Node *root = NULL;
    push(&root,arr[0]);
    for(int j=1;j<n;j++){
        if(arr[j]>=peek(root)) push(&root,arr[j]);
        else{
            int last=pop(&root);
            while(size(root)>0 && arr[j]<peek(root))pop(&root);
            push(&root,last);
        }
    }
    printf("%d",size(root));
    return 0;
}