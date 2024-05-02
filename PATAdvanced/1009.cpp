#include <cstdio>
double poly[1001] ={};
double ans[2001] ={};
int main(){
	int n,m,number = 0;
	scanf("%d",&n);
    int e;
	double c;
	for(int i = 0;i < n;i++){
		scanf("%d %lf",&e,&c);
        poly[e] = c;
	}
	scanf("%d",&m);
	int exp;
	double cof;
    // 让多项式b的每一项与多项式a来相乘
	for(int i = 0;i < m;i++){
		scanf("%d %lf",&exp,&cof);
		for(int j = 0;j < 1001;j++){
// 			可省去if，因为可以+=系数0
            if(poly[j]!=0.0){
                ans[exp + j] += (cof * poly[j]);
            }
//             ans[exp + j] += (cof * poly[j]);
		}
	}
	for(int i = 0; i <= 2000;i++){
		if(ans[i] != 0.0) number ++;
	}
	printf("%d",number);
	for(int i = 2000;i >= 0 ;i--){
		if(ans[i] != 0.0){
			printf(" %d %.1f",i,ans[i]);
		}
	}
	return 0;
}