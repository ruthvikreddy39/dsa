#include<stdio.h>
#include<string.h>
//function to modify
void modify(char *s,int len){
    if(len==1){
        s[0]='\0';
        return;
    }
    for(int j=0;j<len-1;j++){
        strcpy(&s[j],&s[j+1]);
    }
    s[len-1]='\0';
    return;
}
int main(){
    char n1[200],n2[200];
    scanf("%s",n1);
    scanf("%s",n2);
    char n[400];
    while(n1[0]!='\0'|| n2[0]!='\0'){
        if(n1[0]>=n2[0]){
            strcat(n,&n1[0]);
            modify(n1,strlen(n1));
        }
        else {
            strcat(n,&n2[0]);
            modify(n2,strlen(n2));
        }
    }
    printf("%s",n);
    return 0;
}