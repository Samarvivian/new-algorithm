//核心思想介绍:冒泡,每次不断沉下最大的一个数
//时间复杂度分析:两层for循环,每层循环均为n次(n为输入元素的数目),所以时间复杂度为o(n^2)
//空间复杂度分析:用一个数组储存将要被排序的元素,该数组大小被开辟为1e5+10
//则空间复杂度为1e5+10
#include <iostream>
using namespace std;
const int N=1e5+10;
int a[N];
int n;
void bubble_sort()
{
    //两层循环
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            //前一个元素大于后一个元素,下沉,交换
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
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
    //输入元素数目以及所有待排序的元素
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    //冒泡排序
    bubble_sort();
    //打印最后排序好的数组
    print();
    return 0;
}