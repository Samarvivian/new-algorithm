#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=100010;
int a[N];
int n;

//参数含义:num表示从第num个数开始堆化,size表示堆的大小
void siftdown(int num,int size)
{
    while(1)
    {
        //左孩子
        int l=2*num+1;
        //右孩子
        int r=2*num+2;
        int idx=num;
        //找出三者中最大的元素
        if(l<size&&a[l]>a[idx])
        {
            idx=l;
        }
        if(r<size&&a[r]>a[idx])
        {
            idx=r;
        }
        //如果左右孩子越界,或者是父节点最大,就跳出循环
        if(idx==num)
        {
            break;
        }
        //交换元素
        int temp=a[num];
        a[num]=a[idx];
        a[idx]=temp;
        //继续堆化
        num=idx;
    }
}
void print()
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<' ';
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //从第n/2个结点开始堆化
    for(int i=n/2-1;i>=0;i--)
    {
        siftdown(i,n);
    }
    //堆排序
    for(int i=n-1;i;i--)
    {
        //交换第一个元素和最后一个元素
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;

        //从第一个数继续堆化,找到最大元素
        siftdown(0,i);
    }
    print();
    return 0;
}
