#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n,max_in=0,empty,in,leave,count=0,b,j;
    scanf("%d%*c",&n);
    char t;
    for(int i=0; i<n; i++){
        scanf("%c", &t);
        //people entering
        if(t=='E'){
            scanf("%d%*c", &in);;
            if(count==0){
                max_in+=in;
                empty=0;
                count++;
            }
            else {
                if(in>empty){
                    max_in += in-empty;
                }
                else if(in<=empty){
                    empty -= in;
                }
            }  
        }
        //people leaving
        else if(t=='L'){
            scanf("%d%*c", &leave);
            for(int k=0; k<leave;k++){
                scanf("%d%*c",&b);
            }
            empty+=leave;
        }
    }
    printf("%d",max_in);
    return 0;
}