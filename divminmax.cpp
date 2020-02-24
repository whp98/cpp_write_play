//
// Created by whp98 on 2020/1/2.
//
#include <iostream>
using namespace std;

int max(int a[],int i,int j){
    int num1=0,num2=0;

    if(i==j){
        return a[i];
    }
    else if(i==j-1)
        return a[i]>=a[j]?a[i]:a[j];
    else{
        int mid=(i+j)/2;
        num1=max(a,i,mid);
        num2=max(a,mid,j);
        return num1>num2?num1:num2;
    }
}

int min(int a[],int i,int j){
    int num1=0,num2=0;

    if(i==j){
        return num1=num2=a[i];
    }
    else if(i==j-1){
        if(a[i]<a[j]){
            return a[i];
        }
        return a[j];
    }
    else{
        int mid=(i+j)/2;
        num1=min(a,i,mid);
        num2=min(a,mid,j);
        return num1<num2?num1:num2;
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"max="<<max(a,0,n-1)<<endl
        <<"min="<<min(a,0,n-1);
}

