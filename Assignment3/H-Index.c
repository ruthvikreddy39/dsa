#include<stdio.h>

int main(){
    int a,p,c,x;
    scanf("%d %d %d",&a,&p,&c);
    int auth[p],cit[p],index[a];
    for(int i=0;i<p;i++){
        scanf("%d",&auth[i]);
    }
    int u,v;
    for(int i=0;i<p;i++){
        cit[i]=0;
        if(i<a)index[i]=0;
    }
    for(int i=0;i<c;i++){
        scanf("%d %d",&u,&v);
        cit[v]+=1;
    }
    for(int j=0;j<a;j++){
        x=0;
        for(int k=0;k<p;k++){
            if(auth[k]==j){
                if(cit[k]>x)x++;
            }
        }
        index[j]=x;
    }
    for(int i=0;i<a;i++){
        printf("%d",index[i]);
        if(i!=a-1)printf(" ");
    }
    return 0;
}