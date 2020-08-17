#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int N, M, V;
int a, b;
vector<int> vec[1004];

bool visit_dfs[1004];
bool visit_bfs[1004];

void dfs(int num) {
	cout << num << " ";
	visit_dfs[num] = true;
	for (int i = 0; i<vec[num].size(); i++) {
		int next = vec[num][i];
		if (visit_dfs[next] == false) dfs(next);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> V;

	while (M--) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) sort(vec[i].begin(), vec[i].end());

	dfs(V); cout <<'\n';

	queue<int> q;
	q.push(V); visit_bfs[V] = true;








	while (!q.empty()) {
		int now = q.front();   q.pop();
		cout << now <<" ";
		for (int i = 0; i<vec[now].size(); i++) {
			int next = vec[now][i];
			if (visit_bfs[next] == false) {
				visit_bfs[next] = true;
				q.push(next);
			}
		}
	}



}

