#include<algorithm>
#include<iostream>

using namespace std;

int arr[11][11];
int visit[11][11][11];
int area_check[11][11];
/*
1 2 3
4 5 6 
7 8 9
*/
int getarea(int row, int col) {
	if (row <= 3) {
		if (col <= 3) return 1;
		else if (col <= 6) return 2;
		else return 3;
	}
	else if (row <= 6) {
		if (col <= 3) return 4;
		else if (col <= 6) return 5;
		else return 6;
	}
	else if (row <= 9) {
		if (col <= 3) return 7;
		else if (col <= 6) return 8;
		else return 9;
	}
}

void numcheck(int row, int col, int num,bool check) {
	int area = getarea(row, col);

	if(check) area_check[area][num]++;
	else area_check[area][num]--;

	for (int i = 1; i <= 9; i++) {
		if (check) visit[row][i][num]++;
		else visit[row][i][num]--;

		if (check) visit[i][col][num]++;
		else visit[i][col][num]--;
	}
	if (check) visit[row][col][num]--;
	else visit[row][col][num]++;
}

void backtracking(int row, int col) {
	if (row == 10) {
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}

	if (arr[row][col]) {
		if (col == 9) backtracking(row + 1, 1);
		else backtracking(row, col + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			int area = getarea(row, col);
			if (!visit[row][col][i] && !area_check[area][i]) {
				arr[row][col] = i;
				numcheck(row, col, i, 1);
				if (col == 9) backtracking(row + 1, 1);
				else backtracking(row, col + 1);
				numcheck(row, col, i, 0);
				arr[row][col] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) numcheck(i, j,arr[i][j],true);
		}
	}

	backtracking(1, 1);
}