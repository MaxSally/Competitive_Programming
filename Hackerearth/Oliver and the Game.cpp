//http://bigocoder.com/courses/ORANGE01/ORANGE01_LEC08/ORANGE_L08P03/statement
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
int in[N], out[N], sparseT[20][2 * N], h[N];
vi graph[N], lis;

void initiateTree(int u, int pre){
    in[u] = out[u] = (int)lis.size();
    lis.pb(h[u]);
    rep(i, 0, (int)graph[u].size() - 1){
        int v = graph[u][i];
        if(v != pre){
            h[v] = h[u] + 1;
            initiateTree(v, u);
            out[u] = (int)lis.size();
            lis.pb(h[u]);
        }
    }
}

void createSparseTable(){
    int m = (int)lis.size();
    rep(i, 0, m - 1){
        sparseT[0][i] = lis[i];
    }
    int row = (int)log2(m);
    rep(i, 1, row){
        rep(j, 0, m - (1 << i)){
            sparseT[i][j] = min(sparseT[i - 1][j], sparseT[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int findLCA(int a, int b){
    int k = log2(b - a + 1);
    return min(sparseT[k][a], sparseT[k][b - (1 << k) + 1]);
}


int main(){
    io;
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    rep(i, 1, n - 1){
        int x, y; cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    h[1] = 0;
    initiateTree(1, -1);
    createSparseTable();
    int q; cin >> q;
    while(q--){
        int t, x, y; cin >> t >> x >> y;
        int lca = findLCA(min(in[x], in[y]), max(out[x], out[y]));
        //debug(x); debug(y); debug(lca);
        if(t == 0){
            if(lca == h[x]){
                cout << "YES";
            }else{
                cout << "NO";
            }
        }else{
            if(lca == h[y]){
                cout << "YES";
            }else{
                cout << "NO";
            }
        }
        cout << endl;
    }
    return 0;
}
