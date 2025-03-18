#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
const int N=100010;
int a[N];
int n;
void selectionsort()
{
    int minn=INT_MAX;
    for(int i=1;i<n;i++)
    {
        int idx=i;
        for(int j=i;j<=n;j++)
        {
            if(minn>a[j])
            {
                minn=a[j];
                idx=j;
            }
        }
        if(idx!=i)
        {
            swap(a[i],a[idx]);
        }
        minn=INT_MAX;
    }
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
    selectionsort();
    print();
    return 0;
}
