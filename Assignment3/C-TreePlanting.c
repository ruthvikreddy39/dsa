#include<stdio.h>

int isFeasible(int mid, int arr[], int n, int k)
{
    int pos = arr[0];
    int elements = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] - pos >= mid) {
            pos = arr[i];
            elements++;
            if (elements == k)
                return 1;
        }
    }
    return 0;
}
int largestMinDist(int arr[], int n, int k)
{

    int res = 0;
    int left = 1, right = arr[n - 1];
    while (left < right) {
        int mid = (left + right) / 2;
        if (isFeasible(mid, arr, n, k)==1) {
            if(mid>res)
                res = mid;
            left = mid+1;
        }
        else
            right = mid;
    }
 
    return res;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[m];
    for(int i=0;i<m;i++){
        scanf("%d",&arr[i]);
    }
     for(int i=0;i<m-1;i++){
        for(int j=0;j<m-i-1;j++){
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
        }
    }
    int min = largestMinDist(arr,m,n);
    printf("%d",min);
    return 0;
}