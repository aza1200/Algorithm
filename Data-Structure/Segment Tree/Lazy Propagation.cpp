#include<iostream>
#define ll long long
using namespace std;

ll N,segment[3000004],lazy[3000000],M,K;
ll a, b, c, d,offset;

void LazyUpdate(int left, int right, int now) {
	if (!lazy[now]) return;

	segment[now] += (right - left + 1)*lazy[now];

	if (left != right) {
		lazy[2 * now] += lazy[now];
		lazy[2 * now + 1] += lazy[now];
	}

	lazy[now] = 0;
}

void Update(int dstL, int dstR, int curL, int curR, int now,ll number) {
	LazyUpdate(curL, curR, now);

	if (dstL <= curL && curR <= dstR) {
		lazy[now] += number;
		LazyUpdate(curL, curR, now);
		return;
	}

	if (curR < dstL || dstR < curL) return;

	int mid = (curL + curR) / 2;
	Update(dstL, dstR, curL, mid, 2 * now, number);
	Update(dstL, dstR, mid + 1, curR, 2 * now + 1, number);

	segment[now] = segment[now * 2] + segment[now * 2 + 1];
}

ll Get(int dstL, int dstR, int curL, int curR,int now) {
	LazyUpdate(curL, curR, now);

	if (dstL <= curL && curR <= dstR) return segment[now];
	if (curR < dstL || dstR < curL) return 0;

	int mid = (curL + curR) / 2;
	ll sum_1 = Get(dstL, dstR, curL, mid, now * 2);
	ll sum_2 = Get(dstL, dstR, mid + 1, curR, now * 2 + 1);

	return sum_1 + sum_2;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N>>M>>K;
	for (offset = 1; offset <= N; offset *= 2); offset--;
	for (ll i = 1; i <= N; i++) cin >> segment[offset + i];
	for (ll i = offset; i >= 1; i--) segment[i] = segment[2 * i] + segment[2 * i + 1];

	for (int i = 0; i < M + K; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			Update(b + offset, c + offset, 1 + offset, 2 * offset + 1, 1,d);
		}
		else if (a == 2) {
			cin >> b >> c;
			cout << Get(b + offset, c + offset, 1 + offset, 2 * offset + 1, 1) << '\n';
		}
	}
}