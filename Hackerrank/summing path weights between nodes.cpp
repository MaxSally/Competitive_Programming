//https://www.hackerrank.com/contests/101hack49/challenges/summing-the-path-weights-between-nodes

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

struct triad{
    ll x, y, z;
    triad(int x, int y , int z){
        this -> x = x;
        this -> y = y;
        this -> z = z;
    }
};

const int N = 100005;
int n;
vpll graph[N];
bool state[N];
ll dp[2][N];
bool visited[N];
ll res = 0;

void dfs(int node){
    visited[node] = 1;
    dp[state[node]][node]++;
    rep(i, (int) graph[node].size()){
        ll b = graph[node][i].first;
        if(visited[b]) continue;
        dfs(b);
        dp[0][node] += dp[0][b];
        dp[1][node] += dp[1][b];
    }
}

void findRes(int node){
    visited[node] = 1;
    rep(i, (int) graph[node].size()){
        ll b = graph[node][i].first;
        ll c = graph[node][i].second;
        if(visited[b]) continue;
        res += c*(dp[0][b]*(dp[1][1] - dp[1][b]) + dp[1][b]*(dp[0][1] - dp[0][b]));
        findRes(b);
    }
}

int main(){
    io
    //freopen("input.txt","r",stdin);
    cin >> n;
    rep(i, n){
        cin >> state[i + 1];
    }
    rep(i, n - 1){
        ll x, y, z;
        cin >> x >> y >> z;
        graph[x].pb(mp(y, z));
        graph[y].pb(mp(x, z));
    }
    rep(i, 2){
        mem(dp[i], 0);
    }
    mem(visited, 0);
    dfs(1);
//    rep(i, 2){
//        rep(j, n + 1){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
    mem(visited, 0);
    findRes(1);
    cout << res;
    return 0;
}
/*
di tu cac dinh xuong,
chia theo doan, dem xem mot doan dc su dung bao nhieu lan.
do * den + den* do) * w
dp[0][1] - dp[0][v]
dp[i][j]: voi color i, and a parent node: j, there are #number of i color node.
*/

