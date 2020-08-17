#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int n, m;
int floid[104][104];
int before[104][104];
int a, b, c;

void tracking(int start, int end) {
	if (start == end || floid[start][end]==987654321) {
		cout << 0 << '\n';
		return;
	}
	
	stack<int> s;

	int now = end;
	while (now != start) {
		s.push(now);
		now = before[start][now];
	}
	s.push(now);

	cout << s.size() << " ";
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";
	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				floid[i][j] = 0;
				before[i][j] = i;
			}
			else floid[i][j] = 987654321;
		}
	}

	while (m--) {
		cin >> a >> b >> c;
		if (floid[a][b] > c) {
			floid[a][b] = c;
			before[a][b] = a;
		}
	}

	//i->k->j
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (floid[i][j] > floid[i][k] + floid[k][j]) {
					floid[i][j] = floid[i][k] + floid[k][j];
					before[i][j] = before[k][j];
					//왜 before[i][j]= k 가아니라 
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (floid[i][j] == 987654321) cout << 0 << " ";
			else cout << floid[i][j] << " ";
		}
		cout << '\n';
	}

	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			tracking(i, j);
		}
	}
	
}