#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

int dp[20][(1 << 17) + 1], N, all;
int load[20][20];

int go(int now, int state) {

	if ((state & 1) && state != all) return 987654321;
	if (state == all) return 0;

	if (dp[now][state] != -1) return dp[now][state];

	int ret = 987654321;

	for (int i = 1; i <= N; i++) {
		int next = 1 << (i - 1);
		if (load[now][i] > 0 && !(state & next)) {
			ret = min(ret, go(i, state | next) + load[now][i]);
		}
	}
	return dp[now][state] = ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> N;

	all = (1 << N) - 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> load[i][j];
		}
	}

	cout << go(1, 0) << '\n';

}