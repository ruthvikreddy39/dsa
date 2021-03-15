#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

void add(struct node **s, int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->link = NULL;
    temp->data = data;
    if(*s==NULL){
        *s = temp;
    }else{
        struct node *p = *s;
        while(p->link!=NULL){
            p=p->link;
        }
        p->link = temp;
    }
}

void min_heapify(int *arr, int i, int size){
    int l = 2*i+1;
    int r = 2*i+2;
    int smallest  = i;
    if(l<size&&arr[l]<arr[i])
        smallest = l;
    if(r<size&&arr[r]<arr[smallest])
        smallest = r;
    if(smallest!=i){
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
        min_heapify(arr, smallest, size);
    }
}

void build_min_heap(int *arr, int size){
    for(int i=size/2-1;i>=0;i--){
        min_heapify(arr, i,size);
    }
}

int heap_add(int *arr, int *reached, struct node **s,int v, int count){
    struct node *temp = s[v];
    while(temp!=NULL){
        if(reached[temp->data]==0){
            arr[count] = temp->data;
            count++;
            reached[temp->data]=1;
        }
        temp = temp->link;
    }
    return count;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n-1];
    int reached[n];
    for(int i=0;i<n-1;i++){
        arr[i] = 100001;
        reached[i] = 0;
    }
    reached[n-1] = 0;
    reached[0] = 1;
    struct node *g[n];
    for(int i=0;i<n;i++){
        g[i]=NULL;
    }

    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        add(&g[a-1],b-1);
        add(&g[b-1],a-1);
    }
    int count = 0;
    int popped = 0;
    count = heap_add(arr, reached, g, popped, count);
    while(arr[0]!=100001){
        printf("%d ",popped+1);
        build_min_heap(arr, count);
        popped = arr[0];
        arr[0] = arr[count - 1];
        arr[count-1] = 100001;
        count--;
        count = heap_add(arr, reached, g, popped, count);
    }
    printf("%d ",popped+1);
    //this is an extra comment

    return 0;
}
