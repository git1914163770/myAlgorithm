//https://blog.csdn.net/qq_46527915/article/details/120881509
//https://www.bilibili.com/video/BV1Mt4y197kC/?p=67
// 如果这个数本身是一个自环，那么说明他已经在对应的位置了，那么直接跳过。
// 如果一个环和0在同一个环内，共有cnt个点，那么我们需要交换 cnt-1 此。
// 如果一个环没有0，且共有cnt个点，那么首先我们得先将0加进来，然后再依次交换。加入进来1次操作,cnt+1个点交换 需要cnt次 故共cnt+1次
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],st[N],n,ans;
int main(void)
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		if(a[i]==i) continue;//自环
		if(!st[i]) 
		{
			bool flag=false;
			int cnt=0;//点的个数
			for(int j=i;!st[j];j=a[j])
			{
				if(j==0) flag=true;
				cnt++;
				st[j]=1;
			}
			if(flag) ans+=cnt-1;//和零在同一个环
			else ans+=cnt+1;//和零不在同一个环
		}
	}
	cout<<ans<<endl;
	return 0;
}
