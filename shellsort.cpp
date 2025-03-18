#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=100010;
int a[N];
int n;
void shellsort()
{
    for(int gap=n/2;gap;gap/=2)
    {
        for(int i=gap;i<=n;i++)
        {
            int j=i;
            int cur=a[i];
            while(j-gap>=1&&cur<a[j-gap])
            {
                a[j]=a[j-gap];
                j=j-gap;
            }
            a[j]=cur;
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
    shellsort();
    print();
    return 0;
}