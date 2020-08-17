#include<iostream>
#include<string>
#include<algorithm>
#include<memory.h>
#include<vector>
#include<stack>

using namespace std;

int V, E,From,To;
bool visit[100004];
vector<int> vec[100004],vec2[100004],tree[100004];
stack<int> s;
vector <pair<int, int > > what;

void topo(int start) {
	visit[start] = true;
	int Size = vec[start].size();
	for (int i = 0; i < Size; i++) {
		if (!visit[vec[start][i]]) {
			topo(vec[start][i]);
		}
	}
	s.push(start);
}

void kosaraju(int start,int number) {
	visit[start] = true;
	tree[number].push_back(start);
	int Size = vec2[start].size();
	for (int i = 0; i < Size; i++) {
		if (!visit[vec2[start][i]]) {
			kosaraju(vec2[start][i], number);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> V >> E;
	while (E--) {
		cin >> From >> To;
		vec[From].push_back(To);
		vec2[To].push_back(From);
	}
	for (int i = 1; i <= V; i++) {
		if (!visit[i]) topo(i);
	}

	memset(visit, 0, sizeof(visit));

	int treenum = 1;
	while (!s.empty()) {
		int first = s.top();
		s.pop();
		if (!visit[first]) {
			kosaraju(first, treenum);
			treenum++;
		}
	}
	for (int i = 1; i < treenum; i++) {
		sort(tree[i].begin(), tree[i].end());
		what.push_back({ tree[i][0],i });
	}

	sort(what.begin(), what.end());
	int wsize = what.size();
	//what ->{가장 가벼운거번호, 트리번호}
	cout << wsize << '\n';
	for (int i = 0; i < wsize; i++) {
		//what.second 를 이용하장
		int realsize = tree[what[i].second].size();
		for (int j = 0; j < realsize; j++) {
			cout << tree[what[i].second][j] << " ";
		}
		cout << "-1\n";
	}
}