#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

bool visit[100004];
int N,M,Point1,Point2,dp[100003][2];
int parent[100003][2],par[100003][22];
vector<int> vec[100003];

int getancestor(int now, int Number) {
	if (Number == 0) return now;
	else if (Number == 1) return par[now][0];
	for (int i = 1; i <= 22; i++) {
		if (pow(2, i+1) > Number && pow(2,i)<=Number ){
			return getancestor(par[now][i],Number-pow(2,i));
		}
	}
}

int getfinal(int Pointa, int Pointb) {
	if (Pointa == Pointb) return Pointa;
	else if (par[Pointa][0] == par[Pointb][0]) return par[Pointa][0];
	for (int i = 1; i <= 22; i++) {
		if (par[Pointa][i] == par[Pointb][i]) {
			return getfinal(par[Pointa][i - 1], par[Pointb][i - 1]);
		}
	}
}

void check(int now,int parent,int depth) {
	visit[now] = true;
	dp[now][0] = parent;  par[now][0] = parent;
	dp[now][1] = depth;  
	for (int i = 0; i < vec[now].size(); i++) {
		if (!visit[vec[now][i]]) {
			check(vec[now][i], now, depth + 1);
		}
	}
}

void f() {
	for (int j = 1; j < 21; j++) {
		for (int i = 1; i <= N; i++ ) {
			par[i][j] = par[par[i][j - 1]][j - 1];
			//i번 점의 2^j 번째 조상= i번점의 2^j-1 조상의 2^j-1번째 조상
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for(int i=0 ; i<N-1 ; i++){
		cin >> Point1 >> Point2;
		vec[Point1].push_back(Point2);
		vec[Point2].push_back(Point1);
	}
	check(1, 1,1);
	f();

	cin >> M;
	while (M--) {
		cin >> Point1 >> Point2;
		int nowP1=Point1,nowP2=Point2;
		//기본설정 ->nowP1 의 깊이가 nowP2 의 깊이보다 항상 더 깊게 만들것이당.
		if (dp[nowP1][1] < dp[nowP2][1]) {
			int temp = nowP1;
			nowP1 = nowP2;
			nowP2 = temp;
		}
		//nowP1 의 깊이를 nowP2 랑 같게 만들어 준다
		int differ = dp[nowP1][1] - dp[nowP2][1];
		nowP1 = getancestor(nowP1, differ);
		//cout <<nowP1<<" "<<nowP2<<" "<< differ << '\n';
		//cout << nowP1 << ' '<<nowP2<<'\n';
		cout << getfinal(nowP1, nowP2) << '\n';
	}
}
/*
13 
1 2
1 3
1 4
2 5
2 6
5 10
5 11
4 7
4 8
4 9
8 12
8 13
1000
4 12

*/

