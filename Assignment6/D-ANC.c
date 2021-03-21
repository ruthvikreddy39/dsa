#include<stdio.h>
int exists(int *a,int b,int size){
    int j=0;
    for(int i=0;i<size;i++){
        if(a[i]==b)j++;
    } return j;
}

int main(){
    int n,k,x;
    scanf("%d %d %d",&n,&k,&x);
    int s[n],r[k];
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    for(int i=0;i<k;i++){
        scanf("%d",&r[i]);
    }
    int s1=0,s2=0,xpos=0,count,cs,max=0,maxs=0;
    for(int i=0;i<n;i++){
        if(!exists(r,i,k))s1+=s[i];
    }
    printf("%d ",s1);
    for(int i=0;i<k;i++){
        count=0;
        for(int p=r[i];p<r[i]+x;p++){
            if(exists(r,p,k)){
                count++; cs+=s[p]; //cs=0
            }
        }
        if(count>=max && cs>=maxs){//check this line if any error shows up in ans
            max=count; maxs=cs; xpos=r[i];
        }
    }//printf("%d ",xpos);
    for(int i=0;i<n;i++){
        if(!exists(r,i,k) || (i>=xpos && i<=xpos+x-1)){
            s2+=s[i];
        }
    }printf("%d",s2);
    return 0;
}