//manhattan distance between two points
//(x1,y1) and (x2,y2) is
// |x1-x2|+|y1-y2|
#include<stdio.h>

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    return 0;
}