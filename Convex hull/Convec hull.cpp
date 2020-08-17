#include<vector>
#include<stack>
#include<algorithm>
#include<iostream>
#define ll long long

using namespace std;

struct point {
	ll x,y;
	ll r_x,r_y;
	point(ll a, ll b,ll c,ll d) :x(a), y(b), r_x(c), r_y(d) {}

};

bool operator<(point a, point b) {
	if ((a.r_x)*(b.r_y) != (a.r_y)*(b.r_x)) {
		return (a.r_y)*(b.r_x) < (a.r_x)*(b.r_y);
	}


	else if (a.y != b.y) return a.y < b.y;
	else return a.x < b.x;


}


long long ccw(point A, point B, point C) {
	ll a = B.x - A.x;
	ll b = B.y - A.y;

	ll c = C.x - A.x;
	ll d = C.y - A.y;

	return a * d - b * c;
}

int N;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;

	vector<point> vec;


	for (int i = 0; i < N; i++) {
		ll a, b ;
		cin >> a >> b;
		vec.push_back(point(a, b,0,0));
	}
	sort(vec.begin(), vec.end());

	for (int i = 1; i < N; i++) {
		vec[i].r_x = vec[i].x - vec[0].x;
		vec[i].r_y = vec[i].y - vec[0].y;
		//cout << vec[i].x << " " << vec[i].y << " " << vec[i].r_x << " " << vec[i].r_y<<"\n";
	}

	sort(vec.begin() + 1, vec.end());
	stack<int> s;
	int next = 2;

	s.push(0);
	s.push(1);

	while (next < N) {
		while (s.size() >= 2) {
			int first, second;
			second = s.top();
			s.pop();
			first = s.top();
			if (ccw(vec[first],vec[second],vec[next]) > 0) {
				s.push(second);
				break;
			}
		}
		s.push(next++);
	}

	cout << s.size() << '\n';
}