//http://codeforces.com/problemset/problem/118/D

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n1,n2,k1,k2;
const int n =105;
const int modulo = 100000000;
int dp[n][n][2];            //0: solider

int minN(int a, int b){
    if(a < b){
        return a;
    }
    return b;
}

void dynamics(){
    for(int i = 1; i <= n1; i++){
        for(int j = 1; j<=n2; j++){
            for(int k = 1; k <= minN(k1,i); k++){
                dp[i][j][0] += dp[i-k][j][1] % modulo;
            }
            for(int k = 1; k <= minN(k2,j); k++){
                dp[i][j][1] += dp[i][j-k][0]% modulo;
            }
        }
    }

}

int main(){
    freopen("input.txt","r",stdin);
    cin >> n1 >> n2 >> k1 >> k2;
    for(int i = 0; i <= n1; i++){
        if(i <= k1){
            dp[i][0][0] = 1;
        }else{
            dp[i][0][0] = 0;
        }
    }
    for(int i = 0; i <= n2; i++){
        if(i <= k2){
            dp[0][i][1]=1;
        }else{
            dp[0][i][1]=0;
        }
    }
    dynamics();
    cout << (dp[n1][n2][0] + dp[n1][n2][1]) % modulo << endl;
    return 0;

}
