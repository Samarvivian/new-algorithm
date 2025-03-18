#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
const int N=100010;
int a[N];
int temp[N];
int n;
void merge(int l,int mid,int r)
{
    int start1=l,start2=mid+1;
    int idx=0;
    while(start1<=mid&&start2<=r)
    {
        if(a[start1]<a[start2])
        {
            temp[idx]=a[start1];
            start1++;
        }
        else
        {
            temp[idx]=a[start2];
            start2++;
        }
        idx++;
    }
    while(start1<=mid)
    {
        temp[idx]=a[start1];
        idx++;
        start1++;
    }
    while(start2<=r)
    {
        temp[idx]=a[start2];
        idx++;
        start2++;
    }
    for(int i=0,j=l;i<idx,j<=r;i++,j++)
    {
        a[j]=temp[i];
    }
}
void mergesort(int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int mid=l+r>>1;
    mergesort(l,mid);
    mergesort(mid+1,r);
    merge(l,mid,r);
}
void print()
{
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<' ';
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    mergesort(1,n);
    print();
    return 0;
}
