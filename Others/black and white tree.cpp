//https://csacademy.com/contest/round-55/task/black-white-tree/
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

const int N = 50005;
int n, h[N], sparseT[18][N], in[N], out[N], distW[N], distB[N];
pii black[N], white[N];
vi graph[N], lis;
set<int> toUpdate;
bool color[N], iniColor[N]; // 0 = white, 1 black

void findBW(int s, int pre){
    int cntB = 0, cntW = 0, distB = 0, distW = 0;
    if(color[s]) cntB++;
    else cntW++;
    in[s] = out[s] = (int)lis.size();
    lis.pb(h[s]);
    for(int u: graph[s]){
        if(u == pre)continue;
        h[u] = h[s] + 1;
        findBW(u, s);
        out[s] = (int)lis.size();
        lis.pb(h[s]);
        cntB += black[u].first;
        cntW += white[u].first;
        distB += black[u].first + black[u].second;
        distW += white[u].first + white[u].second;
        //jumpingLCA[0][u] = s;
    }
    black[s].first = cntB;
    white[s].first = cntW;
    black[s].second = distB;
    white[s].second = distW;
    out[s] = (int)lis.size() - 1;
}

void update(int s, int pre){
    iniColor[s] = color[s];
    int cntB = 0, cntW = 0, distB = 0, distW = 0;
    if(color[s]) cntB++;
    else cntW++;
    for(int u: graph[s]){
        if(u == pre)continue;
        update(u, s);
        cntB += black[u].first;
        cntW += white[u].first;
        distB += black[u].first + black[u].second;
        distW += white[u].first + white[u].second;
    }
    black[s].first += cntB;
    white[s].first += cntW;
    black[s].second += distB;
    white[s].second += distW;
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

int findDist(int l, int r){
    int lca = findL CA(min(in[l], in[r]), max(out[r], out[l]));
    //debug(lca);
    //debuga1(sparseT[1], 0, n);
    return h[l] + h[r] - 2 * lca;
}

void printWhite(){
    rep(i, 1, n){
        cout << white[i].first << " " << white[i].second << endl;
    }
    cout << endl;
}

void printBlack(){
    rep(i, 1, n){
        cout << black[i].first << " " << black[i].second << endl;
    }
    cout << endl;
}

void createDist(int s, int pre){
    for(int v: graph[s]){
        if(v == pre) continue;
        distB[v] = distB[s] + black[1].first - black[v].first * 2;
        distW[v] = distW[s] + white[1].first - white[v].first * 2;
        createDist(v, s);
    }
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int m;
    cin >> n >> m;
    mem(h, 0); mem(black, 0); mem(white, 0);
    rep(i, 1, n){
        cin >> color[i];
        iniColor[i] = color[i];
    }
    //debuga1(color, 1, n);
    rep(i, 1, n - 1){
        int x, y; cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    //Flag(0);
    h[1] = 0;
    findBW(1, -1);
    createSparseTable();
    //printWhite();
    //printBlack();
    distB[1] = black[1].second;
    distW[1] = white[1].second;
    createDist(1, -1);
    //debuga1(distB, 1, n);
    //debuga1(distW, 1, n);
    //debuga1(lis, 0, (int)lis.size() - 1);
    //debuga1(in, 1, n);
    //debuga1(out, 1, n);
    while(m--){
        int type, v; cin >> type >> v;
        //debug(type); debug(v);
        if(type == 1){
            color[v] = !color[v];
            toUpdate.insert(v);
            if((int)toUpdate.size() >= sqrt(N)){
                //mem(black, 0);
                //mem(white, 0);
                update(1, -1);
                toUpdate.clear();
                distB[1] = black[1].second;
                distW[1] = white[1].second;
                createDist(1, -1);
            }
        }else{
            //debug(res);
            int res = (color[v]? distB[v]: distW[v]);
            for(int node: toUpdate){
                //debug(node);
                if(color[v] != iniColor[node] && color[v] == color[node]){
                    res += findDist(node, v);
                }else if(color[v] != color[node] && color[v] == iniColor[node]){
                    res -= findDist(node, v);
                }
                //debug(res);
            }
            cout << res << endl;
        }
        //debuga1(toUpdate, 0, (int)toUpdate.size() - 1);
    }
    return 0;
}
