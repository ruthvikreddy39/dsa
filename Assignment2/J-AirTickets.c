#include<stdio.h>
#include<stdlib.h>
struct Node{
    int v;
    struct Node* next;
};
//function to print a list
void printList(struct Node *n){
    while(n != NULL){
        printf("%d", n->v);
        n = n->next;
    }
}
//function to add a node
void add(struct Node **head_ref,int d){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->v=d;
    if(*head_ref==NULL){
        temp->next=NULL;
        *head_ref=temp;
    }
    else{
        temp->next=*head_ref;
        *head_ref=temp;
    }
}
//function to delete a node-at the end
int del(struct Node **head_ref){
    struct Node* temp = *head_ref;
    if(temp==NULL){
        return -1;
    }
    else if(temp->next==NULL){
        int i= temp->v;
        *head_ref=NULL;
        free(temp);
        return i;
    }
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    int j=temp->next->v;
    struct Node* p=temp->next;
    free(p);
    return j;
}
void BFS(struct Node** head_ref,struct Node** q,int i, int d,int v[],int *c){
    int vertex;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp = *head_ref;
    *q=NULL;
    if(*c==0)add(q,i);
    v[i]=1;
    while(temp!=NULL){
        vertex = temp->v;
        //*c+=1;
        if(vertex==d) return;
        if(v[vertex]!=1)add(q,vertex);
        v[vertex]=1;
        temp=temp->next;
    }
    del(q);
    //temp=*q;
    /*while(temp->next!=NULL){
        temp=temp->next;
    }*/
    BFS(head_ref,q,i,d,v,c);
}
int main(){
    int n,m,s,t,count=0;
    scanf("%d %d %d %d\n",&n,&m,&s,&t);
    struct Node* arr[n];
    struct Node* queue;
    for(int i=0;i<n;i++){
        arr[i]=NULL;
    }
    int c,d;
    for(int j=0;j<m;j++){
        scanf("%d %d",&c,&d);
        add(&arr[c],d);
        add(&arr[d],c);
    }//adjacency list is created
    int visited[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    BFS(&arr[s],&queue,s,t,visited,&count);
    printf("%d",count);
    return 0;
}