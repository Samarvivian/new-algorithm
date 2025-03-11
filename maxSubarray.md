# 运用分治策略,将所有数组分成右下标全部在mid左边,左下标全部位于mid右边,以及交叉来处理
```
int maxmid(int* nums,int l,int mid,int r)
{
    int sum1=0;
    int res1=INT_MIN;
    for(int i=mid;i>=l;i--)
    {
        sum1+=nums[i];
        if(sum1>res1)
        {
            res1=sum1;
        }
    }
    int sum2=0;
    int res2=INT_MIN;
    for(int i=mid+1;i<=r;i++)
    {
        sum2+=nums[i];
        if(sum2>res2)
        {
            res2=sum2;
        }
    }
    return res1+res2;
}
int maxsubArray(int* nums,int l,int r)
{
    if(l==r)
    {
        return nums[l];
    }
    int mid=l+r>>1;
    int ans1=maxsubArray(nums,l,mid);
    int ans2=maxsubArray(nums,mid+1,r);
    int ans3=maxmid(nums,l,mid,r);
    if(ans1>=ans2&&ans1>=ans3)
    {
        return ans1;
    }
    else if(ans2>=ans1&&ans2>=ans3)
    {
        return ans2;
    }
    else
    {
        return ans3;
    }
}
int maxSubArray(int* nums, int numsSize) {
    return maxsubArray(nums,0,numsSize-1);
}
```