#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* addNode(int d){
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data=d;
    newNode->next=NULL;
    return newNode;
}
void push(struct Node** root,int d){
    struct Node* temp = addNode(d);
    temp->next=*root;
    *root=temp;
}
void printList(struct Node* root){
    struct Node* temp=root;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void reverseList(struct Node** root){
    struct Node* after=NULL;
    struct Node* prev=NULL;
    struct Node* temp=*root;
    while(temp!=NULL){
        after=temp->next;
        temp->next=prev;
        prev=temp;
        temp=after;
    }
    *root=prev;
}
void multiply(struct Node* root,int start,int k){
    int c=k-start;
    while(c>0){
        root->data=(root->data)*k;
        root=root->next;
        c--;
    }
}
void reversek(struct Node** root,int start,int k){
    int a=start,i=0;
    struct Node* temp1=*root;
    while(i!=a){
        temp1=temp1->next;
        i++;
    }
    int c=k;
    struct Node* after=NULL;
    struct Node* prev=NULL;
    struct Node* temp=temp1;
    struct Node* right=temp1;
    while(c>0){
        right=right->next;
        c--;
    }
    c=k;
    prev=right;
    while(c>0){
        after=temp->next;
        temp->next=prev;
        prev=temp;
        temp=after;
        c--;
    }
    *root=prev;
}
int main(){
    int n,k,u;
    scanf("%d %d",&n,&k);
    struct Node* root=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&u);
        push(&root,u);
    }
    int b[k];
    for(int i=0;i<k;i++){
        scanf("%d",&b[i]);
    }
    reverseList(&root);
    printList(root);printf("\n");
    /*int s=0;
    for(int i=0;i<k;i++){
        multiply(root,s,b[i]);
        reversek(&root,s,b[i]);
        s+=b[i];
    }*/
    reversek(&root,3,2);
    printList(root);
    //reverseList(&root);
    //printList(root);
    //reversek(&root,0,3);
    //printf("\n");
    //multiply(root,0,3);
    //printList(root);
    return 0;
}