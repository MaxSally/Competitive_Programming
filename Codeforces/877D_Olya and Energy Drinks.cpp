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

const int N = 1005;
int n, m, k;
bool graph[N][N], visited[N][N];
pii start, stop;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(){
    int cnt = 0;
    queue<pii> q;
    q.push(start);
    visited[start.ff][start.ss] = 1;
    while(!q.empty()){
        cnt++;
        int len = q.size();
        rep(i, 1, len){
            pii current = q.front();
            q.pop();
            rep(j, 0, 3){
                rep(h, 1, k){
                    int x = current.ff + dx[j] * h;
                    int y = current.ss + dy[j] * h;
                    if(x <= 0 || y <= 0 || x > n || y > m || graph[x][y]){
                        break;
                    }
                    if(visited[x][y])continue;
                    visited[x][y] = 1;
                    q.push({x, y});
                    if(x == stop.ff && y == stop.ss){
                        return cnt;
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    rep(i, 1, n){
        rep(j, 1, m){
            char c; cin >> c;
            if(c == '.'){
                graph[i][j] = 0;
            }else{
                graph[i][j] = 1;
            }
        }
    }
    cin >> start.ff >> start.ss >> stop.ff >> stop.ss;
    if(start == stop){
        cout << 0;
        return 0;
    }
    cout << bfs();
    return 0;
}
