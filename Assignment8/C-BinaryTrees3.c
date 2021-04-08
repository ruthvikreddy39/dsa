//uses stack 
#include<stdio.h>
#include<stdlib.h>
struct tNode{
    int v;
    struct tNode* left;
    struct tNode* right;
};
struct sNode{
    struct tNode* node;
    struct sNode* next;
};
int main(){
    int n;
    scanf("%d",&n);
    struct tNode* arr[n];
    for(int i=0;i<n;i++){
        arr[i]=(struct tNode*)malloc(sizeof(struct tNode));
        int u;
        scanf("%d",&u);
        arr[i]->v=u;
        arr[i]->left=NULL;
        arr[i]->right=NULL;
    } 
    char temp;
    for(int i=0;i<n-1;i++){
        int u,v;
        char c;
        scanf("%d %d ",&u,&v);
        scanf("%c",&c);
        scanf("%c",&temp);
        if(c=='R') arr[u]->right=arr[v];
        else if(c=='L') arr[u]->left=arr[v];
    }//input is taken 
    struct tNode* current=arr[0];//root of the tree
    struct sNode* stackroot=NULL; 
    int done=0;
    while(done==0){
        //if left child exists push it to stack
        if(current!=NULL){
            struct sNode* temp=(struct sNode*)malloc(sizeof(struct sNode));
            temp->node=current;
            temp->next=stackroot;
            stackroot=temp;
            current=current->left;
        }
        //if it doesn't exist pop the uppermost element 
        //in stack and print it
        else{
            if(stackroot){
                struct sNode* temp1=stackroot;
                stackroot=stackroot->next;
                printf("%d ",(temp1->node)->v);
                free(temp1);
                current=current->right;
            }
            else done=1;
        }
    }
    return 0;
}