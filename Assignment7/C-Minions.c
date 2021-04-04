#include<stdio.h>
#define MAX 100000
int largestcont(int *b,int n,int *result){
    int i,count,max=0,min1,min2=MAX;
    for(int j=0;j<n;j++){
        if(b[j]!=-1 && j<n-1){
            count=0;i=j;min1=b[j];
            while(b[i]!=-1 && i<n){
                count+=1; //check here if wrong
                if(b[i]<min1)min1=b[i];
                i++;
            }
            if(count>max)max=count;
            if(min1<min2)min2=min1;
        }
    }
    result[1]=min2;
    result[0]=max;
    return result[0];
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int grid[n][m],row[n],column[m],r[2],c[2];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&grid[i][j]);
        }
    }
    int count;
    /*for(int i=0;i<n;i++){
        count=0;
        for(int j=0;j<m;j++){
            if(grid[i][j]==0)count++;
        }
        if(count>0)row[i]=-1;
        else row[i]=n-count;
    }*/
    for(int j=0;j<m;j++){
        count=0;
        for(int i=0;i<n;i++){
            if(grid[i][j]==0)count++;
        }
        if(count>0)column[j]=-1;
        else column[j]=m-count;
    }
    printf("%d",n*largestcont(column,m,c));
    return 0;
}