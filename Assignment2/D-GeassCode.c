/*#include<stdio.h>
void mul(int p[],int a[],int n,int m,int c){
    if(c>n-m){
        return;
    }
    int j;
    for(j=0;j<m;j++){
        *(p+j)= p[j]*a[j];
    }
    mul(p+1,a,n,m,c+1);
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int p[n],a[m];
    for(int i=0; i<n; i++){
        scanf("%d",&p[i]);
    }
    for(int i=0; i<m; i++){
        scanf("%d",&a[i]);
    }
    mul(p,a,n,m,0);
    for(int i=0; i<n; i++){
        printf("%d",p[i]);
        if(i!=n-1)printf(" ");
    }
    return 0;
}*/