#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=100010;
int a[N];
int temp[N];
int n;
//获取num第k位上的数字,其中exp=10^(k-1)
int calc(int num,int exp)
{
    return (num/exp)%10;
}
void radixsort(int exp)
{
    //用一个容器来存储每个元素第k位上的数字
    vector<int>count(10);
    //获取每个元素第k位的数字
    for(int i=1;i<=n;i++)
    {
        int num=calc(a[i],exp);
        count[num]++;
    }
    //运用前缀和,将"数字计数"转化为"数组索引"
    for(int i=1;i<10;i++)
    {
        count[i]=count[i-1]+count[i];
    }
    
    //从后往前遍历
    //原因是:假设上一次排序结果为97,78,88,98
    //根据排序要求,这次排序97应该排在98前面
    //倒序遍历可以保证在高位相同的前提下,不打乱低位的顺序
    for(int i=n;i>=1;i--)
    {
        //提取这个数字的第k位
        int num=calc(a[i],exp);
        //找到对应的数组索引
        int idx=count[num];
        temp[idx]=a[i];
        count[num]--;
    }
    //将排好的顺序复制回原数组中
    for(int i=1;i<=n;i++)
    {
        a[i]=temp[i];
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    //找到最大的数字
    int m=a[1];
    for(int i=1;i<=n;i++)
    {
        m=max(m,a[i]);
    }
    //对每一位进行基数排序
    for(int exp=1;exp<=m;exp*=10)
    {
        radixsort(exp);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<' ';
    }
    return 0;
}