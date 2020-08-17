#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct load {
	int to;
	int dist;
	load(int a,int b): to(a),dist(b){}
};

bool operator<(load a, load b) {
	return a.dist > b.dist;
}

priority_queue<int> heap[1004];
priority_queue<load> pq;
vector<load> vec[1004];

int n, m, k;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;

	for(int i=1 ; i<=m ; i++){
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back(load(b, c));
	}

	pq.push(load(1, 0));  heap[1].push(0);

	while (!pq.empty()) {
		load now = pq.top(); pq.pop();
		int to = now.to;
		int dist = now.dist;

		for (int i = 0; i < vec[to].size(); i++) {
			int next = vec[to][i].to;
			int n_dist = dist + vec[to][i].dist;
			
			if (heap[next].size() < k) {
				heap[next].push(n_dist);
				pq.push(load(next, n_dist));
			}
			else if (heap[next].top() > n_dist) {
				heap[next].pop();
				heap[next].push(n_dist);
				pq.push(load(next, n_dist));
			}

		}

	}

	for (int i = 1; i <= n; i++) {
		if (heap[i].size() != k) cout << -1 << '\n';
		else {
			cout << heap[i].top() << '\n';
		}
	}
}
