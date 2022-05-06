//汉诺塔问题
//本题默认仅有三个柱子“a，b，c”，初始柱子为a，目标柱子为b，层数自定
/*采用分治法，汉诺塔问题可分解为如下：
一、当层数为1时，直接将盘从a柱移至c柱。
二、当层数大于2时，将所有盘分为两个部分：（1）最下面的盘；（2）其余的上面的盘
1、将上面的盘都从a移动至b，期间用c作为中转
2、将最下面的盘a移动至c
3、将其余盘从b移动至c，期间用a作为中转*/
//使用函数hanoi实现汉诺塔问题，其中n为层数，a为起始柱，b为中转，c为目标柱
#include<bits/stdc++.h>
using namespace std;
//static int step=0;
void hanoi(int n,char a,char b,char c)          //实现解决汉诺塔问题的自定函数
{
    if(n==1)
        cout<<a<<" --> "<<c<<endl;      //当层数为1时直接从a移至c，作为跳出条件
        //cout<<++step<<"."<<a<<" --> "<<c<<endl;
    else
    {
        hanoi(n-1,a,c,b);   //上面的盘从a移至b，用c中转
        hanoi(1,a,b,c);     //最下面的盘从a移至c
        hanoi(n-1,b,a,c);   //剩余的盘从b移至c，用a中转
    }
}
int main()
{
    int n;
    //char a,b,c;
    cout<<"请输入塔的层数";
    //cout<<"请输入塔的层数和要从哪个塔移动至哪个塔（共三根柱子）"<<endl;
    cout<<"层数:";
    cin>>n;
    // cout<<"初始柱子:";
    // cin>>a;
    // cout<<"中转点:";
    // cin>>b;
    // cout<<"目标柱子:";
    // cin>>c;
    hanoi(n,'a','b','c');
    return 0;
}