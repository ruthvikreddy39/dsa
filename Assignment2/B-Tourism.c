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
int BFS(struct Node** adjList,int s,int size){
    int visited[size];
    //intialise visted array to zero
    int count=0;
    for(int i=0;i<size;i++){
        visited[i]=0;
    }
    struct Node* queue=NULL;
    pushf(&queue,s);
    count++;
    visited[s]=1;
    while(queue!=NULL){
        int popped=popf(&queue);
        struct Node* temp=adjList[popped];
        while(temp!=NULL){
            if(visited[temp->v]==0){
                pushf(&queue,temp->v);
                count++;
                visited[temp->v]=1;
            }
            temp=temp->next;
        }
    }
    return count;
}
int main(){
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    struct Node* adjList[n];
    //initialise all lists to null
    //and then take inputs
    for(int i=0;i<n;i++){
        adjList[i]=NULL;
    }
    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        pushf(&adjList[u-1],v-1);
    }
    int max=0;
    for(int i=0;i<n;i++){
        int c = BFS(adjList,i,n);
        if(c>max)max=c;
    }
    printf("%d",max);
    return 0;
}