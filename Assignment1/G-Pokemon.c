#include<stdio.h>
#include<string.h>

void DFS(int v[],int i,int n,int* a){
    //mark the vertex visited
    v[i]=1;
    //run this loop for all adjacent vertices
    for(int k=0; k<n; k++){
        //if a vertex is adjacent and non-visited
        if(*((a+i*n)+k)==1 && v[k]==0){
            DFS(v,k,n,a);
        }
    }
}
int main(){
    int n,m,u,v,i;
    int visited[500]={0},arr[500][500]={0};
    scanf("%d %d",&n,&m);
    //filling in adjacency matrix
    for(i=0; i<m;i++){
        scanf("%d %d",&u,&v);
        arr[u][v]=1;
        arr[v][u]=1;
    }
    /*for(i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }*/
    //finding components using dfs
    int comp=0;//number of components
    for(i=0; i<n ;i++){
        if(visited[i]==0){
            DFS(visited,i,n,&arr[0][0]);
            comp += 1;
        }
    }
    printf("%d",comp);
    return 0;
}