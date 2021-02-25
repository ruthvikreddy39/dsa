/*#include<stdio.h>
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void bubbleSort(int arr[], int n) 
{ 
   int i, j,temp=0; 
   for (i = 0; i < n-1; i++){   
       for (j = 0; j < n-i-1; j++){ 
           if (arr[j] > arr[j+1]) 
              swap(&arr[j],&arr[j+1]);
        }
   }
}
int main(){
    int n,count=0,b;
    scanf("%d",&n);
    int arr[n],placed[n];
    for(int i=0; i<n;i++){
        placed[n]=0;
    }
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&b);
    bubbleSort(arr,n);
    int k;
    for(int i=0; i<n; i++){
        k=i;
        if(arr[i]>n/2) break;
    }
    k -=1;
    //printf("%d ",k);
    //printf("%d",arr[n-1]);
    for(int i=n-1;i>k;i--){
        for(int j=k;j>=0;j--){
            if(((arr[i]+arr[j])<=b)&&placed[j]!=1){
                placed[i]=1; placed[j]=1; count+=1;
                //printf("%d %d ",arr[i],arr[j]);
                break;
            }
        }
    }
    for(int i=k;i>0;i--){
        for(int j=i-1;j>=0;j--){
            if(placed[i]!=1){
                if(((arr[i]+arr[j])<=b)&&placed[j]!=1){
                    placed[i]=1; placed[j]=1; count+=1;
                    //printf("%d %d ",arr[i],arr[j]);
                    break;
                }
            }
        }
    }
    printf("%d",count);
    return 0;
}
*/