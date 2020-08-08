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
int degree[N];
vi graph[N];
bool visited[N];

int main(){
    int n; cin >> n;
    rep(i, 1, n - 1){
        int x, y; cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
        degree[x]++;
        degree[y]++;
    }
    vi oddLst;
    rep(i, 1, n){
        if(degree[i] == 1){
            oddLst.pb(i);
        }
    }
    int cnt = n;
    while(cnt > 1){
        int x = oddLst.back();
        oddLst.pop_back();
        int y = oddLst.back();
        oddLst.pop_back();
        cout << "? " << x << " " << y << "\n";
        cout.flush();
        int w; cin >> w;
        if(w == x || w == y){
            cout << "! " << w << "\n";
            cout.flush();
            return 0;
        }
        degree[x]--;
        degree[y]--;
        visited[x] = visited[y] = 1;
        foreach(v, graph[x]){
            if(degree[v] == 0) continue;
            degree[v]--;
            if(degree[v] == 1){
                oddLst.pb(v);
            }
        }
        foreach(v, graph[y]){
            if(degree[v] == 0) continue;
            degree[v]--;
            if(degree[v] == 1){
                oddLst.pb(v);
            }
        }
        cnt-=2;
    }
    rep(i, 1, n){
        if(!visited[i]){
            cout << "! " << i << "\n";
            cout.flush();
            return 0;
        }

    }
    return 0;
}
