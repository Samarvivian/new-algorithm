//核心思想介绍:冒泡,每次不断沉下最大的一个数
//时间复杂度分析:
//平均时间复杂度:两层for循环,每层循环均为n次(n为输入元素的数目),所以时间复杂度为o(n^2)
//最好情况下的时间复杂度:比如1 2 3 4 5,在排序之前已经有序
//第一轮就能够在哨兵位的作用下退出循环,时间复杂度为o(1)
//最坏情况下的时间复杂度:比如5 4 3 2 1,完全倒序
//哨兵位完全不起作用,一共需要循环n(n-1)/2次,时间复杂度为o(n^2)
//空间复杂度分析:原地排序
//则空间复杂度为o(1)
#include <iostream>
using namespace std;
const int N=1e5+10;
int a[N];
int n;
int cnt;//记录总交换次数
void bubble_sort()
{
    
    //两层循环
    for(int i=n;i>1;i--)
    {
        int flag=1;//哨兵位,表示这一轮中有没有元素进行交换
        //如果没有元素进行交换,flag就为1,表示此时元素已经排列好顺序
        //可以提前退出循环
        for(int j=1;j<i;j++)
        {
            //前一个元素大于后一个元素,下沉,交换
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=0;
                cnt++;
            }
        }
        if(flag)
        {
            break;
        }
    }
}
void print()
{
    for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
    
    printf("\n%d",cnt);
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