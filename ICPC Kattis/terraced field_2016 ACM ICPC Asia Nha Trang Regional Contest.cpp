//https://vietnam-practice.kattis.com/problems/terracedfields
/*
* Author : MaxSally
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
#define rep(i, j, k) for (int i = j ; i <= k ; ++i)
#define rrep(i, j, k) for (int i = j; i >= k; --i)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define foreach(i, a) for(auto i: a)
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
#define ss second
#define ff first
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) rep(i, l, r) cout << a[i] << " "; cout << endl
#define Flag(n) cout << "here " << n << endl
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

const int N = 130;
int cnt[2][N];

int cntNumber(ll number, int compareNum){
    int cnt = 0;
    while(number > 0){
        if(number % 10 == compareNum){
            cnt++;
        }
        number = number/10;
    }
    return cnt;
}

void createCnt(int ind, int num){
    for(int i = 1; i * num < N; ++i){
        cnt[ind][i] = cnt[ind][i - 1] + cntNumber(1LL * i * num, num);
    }
}

ll dp[20][20][2][8]; //dp[# of lucky digit][digit ith][smaller or bigger than n][n % k];

ll find68(ll n){
    rep(i, 0, 19){
        rep(j, 0, 19){
            rep(k, 0, 1){
                mem(dp[i][j][k], 0);
            }
        }
    }
    string s = to_string(n);
    int length = s.length();
    rep(i, 0, s[0] - '0'){
        dp[(i == 6 || i == 8)][0][i < (s[0] - '0')][i % 8]++;
    }
    //debug(dp[1][0][0][0]);
    rep(luckyDigi, 0, length - 1){
        rep(i, 0, length - 2){
            rep(lo, 0, 1){
                rep(leftOver, 0, 7){
                    int lim = (lo? 9: s[i + 1] - '0');
                    rep(k, 0, lim){
                        dp[luckyDigi + (k == 6 || k == 8)][i + 1][lo | (k < (s[i + 1] - '0'))][(leftOver * 10 + k) % 8] += dp[luckyDigi][i][lo][leftOver];
                    }
                }
            }
        }
    }
    ll res = 0;
    rep(i, 1, length){
        res += 1LL * i * (dp[i][length - 1][0][0] + dp[i][length - 1][1][0]);
    }
    return res;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    //createCnt(0, 6);
    //createCnt(1, 8);
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        n--;
        ll ans = find68(n) + cntNumber(n + 1, 6) + cntNumber(n + 1, 8);
        cout << ans << "\n";
    }
    return 0;
}
