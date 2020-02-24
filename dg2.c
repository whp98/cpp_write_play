//
// Created by whp98 on 2020/1/2.
//

#include<stdio.h>
int a[100][100];

int mymax(int a1,int a2)
{
    return a1>a2?a1:a2;
}

int dp(int n,int i,int j)
{
    if(i == n)
        return a[i][j];
    int l = dp(n,i + 1, j);
    int r = dp(n,i + 1, j + 1);
    return mymax(l,r) + a[i][j];
}


int main()
{
    int n,i,j;
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            scanf("%d",&a[i][j]);
        }

    }


    printf("%d",dp(n,1,1));
}
