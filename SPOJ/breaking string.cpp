//https://www.spoj.com/problems/BRKSTRNG/

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
#define inf (int) (1e9 + 7)
#define epsi 1e-9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
#define read(type) readInt<type>()
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define left tuyiuoi
#define right fgjhk
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
const double pi=acos(-1.0);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<ll, ll> pll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int M = 1005;
int n, m, A[M][M];
ll dp[M][M], breakP[M];

ll process(){
    fo(len, 1, m, 1){
        rep(l, m - len){
            int r = l + len;
            if(len < 2){
                dp[l][r] = 0;
                A[l][r] = r;
            }else{
                ll ans, res;
                ans = res = inf;
                fo(k, A[l][r - 1], A[l + 1][r] + 1, 1){
                    ll temp = dp[l][k] + dp[k][r] + breakP[r] - breakP[l];
                    if(ans > temp){
                        ans = temp;
                        res = k;
                    }
                }
                dp[l][r] = ans;
                A[l][r] = res;
            }
        }
    }
    return dp[0][m - 1];
}

int main(){
    io
    freopen("input.txt","r",stdin);
    while(cin >> n){
        cin >> m;
        breakP[0] = 0;
        fo(i, 1, m + 1, 1){
            cin >> breakP[i];
        }
        breakP[m + 1] = n;
        m += 2;
        rep(i, M){
            mem(dp[i], 0);
            mem(A[i], 0);
        }
        cout << process() << endl;
    }
    return 0;
}

