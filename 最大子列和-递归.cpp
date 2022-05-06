//最大子列和问题
//给出一个含k个整数的数组，从中找到连续子序列和最大者，并输出最大子列和
//本题可采用普通递归、分治、动态规划

//普通递归方法
#include<iostream>
using namespace std;
int mxsum(int w[],int s,int e,int mx)       //定义mxsum函数用于计算子列和
{
    int sum=0;
    int i;
    if(s==e)        //当起始下标等与定义的数组长度时，跳出递归
        return mx;
    else
        for(i=s;i<e;i++)
        {
            sum+=w[i];
            if(sum>mx)      //当sum的值大于最大值时赋值给最大值mx
                mx=sum;
        }
    return mxsum(w,s+1,e,mx);       //进行递归，求从第s+1个元素开始是否有更大的子列和
}
int main()
{
    int k,max;
    cin>>k;     //定义数组大小
    int a[k];
    for(int i=0;i<k;i++)
        cin>>a[i];      //输入数组元素
    max=mxsum(a,1,k,a[0]);
    cout<<max<<endl;
    return 0;
}
