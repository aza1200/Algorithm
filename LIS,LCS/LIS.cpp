#include<iostream>
#include<stack>
#include<stdio.h>
#include<algorithm>

using namespace std;

stack<int> s;
int arr[1004],answer[1004],num,maxi=0;

int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
		answer[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && answer[i] <= answer[j]) {
				answer[i] = answer[j] + 1;
			}
		}
		if (maxi < answer[i]) maxi = answer[i];
	}
	cout << maxi << endl;
	for (int i = num - 1; i >= 0; i--) {
		if (answer[i] == maxi) {
			maxi--;
			s.push(arr[i]);
		}
	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}