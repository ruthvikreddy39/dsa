#include<stdio.h>
void swap(int *a,int *b){
    int temp;
    temp=*a;*a=*b;*b=temp;
}
int floor2(int a){
    if(a%2==0) return a/2;
    else return (a-1)/2;
}
int absolute(int a){
    if(a<0) return -1*a;
    else return a;
}
//min-heapify function
void MinHeapify(int a[],int i,int n){
    int l= (2*i)+1;
    int r= (2*i)+2;
    int largest;
    if(l<n && a[l]<a[i]) largest=l;
    else largest =i;
    if(r<n && a[r]<a[largest])largest =r;
    if(largest!=i){
        swap(&a[i],&a[largest]);
        MinHeapify(a,largest,n);
    }
}
//build min-heap
void Buildmin(int a[],int n){
    for(int j=floor2(n)-1;j>=0;j--){
        MinHeapify(a,j,n);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int len=(n+1)/2;
    int left[len],right[len],l=0,r=0;
    for(int j=0;j<n;j++){
        if(j==0){
            left[l]=a[j];
            printf("%d",left[l]);
            l++;
        }
        else{
            if((left[l-1]>a[j])&&absolute(l+1-r)<2){
                left[l]=a[j];
                Buildmin(left,l+1);
                l++;
            }
            else if((left[l-1]<a[j])&&absolute(l-r-1)<2){
                right[r]=a[j];
                Buildmin(right,r+1);
                r++;
            }
            else if((left[l-1]>a[j])&&absolute(l+1-r)>=2){
                right[r]=left[l-1];
                left[l-1]=a[j];
                Buildmin(left,l+1);
                Buildmin(right,r+1);
                r++;
                
            }
            else if((left[l-1]<a[j])&&absolute(l-r-1)>=2){
                left[l]=right[0];
                right[0]=a[j];
                Buildmin(right,r+1);
                Buildmin(left,l+1);
                l++;
            }
            if((j+1)%2==0) printf("%d",(left[l-1]+right[0])/2);
            else {
               if(l>r) printf("%d",left[l-1]);
               else printf("%d",right[0]);
            }
        }
        if(j<n-1) printf(" ");
    }
    /*for(int i=0;i<n;i++){
        printf("%d",a[i]);
    }*/
    return 0;
}