#include<stdio.h>
#include<stdlib.h>
//function to check if the char already exists
int in(char *s, char* d){
    int count=0;
    int i=0;
    while(*d!='\0'){
        if(*s==*d){
            count++;
            break;
        }
        d=d+1;
        i++;   
    }
    if(count==0){
        *d=*s;
        *(d+1)='\0';
    }
    return i;
}
int main(){
    int n,c,k;
    scanf("%d %d",&n,&c);
    char str[20];
    char din[1000];
    din[0]='\0';
    int num[1000];
    for(int i=0;i<n;i++){
        num[i]=0;
    }
    for(int i=0; i<n; i++){
        scanf("%s",str);
        k=in(&str[0],din);
        num[k]+=1;
    }
    /*printf("%s",din);
    printf("\n");
    for(int i=0;i<n;i++){
       printf("%d",num[i]);
    }*/
    int p,j=0,fights=0;
    while(num[j]!=0){
        if(num[j]>c){
            p=1;
            num[j]=num[j]-c;
            fights+=num[j];
            num[j]=num[j]-c;
            p++;
            while(num[j]>0){
                fights += (num[j]*c);
                num[j]=num[j]-c;
                p++;
            }
        }
        j++;
    }
    printf("%d",fights);
    return 0;
}