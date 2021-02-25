#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int n,m,i,j,u,v;
    int arr[500][500]={0};
    int colour[500]={0};
    scanf("%d %d", &n,&m);
    for(i=0; i<m; i++){
        scanf("%d %d", &u,&v);
        arr[u][v]=1;
        arr[v][u]=1;
    }
    colour[0]=1;
    for(i=0; i<n; i++){
        for(j=0;j<n;j++){
            if(arr[i][j]==1){
                if(colour[i]==1)colour[j]=2;
                else if(colour[i]==2)colour[j]=1;
            }
        }
    }
    for(i=0; i<n; i++){
        if(colour[i]==0){
            printf("NEED MORE COLOURS");
            exit(0);
        }
    }
    for(i=0; i<n; i++){
        if(colour[i]==1)
            printf("R");
        else if(colour[i]==2)
            printf("B");   
    }
    return 0;
}