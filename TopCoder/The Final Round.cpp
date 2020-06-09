#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000005;

int cnt[505][505];
int M[MAX_N];

class BearDartsDiv2 {
	public:
	long long countN(vector <int> a) {
		int n = (int) a.size();

		vector <int> w = a;
		sort(w.begin(), w.end());

		int p = 0;
		int prev = -1;

		for (int i = 0; i < n; i++) {
			if (w[i] != prev) {
				p++;
				M[w[i]] = p;
			}

			prev = w[i];
		}

		for (int i = n - 1; i >= 0; i--) {
			cnt[i][M[a[i]]]++;
			for (int j = 1; j <= n; j++) {
				cnt[i][j] += cnt[i + 1][j];
			}
		}

		long long res = 0LL;

		for (int i = 0; i < n - 3; i++) {
			for (int j = i + 1; j < n - 2; j++) {
				for (int k = j + 1; j < n - 1; k++) {
					long long val = 1LL * a[i] * a[j] * a[k];
					if (val > 1000000) {
						continue;
					}

					res += cnt[k + 1][M[val]];
				}
			}
		}

		return res;
	}
};

BearDartsDiv2 B;

int main () {
    freopen("input.txt", "r", stdin);
	int n;
	vector <int> w;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		w.push_back(x);
	}
	//freopen("output.txt", "w", stdout);

	cout << B.countN(w);
	return 0;
}
