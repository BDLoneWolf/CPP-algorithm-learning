//快速幂算法，相对于普通幂运算时间复杂度更低
/*思想：分治法，将大规模的幂运算简化。例如有 n^k，当k为偶数时，将k除2，并递归继续运算；为奇数时，
递归 n^k-1，再按偶数处理。*/
//Example：2^12=2^6*2^6;2^13=2^1*2^6*2^6

//#include<iostream>
//using namespace std;

#include <stdio.h>

int Power(int, int);        //快速幂自定义函数

const int MOD = 10007;      //因为幂运算增加非常快，所以输入的N超过10007时先取余数再运算，避免溢出
int main()
{
    int N, k;
    scanf("%d%d", &N, &k);              //cin>>N>>k;
    printf("%d\n", Power(N, k));        //cout<<Power(N,k)<<endl;        
    return 0;
}

int Power(int N,int k)
{
    N %= MOD;       // N=N%MOD 取余数，只在第一次运行Power函数时有效，之后递归时会运行但不影响内容。
    if(k==0)        //跳出条件
        return 1;
    if(k>0)
    {
        if(k%2==1)                          //判断幂指数k的奇偶性
            return N*Power(N,k-1);
        if(k%2==0)
        {
            k/=2;
            return Power(N,k)*Power(N,k);
        }
    }
    return 0;       //不添加编译器会提醒没有绝对的返回值，虽然不影响，但是看着难受 :-(
}

