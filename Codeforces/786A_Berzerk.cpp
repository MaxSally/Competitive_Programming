//https://codeforces.com/problemset/problem/786/A
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

const int N = 7005;
int a[N], b[N], n, cnt[N][2], dp[N][2], k1, k2, degree[N][2];
bool visited[N][2]; // dp = -1 => lose
//vii graph[N][2];

void solve(){
    dp[1][0] = dp[1][1] = -1;
    queue<pair<int,int> > q;
    q.push(mp(1, 0));
    q.push(mp(1, 1));
    visited[1][0] = visited[1][1] = 1;
    while(q.size()){
        int v = q.front().first;
        bool turn = q.front().second;
        q.pop();
        if(dp[v][turn] == -1){
            if(turn){
                rep(i, 0, k1 - 1){
                    int nxt = (v - a[i] + n) % n;
                    if(nxt == 0) nxt = n;
                    bool nxtTurn = !turn;
                    if(visited[nxt][nxtTurn]) continue;
                    dp[nxt][nxtTurn] = 1;
                    q.push(mp(nxt, nxtTurn));
                    visited[nxt][nxtTurn] = 1;
                }
            }else{
                rep(i, 0, k2 - 1){
                    int nxt = (v - b[i] + n) % n;
                    if(nxt == 0) nxt = n;
                    bool nxtTurn = !turn;
                    if(visited[nxt][nxtTurn]) continue;
                    dp[nxt][nxtTurn] = 1;
                    q.push(mp(nxt, nxtTurn));
                    visited[nxt][nxtTurn] = 1;
                }
            }
        }else if(dp[v][turn] == 1){
            if(turn){
                rep(i, 0, k1 - 1){
                    int nxt = (v - a[i] + n) % n;
                    if(nxt == 0) nxt = n;
                    bool nxtTurn = !turn;
                    cnt[nxt][nxtTurn]++;
                    if(cnt[nxt][nxtTurn] == (nxtTurn? k2: k1)){
                        if(visited[nxt][nxtTurn]) continue;
                        dp[nxt][nxtTurn] = -1;
                        q.push(mp(nxt, nxtTurn));
                        visited[nxt][nxtTurn] = 1;
                    }
                }
            }else{
                rep(i, 0, k2 - 1){
                    int nxt = (v - b[i] + n) % n;
                    if(nxt == 0) nxt = n;
                    bool nxtTurn = !turn;
                    cnt[nxt][nxtTurn]++;
                    if(cnt[nxt][nxtTurn] == (nxtTurn? k2: k1)){
                        if(visited[nxt][nxtTurn]) continue;
                        dp[nxt][nxtTurn] = -1;
                        q.push(mp(nxt, nxtTurn));
                        visited[nxt][nxtTurn] = 1;
                    }
                }
            }
        }
    }
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> k1;
    rep(i, 0, k1 - 1){
        cin >> a[i];
    }
    cin >> k2;
    rep(i, 0, k2 - 1){
        cin >> b[i];
    }
    /*rep(i, 1, n){
        rep(j, 0, k2 - 1){
            int nxt = (i - b[j] + n) % n;
            if(nxt == 0) nxt = n;
            graph[i][0].pb(mp(nxt, 1));
            degree[nxt][1]++;
        }
        rep(j, 0, k1 - 1){
            int nxt = (i - a[j] + n) % n;
            if(nxt == 0) nxt = n;
            graph[i][1].pb(mp(nxt, 0));
            degree[nxt][0]++;
        }
    }*/
    solve();
    rep(j, 0, 1){
        rep(i, 2, n){
            switch(dp[i][j]){
            case 1:
                cout << "Win ";
                break;
            case -1:
                cout << "Lose ";
                break;
            case 0:
                cout << "Loop ";
                break;
            }
        }
        cout << endl;
    }
    return 0;
}

