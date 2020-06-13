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

const int N = 0;
vector<string > graph;
vector<vector<bool> > visited;

int n, m, d;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
struct node{
    int x,y,d;
};

void bfsMonster(){
    queue<node> q;
    rep(i, 0, n - 1){
        rep(j, 0, m - 1){
            if(graph[i][j] == 'M'){
                q.push({i, j, d});
            }
        }
    }
    while(!q.empty()){
        node cur = q.front(); q.pop();
        if(cur.d == 0){
            continue;
        }
        rep(i, 0, 3){
            int x = cur.x + dx[i];
            int y = cur.y + dy[i];
            if(x < 0 || y < 0 || x >= n ||y >= m || graph[x][y] == 'M'){
                continue;
            }
            graph[x][y] = 'M';
            q.push({x, y, cur.d - 1});
        }
    }
}

int bfs(){
    queue<node> q;
    visited.resize(n);
    rep(i, 0, n - 1){
        visited[i].resize(m, 0);
    }
    rep(i, 0, n - 1){
        rep(j, 0, m - 1){
            if(graph[i][j] == 'S'){
                q.push({i, j, 0});
                visited[i][j] = 1;
            }
        }
    }
    while(!q.empty()){
        node cur = q.front(); q.pop();
        if(graph[cur.x][cur.y] == 'F'){
            return cur.d;
        }
        rep(i, 0, 3){
            int x = dx[i] + cur.x;
            int y = dy[i] + cur.y;

            if(x < 0 || y < 0 || x >= n ||y >= m || graph[x][y] == 'M' || visited[x][y]){
                continue;
            }

            if(graph[x][y] == '.' || graph[x][y] == 'F'){
                q.push({x, y, cur.d + 1});
                visited[x][y] = 1;
            }
        }
    }
    return -1;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m >> d;
    graph.resize(n + 5);
    rep(i, 0, n - 1){
        cin >> graph[i];
    }
    bfsMonster();
    cout << bfs() << endl;

    return 0;
}
