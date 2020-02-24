//
// Created by whp98 on 2020/1/2.
//
#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b) {
return a>b;
    6.	}
7.	/*将数组a的值排序使其元素的分布从中间往两边依次减少*/
8.	void strageSort(int n,int a[]) {
    9.	    int i,k,mid;
    10.	    sort(a,a+n,cmp);
    11.	    mid = n/2;
    12.	    int b[n+1];
    13.	    b[mid] = a[0];
    14.	    for(i = 1,k = 1; i< n; i++,k++) { //数组a的值分布从中间往两边依次减少
        15.	        b[mid-k] = a[i];
        16.	        i++;
        17.	        if(i!=n)
            18.	            b[mid+k] = a[i];
        19.	    }
    20.	    for(int i = 0; i<n; i++) {     //经变化后的a数组
        21.	        a[i] = b[i];
        22.	    }
    23.	}
24.	void  minStorage(int n,int a[])
25.	{
26.	    int sum = 0;
27.	    for(int i = 0; i<n; i++)
28.	    {
29.	        sum+=a[i];
30.	    }
31.	    double result = 0;
32.	    for(int i = 0; i<n; i++)
33.	    {
34.	        for(int j = i+1; j<n; j++)
35.	        { //从磁道0-n-1。计算它们的磁道间的检索时间
36.	                result+=(a[i]*1.0/sum)*(a[j]*1.0/sum)*(j-i);
37.	        }
38.	    }
39.
40.	     cout<<"最小期望检索时间:"<<result<<endl;
41.
42.
43.
44.	    printf("完成");
45.
46.	}
47.
48.	int main()
49.	{
50.	    int n,k,mid,i;
51.
52.	    FILE *fpRead=fopen("input.txt","r");
53.	    fscanf(fpRead,"%d ",&n);
54.	    int a[n+1];
55.	    for(int i = 0; i<n; i++)
56.	    {
57.	        fscanf(fpRead,"%d ",&a[i]);
58.	    }
59.	    strageSort(n,a);
60.	    minStorage(n,a);
61.	    return 0;
62.	}

