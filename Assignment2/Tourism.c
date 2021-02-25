
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int v;
    struct Node* next;
};
//function to add a node
void add(struct Node** head_ref, int d){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->v=d;
    if(*head_ref==NULL){
        temp->next=NULL;
        *head_ref=temp;
    }
    else{
        temp->next= *head_ref;
        *head_ref=temp;
    }
}
//function to delete a node
void del(struct Node **head_ref){
    struct Node* temp = *head_ref;
    *head_ref=temp->next;
    free(temp);
}

void BFS(struct Node** head_ref,struct Node** q,int v[]){
    struct Node* temp = *head_ref;
    int vertex;
    vertex = temp->v;
    add(q,vertex);
    while(temp!=NULL){
        vertex = temp->v;
        if(v[vertex]!=1)add(q,vertex);
        v[vertex]=1;
        temp=temp->next;
    }
}
int main(){
    int n,m;
    int visited[1000]={0};
    scanf("%d %d",&n,&m);
    struct Node* arr[n];
    struct Node* queue;
    for(int i=0;i<n;i++){
        arr[i]=NULL;
    }
    int s,d;
    for(int i=0; i<m; i++){
        scanf("%d %d",&s,&d);
        add(&arr[s],d);
    }//adjacency list created
    int visited[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }

    return 0;
}