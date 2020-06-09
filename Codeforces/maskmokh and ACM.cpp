//https://codeforces.com/problemset/problem/414/B

/*
* Author : Max Nguyen
*/
/********   All Required Header Files ********/
#include<bits/stdc++.h>
using namespace std;
/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define mem(a, b) memset(a, (b), sizeof(a))
#define fo(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define rfor(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define rep(i, j) fo(i, 0, j, 1)
#define rrep(i, j) rfor(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define forEach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define in(A, B, C) assert( B <= A && A <= C)
#define mp make_pair
#define pb push_back
#define inf (int)1e9
#define epsi 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define left tuyiuoi
#define right fgjhkj
const double pi=acos(-1.0);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int n, k;
ll dp[2005][2005]; //dp[k][n]: so cach voi do dai la k va so cuoi cung la n

void sum(){
    dp[0][0] = 1;
    dp[0][1] = 1;
    fo(i, 0, k + 1, 1){
        fo(j, 1, n + 1, 1){
            fo(h, j, n + 1, j){
                dp[i + 1][h] = (dp[i + 1][h] + dp[i][j]) % MOD;
            }
        }
    }
//    fo(i, 0, k + 1, 1){
//        fo(j, 0, n + 1, 1){
//            cout  << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
}

int main(){
    io
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    sum();
    ll ans = 0;
    fo(i, 1, n + 1, 1){
        ans = (ans + dp[k][i]) % MOD;
    }
    cout << ans;
    return 0;
}
