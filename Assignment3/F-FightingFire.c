#include<stdio.h>
#include<stdlib.h>
struct Node{
    int v;
    struct Node* next;
};
struct Node* addNode(int d){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->v=d;
    newNode->next=NULL;
    return newNode;
}
void pushf(struct Node** list,int v){
    struct Node* temp=addNode(v);
    struct Node* base=*list;
    if(base==NULL) *list=temp;
    else{
        while(base->next!=NULL){
            base=base->next;
        }
        base->next=temp;
    }
}
//to delete the first node, since FIFO
int popf(struct Node** list){
    struct Node* temp=*list;
    int i;
    if(temp==NULL) return -1; 
    else{
        *list=(*list)->next;
        int i=temp->v;
        free(temp);
        return i;
    }
}
void DFS(struct Node** adjList,int s,int *visited,int size){
    visited[s]=1;
    struct Node* root=adjList[s];
    while(root!=NULL){
        if(visited[root->v]==0){
            DFS(adjList,root->v,visited,size);
        }
        root=root->next;
    }
}
int numbercomp(struct Node** adjList,int size,int *visited){
    int count=0;
    for(int i=0;i<size;i++){
        if(visited[i]==0){
            DFS(adjList,i,visited,size);
            count++;
            printf("%d %d\n",count,i);
        }
    }
    return count;
}
int main(){
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    int visited[n];
    //int count=0;
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    struct Node* adjList[n];
    for(int i=0;i<n;i++){
        adjList[i]=NULL;
    }
    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        pushf(&adjList[u],v);
        pushf(&adjList[v],u);
    }
    int c=numbercomp(adjList,n,visited);
    printf("%d",c);
    return 0;
}