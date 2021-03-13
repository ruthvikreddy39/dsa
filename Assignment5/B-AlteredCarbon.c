#include<stdio.h>
#include<string.h>
#define MAX 10000
//function to fill net worth
void worth(char *s, int w[],int l,int num){
    int i,j,k=0,worth=0,part;
    //s[i]>='0'&&s[i]<='9'
    for(i=0;i<l;i++){
        j=0;
        if(s[i]>='0'&&s[i]<='9'&&i==k){
            part=0;
            j=i;
            while(s[j]>='0'&&s[j]<='9'){
                part = part*10 + (s[j]-48);
                j++;
                k=j;
            }
            worth+=part;
        }
        else if(s[i]>='0'&&s[i]<='9'&&i!=k){
            //do nothing
        }
        else if(!(s[i]>='0'&&s[i]<='9')) k++;

        //i=j;
    }
    w[num]=worth;
    return;
}
int main(){
    int n,k,len;
    scanf("%d %d",&n,&k);
    char str[MAX];
    int wealth[n];
    for(int i=0;i<n;i++){
        scanf("%s",str);
        len= strlen(str);
        worth(str,wealth,len,i);
    }
    /*for(int k=0;k<n;k++){
        printf("%d ",wealth[k]);
    }*/
    return 0;
}