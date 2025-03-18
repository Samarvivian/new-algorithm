#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=100010;
float a[N];
int n;
void bucketsort()
{
    //预先约定每个篮子放两个数
    int size=n/2+1;
    vector<vector<float>>buckets(size);
    //遍历所有数(这里事先约定所有数都在[0,1)范围内,i*size将其一一映射到[0,size]中)
    for(int i=1;i<=n;i++)
    {
        int num=a[i]*size;
        buckets[num].push_back(a[i]);
    }
    //将每个篮子排序
    for(vector<float>&bucket:buckets)
    {
        sort(bucket.begin(),bucket.end());
    }
    //重置数组
    int idx=1;
    for(vector<float>&bucket:buckets)
    {
        for(auto x:bucket)
        {
            a[idx++]=x;
        }
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
    bucketsort();
    print();
    return 0;
}
