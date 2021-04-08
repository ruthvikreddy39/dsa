#include<stdio.h>
#include<stdlib.h>
struct Node{
    int v,index;
    struct Node* left;
    struct Node* right;
};
int LCA(struct Node** root,int n1,int n2,int current){
    if(root[current]->v > root[n1]->v && root[current]->v > root[n2]->v) 
        LCA(root,n1,n2,root[current]->left->index);
    else if(root[current]->v < root[n1]->v && root[current]->v < root[n2]->v) 
        LCA(root,n1,n2,root[current]->right->index);
    else return current;
}
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    struct Node* arr[n];
    for(int i=0;i<n;i++){
        arr[i]=(struct Node*)malloc(sizeof(struct Node));
        int u;
        scanf("%d",&u);
        arr[i]->v=u;
        arr[i]->index=i;
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
    }
    int u,v;
    int r[q];
    for(int i=0;i<q;i++){
        scanf("%d %d",&u,&v);
        r[i]=LCA(arr,u,v,0);
    }
    for(int i=0;i<q;i++){
        printf("%d",r[i]);
        if(i<q-1)printf(" ");
    }
    //printf("%d",LCA(arr,5,6,0));
    return 0;
}