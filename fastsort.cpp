//核心思想:每次将第一个元素作为指标,比它大的数必须排在后面,比它小的数必须排在前面
//将该作为指标的元素放在合适的位置,依次递归,最后所有元素都位于它应该在的位置
//难点:如何能够将比它小的元素放在前面,将比它大的元素放在后面
//时间复杂度分析:
//由于快速排序是一种递归算法,每次都将它所在的区间分成两部分,继续递归下去
//直到区间长度为1为止
//最优情况：每次区间都被平分：
//(1+2+4+……+2^x)=n,解得x=log(n+1)
//每次递归时间复杂度为n，所以整个算法最优时间复杂度为o(nlogn)
//最坏情况：元素从高到低排列，这时快速排序退化成冒泡排序
//此时时间复杂度为o(n^2)
//空间复杂度分析：
//最好情况:每次都平分:o(logn)
//最坏情况：完全倒序:o(n)
#include <iostream>
using namespace std;
const int N=1e5+10;
int a[N];
int n;
void fast_sort(int l,int r)
{
    //当区间长度大于1，停止递归
    if(l>=r)
    {
        return;
    }
    //设定指标
    int index=a[l];
    int s1=l,s2=r;
    while(s1<s2)
    {
        //后面放的都是比index大的元素
        while(s1<s2&&a[s2]>=index)
        {
            s2--;
        }
        if(a[s2]<index)
        {
            a[s1]=a[s2];
            s1++;
            
        }
        //前面放的都是比index小的元素
        while(s1<s2&&a[s1]<index)
        {
            s1++;
        }
        if(a[s1]>=index)
        {
            a[s2]=a[s1];
            s2--;
        }
    }
    //将index放在合适的位置
    a[s1]=index;
    //递归
    fast_sort(l,s1-1);
    fast_sort(s1+1,r);
}
void print()
{
    for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    //快速排序
    fast_sort(1,n);
    //打印数组
    print();
    return 0;
}