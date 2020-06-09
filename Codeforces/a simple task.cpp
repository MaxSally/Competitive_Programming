//http://codeforces.com/problemset/problem/11/D

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
#define right fgjhk
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

const int N = 19;
int n, m;
bool graph[N][N];
ll maxFirst[1 << N];
ll dp[1 << N][N];

void createDistance(){
    rep(setN, (1 << n)){
        rep(i, n){
            rep(j, n){
                if((setN & (1 << i)) > 0 && (setN & (1 << j)) > 0 && graph[j][i] && i != maxFirst[setN]){
                    dp[setN][i] += dp[setN ^ (1 << i)][j];
                }
            }
        }
    }
}

void process(){
    mem(maxFirst, 0);
    rep(i, (1 << n)){
        mem(dp[i], 0);
        rep(j, n){
            if((i & (1 << j)) > 0){
                maxFirst[i] = j;
                break;
            }
        }
    }
    rep(i, n){
        dp[1 << i][i] = 1;
    }
}

void output(){
    ll res = 0;
    rep(setN, (1 << n)){
        if(__builtin_popcount(setN) > 2){
            int a = maxFirst[setN];
            rep(i, n){
                if((setN & (1 << i)) > 0){
                    if(graph[a][i]){
                        res += (ll) dp[setN][i];
                    }
                }
            }
        }
    }
    cout << res/2ll;
}

int main(){
    io
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    rep(i, N){
        mem(graph[i], 0);
    }
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    process();
    createDistance();
    output();
    return 0;
}
