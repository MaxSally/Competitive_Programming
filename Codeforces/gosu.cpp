//https://codeforces.com/gym/102202/problem/B
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

const int N = 3005;
int n;
vi graph[N];

int bfs(int s){
    queue<int> q;
    q.push(s);
    vector<bool> visited(n + 1, 0);
    vector<int> h(n + 1, -1);
    h[s] = 0;
    visited[s] = 1;
    int cnt = 1;
    while(q.size()){
        int u = q.front(); q.pop();
        if(cnt == n) break;
        for(int a: graph[u]){
            if(cnt == n) break;
            if(visited[a])continue;
            visited[a] = 1;
            q.push(a);
            h[a] = h[u] + 1;
            cnt++;
        }
    }
    int maxN = 0;
    rep(i, 1, n){
        if(h[i] == -1) h[i] = 9000;
        maxN = max(maxN, h[i]);
    }
    return maxN;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n;
    int winner, d;
    winner = 1;
    d = 1;
    rep(i, 1, n){
        int tempD = 0;
        rep(j, 1, n){
            char c; cin >> c;
            if(c == 'W'){
                tempD++;
            }
        }
        if(d < tempD){
            d = tempD;
            winner = i;
        }
    }
    if(d == n - 1){
        cout << "1 " << winner << endl;
    }else{
        cout << "2 " << winner << endl;
    }
    return 0;
}

