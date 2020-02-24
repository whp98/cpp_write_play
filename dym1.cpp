//
// Created by whp98 on 2020/1/2.
//
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dis(string a, string b, int k)
{
    int al = a.length();
    int bl = b.length();
    int i, j;
    int ** val = new int*[al + 1];

    for (i = 0; i <= al; i++)
        val[i] = new int[bl + 1];

    val[0][0] = 0;
    //初始化
    for (i = 1; i <= al; i++)
        val[i][0] = i*k;

    for (i = 1; i <= bl; i++)
        val[0][i] = i*k;


    for (i = 1; i <= al; i++)
        for (j = 1; j <= bl; j++)
            //取最小值
            //递归定义
            val[i][j] = min(min(val[i - 1][j] + k, val[i][j - 1] + k), val[i - 1][j - 1] + abs(a[i - 1] - b[j - 1]));


    //cout << val[0][1]<<endl;
    return val[al][bl];
}

int main()
{
    string A, B;
    int k;
    while (cin>>A>>B>>k)
    {
        cout << dis(A, B, k) << endl;

    }
}

