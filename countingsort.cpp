#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N=100010;
int a[N];
int n;
void countingsort()
{
    //找到最大元素
    int m=a[1];
    for(int i=1;i<=n;i++)
    {
        m=max(m,a[i]);
    }
    vector<int>vec(m+1);
    for(int i=1;i<=n;i++)
    {
        vec[a[i]]++;
    }
    for(int i=0;i<=m;i++)
    {
        if(vec[i])
        {
            for(int j=1;j<=vec[i];j++)
            {
                cout<<i<<' ';
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    countingsort();
    return 0;
}