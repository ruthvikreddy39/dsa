#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void check(char *s, int len,int j, int count){

    if(j<=len-3){
        if(*(s)=='b'){
            if(*(s+1)=='a'){
                if(*(s+2)=='a'){
                    if(*(s+3)=='b'){
                        if(count==0){
                            printf("YES");
                            printf(" %d",j);
                            check(s+1,len,j+1,count+1);
                        }
                        else{
                            printf(" %d",j);
                            check(s+1,len,j+1,count+1);
                        }                 
                    }else{check(s+1,len,j+1,count); }
                }else{check(s+1,len,j+1,count); }
            }else{check(s+1,len,j+1,count); }
        }
        else {
            check(s+1,len,j+1,count);  
        }
    }
    else if(j>len-3 && count==0){
        printf("NO");
        return;
        //exit(0); 
    }
}

int main(){
    int n,c=0,b=1;
    scanf("%d",&n);
    char s[500];
    scanf("%s",s);
    check(s,n,b,c);
    return 0;
}