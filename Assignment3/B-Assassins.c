#include<stdio.h>

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int skill[n],steal[n];
    int body[m][2];
    for(int i=0;i<n;i++){
        scanf("%d",&skill[i]);
    }
    for(int i=0;i<n;i++){
        steal[i]=0;
    }
    for(int j=0;j<m;j++){
        scanf("%d %d",&body[j][0],&body[j][1]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(skill[i]>=body[j][0]){
                steal[i]+=body[j][1];
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d",steal[i]);
        if(i!=n-1) printf(" ");
    }
    return 0;
}