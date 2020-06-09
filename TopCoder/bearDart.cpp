//http://community.topcoder.com/stat?c=problem_statement&pm=13479&rd=16551

/*
sort(unique(w));
M[w[i]] = so luong so nho hon w[i] + 1 for i
cnt[i][x] = tu n - 1 tro ve i, x lap lai may lan
for(i = n -1 -> 0)
	for(int x 1 in range )
		cnt[i][x] = cnt[i + 1][x]
	cnt[i][M[w[i]]]++;

M 0 1 2 3 4 5 6 7 8 9
      1         2

product = a b c
res += cnt[k + 1][M[product]]

*/

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include<string>
#include <map>
#include <queue>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double


int M[1000005];
    int cnt[505][510];

class BearDartsDiv2{
    vector<int> v;


    public: long count(vector<int> w){
        long res = 0;
        int length = w.size();
        v = w;
        //cout <<"YES" << endl;
        v.resize(unique(v.begin(), v.end()) - v.begin());
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            M[v[i]] = i + 1;
        }
        for(int i = w.size() - 1; i >= 0; i--){
            for(int j = 0; j < 505; j++){
            	if(i == (w.size() - 1)){
            		cnt[i][j] = 0;
            	}else{
            		cnt[i][j] = cnt[i + 1][j];
            	}
            }
            cnt[i][M[w[i]]]++;
        }
        for(int i = 0; i < length; i++){
            for(int j = i + 1; j < length; j++){
                for(int k = j + 1; k < length; k++){
                    long long product = 1ll*w[i] * w[j] * w[k];
                    if(product > 1e6)
                        continue;
                    res += cnt[k + 1][M[(int) product]];
                }
            }
        }
        return res;
    };
};

int main(){
    //freopen("input.txt","r",stdin);
    BearDartsDiv2 q;
    int n, t;
    //cin >> t;
    //cout << t  << endl;
    //while(t--){
        cin >> n;
        //cout << n << endl;
        vector<int> w;
        w.resize(n);
        for(int i = 0; i < n; i++){
            //cout << i << endl;
            cin >> w[i];
        }
        cout << q.count(w) << endl;

    return 0;
}
