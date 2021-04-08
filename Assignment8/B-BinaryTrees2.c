#include<stdio.h>
#include<stdlib.h>

struct Node{
    int v;
    struct Node* left;
    struct Node* right;
};
unsigned long long int modulo(long long int s){
    unsigned long long int M=1000000007;
    return s%M;

}
int absolute(int a,int b){
    if(a>b)return a-b;
    else return b-a;
}
unsigned long long int sum(int *a,int *b,int *c,int n){
    long long int s=0;
    for(int i=0;i<n;i++){
        s+= (absolute(a[i],b[i]))*c[i];
    }
    return s;
}
void preorder(int *a,struct Node* root,int *i){
    //initially i=0 will be given in the call
    if(root==NULL) return;
    a[*i]=root->v;
    *i+=1;
    preorder(a,root->left,i);
    preorder(a,root->right,i);
}
void postorder(int *b,struct Node* root,int *i){
    //initially i=0 will be given in the call
    if(root==NULL) return;
    postorder(b,root->left,i);
    postorder(b,root->right,i);
    b[*i]=root->v;
    *i+=1;
}
void inorder(int *c,struct Node* root,int *i){
    //initially i=0 will be given in the call
    if(root==NULL) return;
    inorder(c,root->left,i);
    c[*i]=root->v;
    *i+=1;
    inorder(c,root->right,i);
}
int main(){
    int n;
    scanf("%d",&n);
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
    //printf("%d",arr[0]->right->v);
    int a[n],b[n],c[n];
    int point=0;
    preorder(a,arr[0],&point);
    point=0;
    postorder(b,arr[0],&point);
    point=0;
    inorder(c,arr[0],&point);
    printf("%lld",sum(a,b,c,n));
    return 0;
}