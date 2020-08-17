#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

string A, B;
int dp[1003][1003];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	for (int i = 0; i < A.length(); i++) {
		for (int j = 0; j < B.length(); j++) {
			if (A[i] == B[j]) {
				dp[i + 1][j + 1] = max(max(dp[i][j] + 1, dp[i][j + 1]), dp[i + 1][j]);
			}
			else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}
	cout << dp[A.length()][B.length()] << '\n';
}