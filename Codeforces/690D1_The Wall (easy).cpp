//https://codeforces.com/problemset/problem/690/D1
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

const int N = 105;

bool a[N][N], visited[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int r, c;

void bfs(int u, int v){
    visited[u][v] = 1;
    queue<pii> q;
    q.push({u, v});
    while(q.size()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        rep(i, 0, 3){
            int x1 = x + dx[i], y1 = y + dy[i];
            if(x1 < 0 || x1 >= r || y1 < 0 || y1 >= c || !a[x1][y1] || visited[x1][y1])continue;
            visited[x1][y1] = 1;
            q.push({x1, y1});
        }
    }
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> r >> c;
    rep(i, 0, r - 1){
        mem(visited[i], 0);
        mem(a[i], 0);
    }
    rep(i, 0, r - 1){
        rep(j, 0, c - 1){
            char d; cin >> d;
            a[i][j] = (d == 'B');
        }
    }
    int cnt = 0;
    rep(i, 0, r - 1){
        rep(j, 0, c - 1){
            if(!visited[i][j] && a[i][j]){
                bfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
