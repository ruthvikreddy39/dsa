#include<stdio.h>
//quicksort functions
int partition(int a[],int p, int r){
    int x=a[r];
    int i=p-1,temp;
    for(int j=p;j<r;j++){
        if (a[j]<=x){
            i+=1;
            temp=a[j];a[j]=a[i];a[i]=temp; //swap
        }
    }
    temp = a[i+1];a[i+1]=a[r];a[r]=temp; //swap
    return i+1;
}
void quicksort(int a[],int p, int r){
    if(p<r){
        int q=partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}
//function to find sum
int sum(int a[],int l){
    int s=0;
    for(int k=0;k<l;k++){
        s+=a[k];
    }
    return sum;
}
//function to perform queries
void query(int a[], int s[],int k,int p,int r){
    int diff,r1;
    r1=r-(k-1);
    quicksort(a,p,r1);
    diff=a[r1]-a[0];
    for(int j=0;j<r1-1;j++){
        a[j]=a[j+1];
    }
    a[r1-1]=diff;
    for(int j=r1;j<=r;j++){
        a[j]=0;
    }
    s[k-1]=sum(a,r);
}
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    int arr[n],sum[q];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<q;i++){
        query(arr,sum,i,0,n-1);
    }
    printf("%d",sum[2]);
    return 0;
}