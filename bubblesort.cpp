#include <iostream>
using namespace std;
const int N=1e5+10;
int a[N];
int n;
void bubble_sort()
{
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
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
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    bubble_sort();
    print();
    return 0;
}