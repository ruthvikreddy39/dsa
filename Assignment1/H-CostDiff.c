#include<stdio.h>
#include<stdlib.h>

void rotate(int a[],int len){
    int n1,n2,n3;
    n1=a[len-1];
    n2=a[0];
    n3;
    for(int i=0;i<len;i++){
        if(i==0){
            a[i]=n1;
            continue;
        }
        n3=a[i];
        a[i]=n2;
        n2=n3;
    }
    
}
int main(){
    int n,arr[500],c[500],d;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&d);
        arr[i]=d;
    }
    
    int max,min,cost,o=0,e=0;
    for(int i=0;i<n;i++){
        o=0,e=0;
        for(int j=0; j<n;j++){
            if(j%2 == 0)
                e+= arr[j]*arr[j];
            else if(j%2 == 1)
                o+= arr[j]*arr[j]*arr[j];
        }
        cost=e-o;
        c[i]=cost;
        rotate(arr,n);
    }
    max=c[0],min=c[0];
    for(int i=0;i<n;i++){
        if(c[i]>max)max=c[i];
        else if(c[i]<min)min=c[i];
    }
    printf("%d",max-min);
    return 0;
}