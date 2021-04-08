#include<stdio.h>
#include<stdlib.h>
struct Node{
    int v;
    struct Node* left;
    struct Node* right;
};

int main(){
    int n,t;
    scanf("%d %d",&n,&t);
    struct Node* arr[n];
    for(int i=0;i<n;i++){
        arr[i]=(struct Node*)malloc(sizeof(struct Node));
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
    }
    char str[10];
    char temp;
    int u;
    for(int i=0;i<t;i++){
        scanf("%s",str);
        scanf("%c",&temp);
        scanf("%d",&n);
    }
    return 0;
}