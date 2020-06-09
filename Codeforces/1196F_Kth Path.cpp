//https://codeforces.com/contest/1196/problem/F
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
#define inf (long long) (1e17 + 7)
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

const int N = 200005;

struct triad{
    int x, y, w;
};

bool visited[N];
int n, m, k;
vector<triad> edgeList;
ll dist[805][805];
vi chosen;

bool compare(triad a, triad b){
    return a.w < b.w;
}

void floyd(){
    int sz = (int)chosen.size();
    rep(i, 0, sz - 1){
        rep(j, 0, sz - 1){
            if(dist[i][j] == 0 && i != j){
                dist[i][j] = inf;
            }
        }
    }
    rep(k, 0, sz - 1){
        rep(i, 0, sz - 1){
            rep(j, 0, sz - 1){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    priority_queue<ll, vl, greater<ll> > pq;
    rep(i, 0, sz - 1){
        rep(j, i + 1, sz - 1){
            if(dist[i][j] == 0) continue;
            pq.push(dist[i][j]);
        }
    }
    rep(i, 1, k - 1){
        //debug(pq.top());
        pq.pop();
    }
    cout << pq.top();
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    rep(i, 1, m){
        int x, y, w; cin >> x >> y >> w;
        edgeList.pb({x, y, w});
    }
    sort(edgeList.begin(), edgeList.end(), compare);
    rep(i, 0, min(400, m) - 1){
        int x = edgeList[i].x, y = edgeList[i].y, w = edgeList[i].w;
        chosen.pb(x); chosen.pb(y);
    }
    sort(chosen.begin(), chosen.end());
    vi:: iterator it = unique(chosen.begin(), chosen.end());
    chosen.resize(distance(chosen.begin(), it));
    //debuga1(chosen, 0, (int)chosen.size() - 1);
    rep(i, 0, min(m, k) - 1){
        int x = edgeList[i].x, y = edgeList[i].y, w = edgeList[i].w;
        vi::iterator it = lower_bound(chosen.begin(), chosen.end(), x);
        int left = it - chosen.begin();
        it = lower_bound(chosen.begin(), chosen.end(), y);
        int right = it - chosen.begin();
        //debug(left); debug(right);
        dist[left][right] = dist[right][left] = w;
    }
    floyd();
    return 0;
}
