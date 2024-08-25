#include<bits/stdc++.h>
using namespace std;
int P, G;//程序员数量，小组容量
// https://blog.csdn.net/a131529/article/details/141267628
// https://blog.csdn.net/liuchuo/article/details/54427590

// 6 0 8 7 10 5 9 1 4 2 3：这是程序员的初始比赛顺序。具体地：
// 第一个比赛的程序员是编号 6（体重大约 19）
// 第二个比赛的程序员是编号 0（体重大约 25）
// 以此类推。

// 第一轮
// 第1组：[6, 0, 8]（体重: 19, 25, 57）
// 第2组：[7, 10, 5]（体重: 22, 10, 3）
// 第3组：[9, 1, 4]（体重: 56, 18, 37）
// 第4组：[2, 3]（体重: 0, 46）
// 进入第二轮的程序员编号是 8, 7, 9, 3。

// 第二轮
// 第1组：[8, 7, 9]（体重: 57, 22, 56）
// 第2组：[3]（体重: 46）
// 进入第三轮的程序员编号是 8, 3。

// 第三轮（最终轮）
// 8, 3（体重: 57, 46）
// 最重的老鼠是程序员 8（体重 57）。
 
int main()
{
	cin >> P >> G;
	vector<int> score(P),players(P),rank(P);
	for (int i = 0;i < P;i++) cin >> score[i];
	for (int i = 0;i < P;i++) cin >> players[i];
	int num = P;//当前玩家总数
	while (num > 1){
		vector<int> nextturn;//下一轮的人
		for (int i = 0;i < num;i += G){
			int jinji = i;//先假设每组的第一个人晋级，便于后续比较
			for (int j = i + 1;j < i + G && j < num;j++)
				if (score[players[jinji]] < score[players[j]]) jinji = j;
			nextturn.push_back(players[jinji]);
			for (int j = i;j < i + G && j < num;j++)
				if (j != jinji) rank[players[j]] = num / G + (num % G ? 1 : 0) + 1;
		}
		players = nextturn;
		num = num / G + (num % G ? 1 : 0);
	}
	rank[players[0]] = 1;
	for (int i = 0;i < rank.size();i++){
		if (i) cout << " ";
		cout << rank[i];
	}
}