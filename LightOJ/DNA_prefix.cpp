//http://lightoj.com/volume_showproblem.php?problem=1224
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct node {
	struct node *child[4];
	int weight;
	int endW;
};

struct node *addNode() {
	struct node *Node = new struct node;
	Node->endW = 0;
	Node->weight = 0;
	for (int i = 0; i<4; i++) {
		Node->child[i] = NULL;
	}
	return Node;

};

void addWord(struct node *root, string s) {
	int ch;
	struct node *temp = root;
	for (int i = 0; i<s.length(); i++) {
		ch = s[i] - '0';
		if (temp->child[ch] == NULL) {
			temp->child[ch] = addNode();
		}
		temp = temp->child[ch];
		temp->weight += 1;
	}
	temp->endW = 1;
}

int findWord(struct node *root, string s) {
	int ch;
	struct node *temp = root;
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i<s.length(); i++) {
		ch = s[i] - '0';
		if (temp->child[ch] == NULL) {
			return -1;
		}
		temp = temp->child[ch];
		cnt++;
		int temp1 = temp->weight;
		ans = max(ans, cnt*temp1);
	}
	return max(temp->weight*cnt, ans);

}

string convert(string s) {

	string temp = "";
	for (int i = 0; i<s.length(); i++) {
		if (s[i] == 'A') {
			temp += "0";
		}
		else if (s[i] == 'C') {
			temp += "1";
		}
		else if (s[i] == 'G') {
			temp += "2";
		}
		else {
			temp += "3";
		}
	}

	return temp;

}

void deletenode(struct node *temp) {
	for (int i = 0; i<4; i++) {
		if (temp->child[i]) {
			deletenode(temp->child[i]);
			delete temp->child[i];
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	for (int ii = 0; ii<t; ii++) {
		int n;
		cin >> n;
		vector<string> store;
		struct node *root = addNode();

		for (int i = 0; i<n; i++) {
			string s;
			cin >> s;
			s = convert(s);
			store.push_back(s);
			addWord(root, s);
		}

		int ans = 0;
		for (int i = 0; i<store.size(); i++) {
			ans = max(ans, findWord(root, store[i]));
		}
		cout << "Case " << ii + 1 << ": " << ans << endl;
		deletenode(root);
	}
	return 0;
}
