#include<stdio.h>

int main(){
    int n,l;
    scanf("%d %d",&n,&l);
    int a[n],b[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int j=0;j<n;j++){
        scanf("%d",&b[j]);
    }
    int safety=b[0],prev,temp;
    for(int i=1;i<n;i++){
        if((a[i]-a[prev])>l){
            temp=safety;
            safety+=b[i];
            prev=i;
        }
    }
    if((n-1)-prev>0){
        for(int i=prev+1;i<n;i++){
            if((temp+b[i])>safety){
                safety=temp+b[i];
                temp=safety;
            }
        }
    }
    printf("%d",safety);
    return 0;
}