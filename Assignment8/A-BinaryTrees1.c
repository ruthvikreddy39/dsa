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
struct sNode* addNode(struct tNode* node){
    struct sNode* stackNode= (struct sNode*)malloc(sizeof(struct sNode));
    stackNode->node=node;
    stackNode->next=NULL;
    return stackNode;
}
int isEmpty(struct sNode* root){
    return !root;
}
void push(struct sNode** root, struct tNode* node){
    struct sNode* stackNode = addNode(node);
    stackNode->next = *root;
    *root = stackNode;
}
void pop(struct sNode** root){
    if(isEmpty(*root)) return ;
    struct sNode* temp=*root;
    *root=(*root)->next;
    //struct tNode* popped = temp->node;
    free(temp);
    //return popped;
}
struct tNode* peek(struct sNode* root){//ERROR
    if(isEmpty(root)) return NULL;
    return root->node;
}

void zigzagTraversal(struct tNode* root,int n){
    
    if (!root) return;
    struct sNode* currentLevel=NULL;
    struct sNode* nextLevel=NULL;

    push(&currentLevel,root);
    int lefttoright=0;
    int i=0;
    while(!isEmpty(currentLevel)){
        struct tNode* temp=peek(currentLevel);
        pop(&currentLevel);

        if(temp){
            printf("%d ",temp->v);i++;
            //if(i<n)printf(" ");
            if (lefttoright%2==0) {
                if (temp->left)
                    push(&nextLevel,temp->left);//nextlevel.push(temp->left);
                if (temp->right)
                    push(&nextLevel,temp->right);//nextlevel.push(temp->right);
            }
            else{
                if (temp->right)
                    push(&nextLevel,temp->right);//nextlevel.push(temp->right);
                if (temp->left)
                    push(&nextLevel,temp->left);//nextlevel.push(temp->left);
            }
        }
        if (isEmpty(currentLevel)) {
            lefttoright += 1;
            //swap(currentlevel, nextlevel); ERROR
            struct sNode* temp1;
            temp1=currentLevel;
            currentLevel=nextLevel;
            nextLevel=temp1;
        }
    }
}
int main(){
    int n,u,v;
    char c;
    scanf("%d",&n);
    struct tNode* a[n];
    for(int i=0;i<n;i++){
        a[i]=(struct tNode*)malloc(sizeof(struct tNode));
        scanf("%d",&u);
        a[i]->v=u;
        a[i]->left=NULL;
        a[i]->right=NULL;
    } 
    char temp;
    for(int i=0;i<n-1;i++){
        scanf("%d %d ",&u,&v);
        scanf("%c",&c);
        scanf("%c",&temp);
        if(c=='R') a[u]->right=a[v];
        if(c=='L') a[u]->left=a[v];
    }
    zigzagTraversal(a[0],n);
    return 0;
}