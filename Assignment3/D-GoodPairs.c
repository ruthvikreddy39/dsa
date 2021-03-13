#include<stdio.h>

int main(){
    int n,k1,k2,count=0;
    scanf("%d %d %d",&n,&k1,&k2);
    int a[n],b[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    for(int p=0;p<n;p++){
        for(int q=p+1;q<n;q++){
            for(int r=0;r<n;r++){
                for(int s=r+1;s<n;s++){
                    if((p==r)&&(q==s)){
                        if((a[p]+a[q]+k1)>(b[r]+b[s]+k2))count++;
                    }
                }
            }
        }
    }
    printf("%d",count);
    return 0;
}