#include<stdio.h>
//function to find out bit-representation
void bin(unsigned n,int arr[],int l)
{
    if(l>0){
        if (n >=1){
            bin(n / 2,arr-1,l-1);
            *arr= n % 2;
        }
        else{
            bin(n / 2,arr-1,l-1);
            *arr= 0;
        }
    }
}
int main(){
    int m,n,i,d,max=0,items=0,cost=0;
    int arr[25],arr2[25];
    scanf("%d", &m);
    scanf("%d", &n);
    int k= (1<<n);
    for(i=0; i<n; i++){
        scanf("%d", &d);
        arr[i] = d;
    }
    for(int j=0;j<k;j++){
        items=0;cost=0;
        bin(j,&arr2[n-1],n);
        for(i=0;i<n;i++){
            if(arr2[i]==1){
                cost+=arr[i];
                items++;
            }
            if(cost<=m && items>max){
                max=items;
            }
        }
    }
    //xoxoxoxo
    printf("%d",max);
    return 0;
}