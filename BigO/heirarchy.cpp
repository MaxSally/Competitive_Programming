//http://bigocoder.com/courses/ORANGE01/ORANGE01_LEC01/ORANGE_L01P02/statement
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

const int N = 100005;
vi g[N], ans;
int level[N], path[N];
int n, k;

bool topological_sort_kahn(){
    queue<int> q;
    rep(i, 1, n){
        if(level[i] == 0) q.push(i);
    }
    while(q.size()){
        int u = q.front(); q.pop();
        //debug(u);
        path[u] = ans.size();
        ans.pb(u);
        for(int i: g[u]){
            level[i]--;
            if(level[i] == 0){
                q.push(i);
            }
        }
    }
    rep(i, 1, n){
        if(level[i]) return false;
    }
    return true;
}

int main(){
    io
    freopen("input.txt","r",stdin);
    cin >> n >> k;
    mem(level, 0); mem(path, 0);
    rep(i, 1, k){
        int wish, y; cin >> wish;
        while(wish--){
            cin >> y;
            g[i].pb(y);
            level[y]++;
        }
    }

    if(topological_sort_kahn()){
        //debuga1(ans, 0, n - 1);
        rep(i, 1, n){
            if(path[i] == 0)
                cout << 0 << endl;
            else
                cout << ans[path[i] - 1] << endl;
        }
    }
    return 0;
}

