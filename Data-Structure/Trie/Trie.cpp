#include<stdio.h>
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int char_to_index(char c) {
	return c - '0';
}

struct Trie {
	bool is_terminal;     //요놈이 문장의 끝인강
	Trie * next[11];  //포인터배열

	Trie() : is_terminal(false) {
		memset(next, 0, sizeof(next));
	}//생성자

	~Trie() {
		for (int i = 0; i < 11; i++) {
			if (next[i]) delete next[i];
		}
	}//삭제

	void insert(const char *key) {
		if (*key == '\0') {
			is_terminal = true;
		}
		else {
			int index = char_to_index(*key);

			if (next[index] == 0) next[index] = new Trie();

			next[index]->insert(key + 1);
		}
	}

	bool find(const char* key) {
		if (*key == 0) return true;

		if (is_terminal) return false;

		int index = char_to_index(*key);
		return next[index]->find(key + 1);
	}


};

int main() {
	int t;
	cin >> t;

	while (t--) {
		Trie * root = new Trie();
		char phone_books[10000][11];
		memset(phone_books, NULL, sizeof(phone_books));
		int n; cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> phone_books[i];
			root->insert(phone_books[i]);
		}

		bool is_valid = true;

		for (int i = 0; i < n; i++) {
			if (root->find(phone_books[i]) == false) {
				is_valid = false;
				break;
			}
		}
		delete root;

		if (is_valid) cout << "YES\n";
		else cout << "NO\n";
	}
}

//백준 5052번