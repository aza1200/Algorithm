#include<iostream>
#include<queue>
#include<vector>
#define ll long long 

using namespace std;

int TC,answer[505];
struct load {
	int from;
	int to;
	int dist;
	load(int a,int b,int c):from(a),to(b),dist(c){}
};

//500 500 500
//125 00 00 00

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> TC;

	while (TC--) {
		int N, M, W;
		cin >> N >> M >> W;
		for (int i = 1; i <= N; i++) answer[i] = 987654321;
		vector<load> vec;
		int S, E, T;
		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			vec.push_back(load(S, E, T));
			vec.push_back(load(E, S, T));
		}
		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			vec.push_back(load(S, E, -T));
		}
		bool cycle = false;


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < vec.size(); j++) {
				load now = vec[j];
				if (answer[now.to] > answer[now.from] + now.dist) {
					answer[now.to] = answer[now.from] + now.dist;
				}
			}
		}
		
		for (int j = 0; j < vec.size(); j++) {
			load now = vec[j];
			if (answer[now.to] > answer[now.from] + now.dist) {
				cycle = true;
			}
		}

		if (cycle) cout << "YES\n";
		else cout << "NO\n";


	}

						

}
