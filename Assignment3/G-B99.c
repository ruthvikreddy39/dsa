#include<stdio.h>

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int M[m],N[n],opt[n];
    for(int i=0;i<n;i++){
        opt[i]=0;
    }
    for(int i=0;i<m;i++){
        scanf("%d",&M[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&N[i]);
    }
    for(int j=0;j<n;j++){
        for(int k=0;k<m;k++){
            if(N[j]>=M[k])opt[j]+=1;
        }
    }
    for(int i=0;i<n;i++){
       printf("%d",opt[i]);
       if(i!=n-1)printf(" ");
    }
    return 0;
}