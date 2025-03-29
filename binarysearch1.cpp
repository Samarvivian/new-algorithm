#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e5+10;
int a[N];
int n;
int target;
void binarysearch()
{
    int l=1,r=n;
    
    while(l<r)
    {
        int mid=l+r>>1;
        if(a[mid]>target)
        {
            r=mid;
            
        }
        else if(a[mid]<target)
        {
            l=mid+1;
        }
        else
        {
            printf("find,the pos is%d",mid);
            return;
        }
    }
    printf("not find");
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    printf("enter the number you want to find:\n");
    cin>>target;
    binarysearch();
    return 0;
}