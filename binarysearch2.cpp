#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=100010;
double a[N];
int n;
int binarysearch2(int l,int r)
{
    if(l==r-1)
    {
        if(a[l]<a[r])
        {
            return l;
        }
        else if(a[l]>a[r])
        {
            return r;
        }
    }
    else if(r-1>l)
    {
        if((r-l+1)&1)
        {
            int mid=l+r>>1;
            double sum1=0,sum2=0;
            for(int i=l;i<=mid;i++)
            {
                sum1+=a[i];
            }
            for(int i=mid;i<=r;i++)
            {
                sum2+=a[i];
            }
            if(sum1<sum2)
            {
                return binarysearch2(l,mid);
            }
            else
            {
                return binarysearch2(mid,r);
            }
        }
        else
        {
            int mid=(r-l-1)>>1;
            double sum1=0,sum2=0;
            for(int i=l;i<=l+mid;i++)
            {
                sum1+=a[i];
            }
            for(int i=l+mid+1;i<=r;i++)
            {
                sum2+=a[i];
            }
            if(sum1<sum2)
            {
                return binarysearch2(l,mid+l);
            }
            else
            {
                return binarysearch2(l+mid+1,r);
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<binarysearch2(1,n)<<endl;
    return 0;
}