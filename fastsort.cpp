#include <iostream>
using namespace std;
const int N=1e5+10;
int a[N];
int n;
void fast_sort(int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int index=a[l];
    int s1=l,s2=r;
    while(s1<s2)
    {
        while(s1<s2&&a[s2]>=index)
        {
            s2--;
        }
        if(a[s2]<index)
        {
            a[s1]=a[s2];
            s1++;
            
        }
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
    a[s1]=index;
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
    fast_sort(1,n);
    print();
    return 0;
}