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
int main(){
    int m;
    scanf("%d",&m);
    int q[m];
    for(int i=0;i<m;i++){
        scanf("%d",&q[i]);
    }
    quicksort(q,0,m-1);
    int diff, ways;
    diff = q[m-1]-q[0];
    int n1,n2,j=1,c=1;
    while(q[j]==q[0]){
        c++;
        j++;
    }
    n1=c;c=1;
    j=m-2;
    while(q[j]==q[m-1]){
        c++;
        j--;
    }
    n2=c;
    printf("%d %d",diff,n1*n2);
    return 0;
}