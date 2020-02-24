//
// Created by whp98 on 2020/1/2.
//
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int Ni = 10000;
const int INF = 1<<27;

struct node
{
    int x,d;
    node(){}
    node(int a,int b){x=a;d=b;}
    bool operator < (const node & a) const
    {
        if(d==a.d) return x<a.x;
        else return d > a.d;
    }
};

vector<node> eg[Ni];
int dis[Ni],n;


void Dijkstra(int s)
{
    int i;
    for(i=0;i<=n;i++) dis[i]=INF;
    dis[s]=0;
    priority_queue<node> q;
    q.push(node(s,dis[s]));
    while(!q.empty())
    {
        node x=q.top();
        q.pop();
        for(i=0;i<eg[x.x].size();i++)
        {
            node y=eg[x.x][i];
            if(dis[y.x]>x.d+y.d)
            {
                dis[y.x]=x.d+y.d;
                q.push(node(y.x,dis[y.x]));
            }
        }
    }
}
int main()
{
    int a,b,d,m;
    while(scanf("%d%d",&n,&m),n+m)
    {
        for(int i=0;i<=n;i++) eg[i].clear();
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&d);
            eg[a].push_back(node(b,d));
            eg[b].push_back(node(a,d));
        }
        Dijkstra(1);
        printf("0 5 :¾àÀë£º%d\n",dis[5]);
    }
    return 0;
}


