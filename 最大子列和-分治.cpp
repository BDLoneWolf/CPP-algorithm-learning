//最大子列和问题
//给出一个含k个整数的数组，从中找到连续子序列和最大者，并输出最大子列和，皆小于0时输出0
//本题可采用普通递归、分治、动态规划

/*分治法解决最大子列和问题的思想为将数组分为两份，分别判断左边、右边、中间三处子列和的最大值，再
判断哪个最大，求出答案*/
//分治法
#include<iostream>
//#include<algorithm>
using namespace std;
int max(int a,int b)        //可以调用algorithm头文件中的max函数
{
    if(a>b)
        return a;
    return b;
}
int mxsum(int w[],int s,int e)          //定义mxsum函数求最大子序列
{
    if(s==e)
        return w[s];
    int lsum,rsum,mid;
    mid=(s+e)/2;
    lsum=mxsum(w,s,mid);        //计算左区间的最大值
    rsum=mxsum(w,mid+1,e);      //计算右区间的最大值
    int sum1,sum2;
    sum1=sum2=0;
    int lefts,rights;
    lefts=rights=0;
    for(int i=mid;i>=s;i--)
    {
        lefts+=w[i];
        if(lefts>sum1)
            sum1=lefts;
    }
    for(int i=mid+1;i<=e;i++)
    {
        rights+=w[i];
        if(rights>sum2)
            sum2=rights;
    }  
    int msum=sum1+sum2;         //计算从中间向两边取序列的最大子序列
    return max(msum,max(lsum,rsum));
}
int main()
{
    int k,max;
    cin>>k;
    int a[k];
    for(int i=0;i<k;i++)
        cin>>a[i];
    max=mxsum(a,0,k-1);
    if(max<0)
        max=0;
    cout<<max<<endl;
    return 0;
}

