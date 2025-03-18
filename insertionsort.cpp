#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
const int N=100010;
int a[N];
int n;
void insertionsort()
{
    for(int j=2;j<=n;j++)
    {
        int temp=a[j];
        int i=j-1;
        while(i&&a[i]>temp)
        {
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=temp;
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
    insertionsort();
    print();
    return 0;
}
