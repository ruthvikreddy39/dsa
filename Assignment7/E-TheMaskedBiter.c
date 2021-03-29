#include<stdio.h>
#include<stdlib.h>
#define MAX 10000
int parity(int a,int b){
    int c=a,d=b,p=0;
    while(c>0 && d>0){
        if((c%10)%2!= (d%10)%2)p++;
        c=c/10; d=d/10;
    }
    if(c==0){
        while(d>0){
            if((d%10)%2!=0)p++;
            d=d/10;
        }
    }
    else if(d==0){
        while(c>0){
            if((c%10)%2!=0)p++;
            c=c/10;
        }
    }
    return p;
}
int findnumber(char* str){
    int num=0,i=0,j;
    while(str[i]!='\0'){
        if(str[i]>='0'&&str[i]<='9'){
            j=i;
            while(str[j]>='0'&&str[j]<='9'){
                num=(10*num)+(str[j]-48);
            }
        }
        i++;
    }
    return num;
}
struct Node{
    int data;
    struct Node* next;
};
struct Node* addNode(int d){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=d;
    newNode->next=NULL;
    return newNode;
}
void add(struct Node** root,int x){
    struct Node* temp=addNode(x);
    temp->next=*root;
    *root=temp;
}
void delete(struct Node** root, int x){
    struct Node* temp=*root;
    struct Node* prev=NULL;
    while(temp->data!=x){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)return;
    prev->next=temp->next;
    //temp->next=NULL;
    free(temp);
}
int query(struct Node* root, int q){
    int eq=0;
    struct Node* temp=root;
    while(temp!=NULL){
        if(parity(temp->data,q)==0) eq++;
        temp=temp->next;
    }
    return eq;
}
int main(){
    int n; int ans[n],p=0;
    char temp;
    char str[MAX];
    long long int num;
    struct Node* list;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",str);
        scanf("%lld",&num);
        scanf("%c",&temp);
        if(str[0]=='a')add(&list,num);
        else if(str[0]=='d')delete(&list,num);
        else if(str[0]=='q'){
            ans[p]=query(list,num);
            p++;
        }
    }
    for(int k=0;k<p;k++){
        printf("%d",ans[k]);
        if(k<p-1)printf("\n");
    }
    return 0;
}