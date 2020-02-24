//
// Created by whp98 on 2020/1/2.
//

#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
const int N=100;
const int max1=100000;
int p[N][N],d[N],path[N];

void dijkstra(int sec,int n)
{
    int i,j,min,min_num;
    int vis[N]={0,};
    for(i=0;i<n;i++)
    {
        d[i]=p[sec][i];
    }
    vis[sec]=1;
    d[sec]=0;
    for(i=1;i<n;i++)
    {
        min=max1;
        for(j=0;j<n;j++)
        {
            if(!vis[j]&&d[j]<min)
            {
                min=d[j];
                min_num=j;
            }
        }
        vis[min_num]=1;
        for(j=0;j<n;j++)
        {
            if(d[j]>min+p[min_num][j])
            {
                path[j]=min_num;
                d[j]=min+p[min_num][j];
            }
        }
    }
}

void print(int sec,int n)
{
    int i,j;
    stack<int> q;
    for(i=1;i<n;i++)
    {
        j=i;
        while(path[j]!=-1)
        {
            q.push(j);
            j=path[j];
        }
        q.push(j);
        if(i==4) printf("%d  %d, ¾àÀë:%d ",sec,i,d[i]);
        while(!q.empty())
        {

            q.pop();
        }

    }
}

int main()
{
    memset(path,-1,sizeof(path));
    int i,j,n=5;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            p[i][j]=(i==j?0:max1);
        }
    }
    p[0][1]=2;
    p[0][2]=3;
    p[0][3]=5;
    p[1][2]=8;
    p[1][3]=5;
    p[2][4]=5;
    p[3][4]=2;
    dijkstra(0,n);
    print(0,n);
    return 0;
}
