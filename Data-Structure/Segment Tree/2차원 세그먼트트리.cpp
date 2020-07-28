#include<iostream>
#include<memory.h>
#include<algorithm>

#define ll long long

using namespace std;

ll N, M,segment[4000][4000],offset;

void Update(int x, int y, int c) {
	int i = x + offset, j = y + offset;
	segment[i][j] = c;

	while (j>1) {
		j /= 2;
		segment[i][j] = segment[i][j * 2] + segment[i][j * 2 + 1];
	}

	while (i>1) {
		j = y + offset;
		i /= 2;
		segment[i][j] = segment[i * 2][j] + segment[i * 2 + 1][j];
		while (j > 1) {
			j /= 2;
			segment[i][j] = segment[i][j * 2] + segment[i][j * 2 + 1];
		}

	}

	return;
}

ll xquery(int y,int dstL,int dstR,int now,int curL,int curR) {
	if (dstL <= curL && curR <= dstR) return segment[y][now];
	else if (dstR < curL || curR < dstL) return 0;
	int mid = (curL + curR) / 2;
	return xquery(y, dstL, dstR, now * 2, curL, mid) + xquery(y,dstL,dstR,now*2+1,mid+1,curR);
}

ll yquery(int dstL, int dstR, int now, int curL, int curR, int x1, int x2) {
	if (dstL <= curL && curR <= dstR) return xquery(now, x1, x2, 1,1+offset,2*offset+1);
	else if (dstR < curL || curR < dstL) return 0;
	int mid = (curL + curR) / 2;
	return yquery(dstL, dstR, now * 2, curL, mid, x1, x2) + yquery(dstL, dstR, now * 2 + 1, mid + 1, curR, x1, x2);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;

	if (N == 1) offset = 1;
	else {
		for (offset = 1; offset < N; offset *= 2); offset--;
	}

	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) cin >> segment[i+offset][j+offset];

	for (int i = N+offset ; i >=1; i--) {
		for (int j = offset; j >= 1; j--) {
			segment[i][j] = segment[i][j * 2] + segment[i][j * 2 + 1];
			segment[j][i] = segment[j * 2][i] + segment[j * 2 + 1][i];
		}
	}

	while (M--) {
		int w, x, y, c;
		int x1, y1, x2, y2;
		cin >> w;

		if (!w) {
			cin >> x >> y >> c;
			Update(x, y, c);
		}
		else {
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 > x2) swap(x1, x2);
			if (y1 > y2) swap(y1, y2);
			cout << yquery(x1+offset,x2+offset,1,1+offset,2*offset+1,y1+offset,y2+offset) << "\n";
		}
		/*
		cout << "\n";
		for (int i = 1; i <= N + offset; i++) {
			for (int j = 1; j <= N + offset; j++) {
				cout << segment[i][j] << " ";
			}
			cout << "\n";
		}
		*/

	}
}