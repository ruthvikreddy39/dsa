#include <stdio.h>

int main(){
    
    int a[1000],b[1000],s[1001],s1=0,s2=0,s3=0,i=0;
    int carry=0, sum=0;
    char num1[1000],num2[1000],add[1001];
    //taking inputs as strings
    scanf("%s", num1);
    scanf("%s", num2);
    //finding length of each number
    while(num1[i]!='\0'){
        s1++;
        i++;
    }
    i=0;
    while(num2[i]!='\0'){
        s2++;
        i++;
    }
    //storing digits into an array
    //if same no. of digits
    if(s1==s2){
        for(i=0;i<s1;i++){
            a[i]=num1[i]-48;
            b[i]=num2[i]-48;
        }
    }
    //if diff no. of digits
    else if (s1!= s2){
        for(i=0;i<s1;i++){
            a[i]=num1[i]-48;
        }
        for(i=0; i<s1;i++){
            if(i<s1-s2)
                b[i]=0;
            else
                b[i]=num2[i-s1+s2]-48;
        }
    }
    //we have two arrays of equal length for sure now
    //adding digit by digit
    for(i=s1-1; i>=0; i--){
            sum = a[i]+b[i]+carry;
            if(i== 0 && sum>=10){
                s[s3]=sum%10;
                s[s3+1]= 1;
                s3+=2;
                carry=0;
                break;
            }
            if(sum>=10){
                carry = 1;
                s[s3] = sum%10;
            }
            else if(sum<10){
                carry=0;
                s[s3] = sum;
            }
            ++s3;
        }
    //to print it as a string
    for(i= s3-1; i>=0 ; i--){
        add[s3-1-i]= s[i]+'0';
    }
    printf("%s",add);
    return 0;
}