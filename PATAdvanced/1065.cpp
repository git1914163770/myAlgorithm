#include<bits/stdc++.h> 
using namespace std;
int main(void)
{
	int t; cin>>t;
	for(int i=1;i<=t;i++)
	{
		long double a,b,c; cin>>a>>b>>c;
		if(a+b>c) printf("Case #%d: true\n",i);
		else printf("Case #%d: false\n",i);
	}
	return 0;
}

// 其他方法：溢出性质 正+负不会溢出 正+正或负+负可能溢出
// https://blog.csdn.net/liuchuo/article/details/52109211
// 或者高精度 分类讨论