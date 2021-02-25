#include<stdio.h>

int main(){
    int n,match[200][200]={0};
    int miss[2];
    scanf("%d",&n);
    int w,l;
    for(int i=0;i<((n*(n-1))/2)-1;i++){
        scanf("%d %d",&w,&l);
        match[w-1][l-1]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                if(match[i][j]==1 || match[j][i]==1){}
                else{
                    miss[0]=i+1;
                    miss[1]=j+1;
                } 
            }
        }
    }
    w=miss[0]-1;l=miss[1]-1;
    int temp,count;
    for(int i=0;i<n;i++){
        if(match[w][i]==0 && match[l][i]==1) count++;
    }
    if(count!=0){
        //swap
        temp=miss[0];
        miss[0]=miss[1];
        miss[1]=temp;
    }
    printf("%d %d",miss[0],miss[1]);
    return 0;
}