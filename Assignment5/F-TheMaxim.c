#include<stdio.h>
void DFS(int *a,int *v,int i,int n){
    v[i]=1;
    printf("%d",i+1);
    for(int k=0;k<n;k++){
        if(*((a+i*n)+k)==1 && v[k]==0){
            DFS(a,v,k,n);
        }
    }
}
int main(){

    int n,m;
    scanf("%d %d",&n,&m);
    int adj[n][n];
    int visited[n];
    for(int j=0;j<n;j++){
        visited[j]=0;
    }
    for(int i=0,u,v;i<m;i++){
        scanf("%d %d",&u,&v);
        adj[u-1][v-1]=1; adj[v-1][u-1]=1;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            DFS(&adj[0][0],visited,i,n);
        }
    }
    return 0;
}