//https://codejam.withgoogle.com/2018/challenges/0000000000007765/dashboard/000000000003e0a8

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
long long const inf =1000000000000000;
int k = 200;
vector<long long> w;
vector< vector<long long> > f;

void print(){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

long long dp(){
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++){
            long long minN = f[i-1][j];
            //cout << w[i] << endl;
            if(f[i-1][j-1] <= 6ll *w[i]){
                minN = min(minN,f[i-1][j-1] + w[i]);
            }
            f[i][j] = minN;
            //print();
        }
    }
    long long maxN = 0;
    for(long long i = 1; i <= k; i++){
        if(f[n][i]!= inf){
            maxN = max(i, maxN);
        }
    }
    return maxN;
}

int main(){
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    for(int ii = 1; ii <= t; ii++){
        cin >> n;
        w.resize(n+1);
        w[0] = inf;
        for(int i = 1; i <= n; i++){
            cin >> w[i];
        }
        f.resize(n+1);
        for(int i = 0; i <=n ; i++){
            f[i].resize(k+1);
            for(int j = 0; j <=k; j++){
                f[i][j]=inf;
                if(j == 0){
                    f[i][j] = 0;
                }
            }
        }
        cout << "Case #" << ii << ": " << dp() << endl;
    }
    return 0;
}
