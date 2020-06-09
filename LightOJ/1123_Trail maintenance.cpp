//http://lightoj.com/volume_showproblem.php?problem=1123
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

const int N = 205;

struct triad{
    int u, v, w;
};

bool compare(triad x, triad y){
    return x.w < y.w;
}

vector<triad> edge;
int n, w, dsu[N];

int findSet(int u){
    return (dsu[u] == u? u: dsu[u] = findSet(dsu[u]));
}

int kruskal(){
    rep(i, 1, n){
        dsu[i] = i;
    }
    int i = 0, cnt = 0, sum = 0;
    set<int> seleted;
    while(i < (int)edge.size() && cnt < n){
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        int x = findSet(u), y = findSet(v);
        if(x != y){
            cnt++;
            dsu[y] = x;
            sum += w;
            seleted.insert(i);
        }
        i++;
    }
    rrep(i, (int)edge.size() - 1, 0){
        if(seleted.find(i) == seleted.end()){
            edge.erase(edge.begin() + i);
        }
    }
    set<int> s;
    rep(i, 1, n){
        if(dsu[i] == i){
            s.insert(i);
        }
    }
    if(s.size() > 1){
        return -1;
    }else{
        return sum;
    }
}

int main(){
    //io;
    freopen("input.txt", "r", stdin);
    int t; cin >> t;
    rep(ii, 1, t){
        cin >> n >> w;
        cout << "Case " << ii << ":\n";
        rep(i, 1, w){
            int u, v, w; cin >> u >> v >> w;
            edge.pb({u, v, w});
            sort(all(edge), compare);
            cout << kruskal() << '\n';
        }
        edge.clear();
    }
    return 0;
}
