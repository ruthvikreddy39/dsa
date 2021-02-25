#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[1000][1000]={0},u,v;
    int visited[1000];
    for(int i=0; i<m; i++){
        scanf("%d %d",&u,&v);
        arr[u-1][v-1]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
