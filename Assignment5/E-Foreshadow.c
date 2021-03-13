#include<stdio.h>
int floorav(int a, int b){
    if((a+b)%2==0)return (a+b)/2;
    else return ((a+b)-1)/2;
}
int absolute(int a){
    if(a<0) return -1*a;
    else return a;
}
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
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n+k];
    int s=n,maxd,d,maxi=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int j=0;j<k;j++){
        maxd=absolute(a[0]-a[1]);
        for(int p=0;p<n-1;p++){
            d=absolute(a[p]-a[p+1]);
            if(d>maxd){
                maxd=d;
                maxi=p;
            }
        }
        a[s]=floorav(a[maxi],a[maxi+1]);
        s+=1;
        quicksort(a,0,s-1);
    }
    maxd=absolute(a[0]-a[1]);
    for(int p=0;p<n-1;p++){
        d=absolute(a[p]-a[p+1]);
        if(d>maxd)maxd=d;
    }
    printf("%d",maxd);
    return 0;
}