#include<stack>
#include<vector>
#include<iostream>
#include<stdio.h>
using namespace std;
stack< pair<int, int> > process;
vector<int> cat;
vector< vector<int> > tree;
int n, m;

int DFS() {
	int res = 0;
	process.push(make_pair(1, 0));
	while (!process.empty()) {
		int ind = process.top().first;;
		int cntCat = process.top().second;
		process.pop();
		if (cat[ind] == 1) {
			cntCat++;
		}
		else {
			cntCat = 0;
		}
		if (cntCat <= m) {
			int temp = tree[ind].size();
			for (int i = 0; i<temp; i++) {
				process.push(make_pair(tree[ind][i], cntCat));
			}
		}
		if (tree[ind].empty() && cntCat <= m) {
			res++;
		}

	}

	return res;

}


int main() {
	freopen("kefa_and_park_580C.txt", "r", stdin);
	cin >> n >> m;
	tree.resize(n + 1);
	cat.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> cat[i];
	}
	for (int i = 1; i<n; i++) {
		int xi, yi;
		cin >> xi >> yi;
		if (xi<yi) {
			tree[xi].push_back(yi);
		}
		else {
			tree[yi].push_back(xi);
		}

	}
	cout << DFS();

}
