//顶点1-n 输出查询编号，从0开始
//对于每行查询，如果当前节点的入度不为0，则不是拓扑排序
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m,a,b,k,in[1010];
    vector<int> v[1010];
    scanf("%d %d",&n,&m);
    for(int i = 0 ;i < m;i++){
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        in[b]++;
    }
    scanf("%d",&k);
    int resFlag = 0;
    for(int i = 0;i < k;i++){
        int isOrder = 1;
        // 顶点1-n
        vector<int> temp(in,in+n+1);
        for(int j = 0;j < n;j++){
            scanf("%d",&a);
            if(temp[a] != 0){
                // 这里不能直接break,要全部读完
                isOrder = 0;
                //或者像下面的方式读取剩下的
                // j++;
                // for(;j < n;j++){
                //     scanf("%d",&a);
                // }
                // break;
            }
            for(int it : v[a]) temp[it]--;
        }
        if(!isOrder) {
            if(resFlag) printf(" "); else resFlag = !resFlag;
            printf("%d",i);
        }
    }
    return 0;
}