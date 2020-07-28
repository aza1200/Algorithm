#include<iostream>
#define ll long long 
using namespace std;

ll N, M, K, segment[2500003], offset;

ll getsum(int dstL, int dstR, int curL, int curR, int now) {

	if (dstL <= curL && curR <= dstR) return segment[now];

	if (curR < dstL || dstR < curL) return 0;
	else {
		int mid = (curL + curR) / 2;
		ll getsum_1 = getsum(dstL, dstR, curL, mid, now * 2);
		ll getsum_2 = getsum(dstL, dstR, mid + 1, curR, now * 2 + 1);
		return getsum_1 + getsum_2;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N>>M>>K;

	if (N == 1) offset = 1;
	else {
		for (offset = 1; offset < N; offset *= 2); offset--;
	}
	//cout << offset << '\n';

	for (int i = 1; i <= N; i++) cin >> segment[i + offset];
	for (int i = offset; i >= 1; i--) segment[i] = segment[2 * i] + segment[2 * i + 1];


	for (int i = 0; i < M + K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			ll differ = c - segment[b + offset];
			int now = b + offset;
			while (now) {
				segment[now] += differ;
				now /= 2;
			}
		}
		else if (a == 2) {
			cout << getsum(b + offset, c + offset, 1 + offset, offset * 2 + 1, 1) << '\n';
		}
	}

}
