#include<stdio.h>

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int adj[n][n],visited[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j]=-1;
        }
        visited[i]=0;
    }
    int u,v,e;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&e);
        adj[u][v]=e;
        adj[v][v]=e;
    }
}