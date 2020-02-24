//
// Created by whp98 on 2020/1/2.
//
#include<stdio.h>
#define n 5
int a[5]={6,12,11,2,3};
//排序
void sort(int *a, int l)
{
    int i, j;
    int v;
    for(i = 0; i < l - 1; i ++)
        for(j = i+1; j < l; j ++)
        {

            if(a[i] > a[j])
            {
                v = a[i];
                a[i] = a[j];
                a[j] = v;
            }
        }
}
//最小次数
int getmin(int *a)
{
    int r=0;
    int num=5;
    int mu=5;
    int i;

    while(num>1)
    {
        printf("%d %d\n",a[0],a[1]) ;

        a[0]=a[0]+a[1];
        //printf("%d\n",a[0]);
        r+=a[0]-1;
        num--;
        for(i=1;i<num;i++)
            a[i]=a[i+1];
        a[num]=9999;
        sort(a,n);
    }
    return r;

}

int main()
{


    sort(a,n);
    printf("总比较次数：%d\n",getmin(a));
    return 0;
}

