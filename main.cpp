#include <iostream>
#include <string>
using namespace std;

static string A[7] = {"A0","A1","A2","A3","A4","A5","A6"};//六个矩阵A1～A6 但是伪码是从下标1开始计算，因此在首位填充0
static int p[7] = {5,10,3,12,5,50,6};//同上，A[1]的维数为p[0]*p[1]
//static int p[7] = {30,35,15,5,10,20,25};

int** matrix_chain_order(int *p, int **m, int **s, int n)
{
    int i,j,k;
    for(i = 1; i <= n; i++)
        m[i][i] = 0;
    for(int l = 2; l <= n; l++)
        for(i = 1; i <= n-l+1; i++)
        {
            j = i+l-1;
            m[i][j] = 100000;//表示无穷大
            for(k = i; k <= j-1; k++)
            {
                int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if(q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    for(int i = 1; i<= n;i++)
    {
        for (int j= 1;j<=n;j++)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
    cout << endl;

    for(int i = 1; i<= n;i++)
    {
        for (int j= 1;j<=n;j++)
            cout<<s[i][j]<<" ";
        cout<<endl;
    }

    return s;
}

void print_optimal_parens(int **s, int i,int j)
{
    if(i == j)
        cout<<A[i];
    else
    {
        cout << "(";
        print_optimal_parens(s, i, s[i][j]);
        print_optimal_parens(s, s[i][j] + 1,  j);
        cout << ")";
    }
}

int** matrixInit(int row,int col)
{
    int **matrix;
    matrix = (int**)malloc(sizeof(int*)*row);
    for(int i = 0 ; i < col; i++)
        matrix[i] = (int*)malloc(sizeof(int)*col);
    return matrix;
}

int main() {
    int **s;
    int **m;
    int n = sizeof(p)/sizeof(int) -1;
    m = matrixInit(n+1,n+1);
    s = matrixInit(n+1,n+1);
    for(int i = 0;i<=n;i++)
        for(int j =0;j<=n;j++)
            m[i][j] = 99999;//数组赋初值

    s = matrix_chain_order(p, m, s, n);
    print_optimal_parens(s,1,6);
    return 0;
}