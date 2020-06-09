//http://community.topcoder.com/stat?c=problem_statement&pm=14809&rd=17064

#include<vector>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;


int f[305][10005];
int sum[305][10005];

class IncreasingSequencesEasy{
public: int count(vector<int> L, vector<int> R){
        int n = (int) L.size();
        const int mod = 998244353;
       /* L.push_back(-1);
        R.push_back(-1);
        for(int i=n;i>0;i--){
            L[i]=L[i-1];
        }
        L[0]=-1;
        for(int i=n;i>0;i--){
            R[i]=R[i-1];
        }
        R[0]=-1;*/
        f[0][0]=1;
        for(int j = 0; j < 10005; j++){
        	sum[0][j] = 1;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 10005; j++){
                if(j <= R[i-1] && j >= L[i-1]){
                    (f[i][j] += sum[i-1][j-1]) %= mod ;
                    (sum[i][j] += (f[i][j])) %= mod ;
                }
            }
            for(int j = 1; j < 10005; j++){
        		(sum[i][j] += sum[i][j-1]) %= mod;

        	}
        }

        return sum[n][10004];
    }

};

IncreasingSequencesEasy I;

int main(){
    //freopen("input.txt","r",stdin);
    int n,a;
    cin >> n;
    vector<int> L, R;
    for(int i=0;i<n;i++){
        cin >> a;
        L.push_back(a);
    }

    for(int i=0;i<n;i++){
        cin >> a;
        R.push_back(a);
    }

    cout << I.count(L,R);

    return 0;
}
