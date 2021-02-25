#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100000
//function to print all combinations
int c;
void printk(char *s, char *e, int n, int k,int l,int *c){
    if(k==0){
        printf("%s",e);
        *c -=1;
        if(*c!=0)printf("\n");
        return;
    }
    for(int j=0;j<n;j++){
        char new[MAX];
        char temp[MAX];
        strcpy(temp,e);
        strncat(temp,&s[j],1);
        strcpy(new,temp);
        printk(s,new,n,k-1,l,c);
    }
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    if(n==0)exit(0);
    int l=1;
    for(int p=0;p<k;p++){
        l = l*n;
    }
    c=l;
    //printf("%d\n",l);
    char str[MAX];
    scanf("%s",str);
    char empty[5];
    empty[0]='\0';
    printk(str,empty,n,k,l,&c);
    return 0;
}