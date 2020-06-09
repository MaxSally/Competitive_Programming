//https://codeforces.com/problemset/problem/653/D
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
#define inf (double) (1e9 + 7)
#define epsi 1e-9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
#define read(type) readInt<type>()
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define left tuyiuoi
#define right fgjhkkl
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fo(i, l, r, 1) cout << a[i] << " "; cout << endl
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

const double N = 100005;
int n, m, x;

bool difference(double a, double b){
    return abs(a - b) > 1e-9;
}

/*
    numBear counts how many bear are allowed to go through the same edge. As more bear/flow goes through an edge, the # drops.
    c represents the weight of the edge. Arent used in the actual flow calculation. Instead, it gets converted to numBear depending on the mid value obtained from binarySearch.
*/

struct Edge{
    int v, rev, numBear;
    double c;
    Edge(int v, int rev, double c, int numBear){
        this->v = v; this->rev = rev; this->c = c; this->numBear = numBear;
    }
};

class MaxFlow{
private:
    int n;
    vector<int> delta;
    vector<vector<Edge> > bear;
    vi pNode, pEdge;

    bool findPath(int s, int t){
        queue<int> q;
        q.push(s);
        vector<bool> visited;
        visited.resize(n, false);
        delta.assign(n, inf);
        pNode.assign(n, -1);
        pEdge.assign(n, -2);
        visited[s] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int i = 0; i < bear[u].size(); i++){
                Edge e = bear[u][i];
                if(visited[e.v] || e.numBear == 0) continue;
                visited[e.v] = 1;
                q.push(e.v);
                pNode[e.v] = u;
                pEdge[e.v] = i;
                delta[e.v] = min(delta[u], e.numBear);
            }
        }
        return visited[t];
    }

    double updateFlow(int s, int t){
        double df = delta[t];
        for(int cur = t; cur != s; cur = pNode[cur]){
            int edge = pEdge[cur];
            int node = pNode[cur];
            bear[node][edge].numBear -= df;
            bear[cur][bear[node][edge].rev].numBear += df;
        }
        return df;
    }

public:

    MaxFlow(int n){
        this->n = n;
        bear.assign(n, vector<Edge>());
    }

    void addEdge(int u, int v, int c){
        bear[u].pb(Edge(v, bear[v].size(), 1.0*c, 0));
        bear[v].pb(Edge(u, bear[u].size() - 1, 0.0, 0));
    }

    void printbear(){
        rep(i, 0, n - 1){
            rep(j, 0, bear[i].size() - 1){
                cout << bear[i][j].v << " ";
            }
            cout << endl;
        }
    }

    double findMaxFlow(int s, int t){
        double maximumFlow = 0.0;
        while(findPath(s, t)){
            maximumFlow += updateFlow(s, t);
        }
        return maximumFlow;
    }

    double binarySearch(){
        double mid = 0.0, left = 0.0, right = 1e12; int cnt = 100; //2^100 = 1e30
        while(cnt--){
            mid = (left + right)/2.0;
            rep(i, 0, n - 1){
                rep(j, 0, bear[i].size() - 1){
                    double cap = bear[i][j].c;
                    if(mid <= cap){
                        bear[i][j].numBear = x;
                    }else{
                        bear[i][j].numBear = (int) (1.0*cap*x/mid);
                    }
                }
            }
            double res = findMaxFlow(0, n - 1);
            //cout << "mid " << mid << " " << res << endl;
            if(res >= x)
                left = mid;
            else
                right = mid;
        }
        return mid;
    }
};

int main(){
    io
    freopen("input.txt","r",stdin);
    cin >> n >> m >> x;
    MaxFlow MF(n);
    rep(i, 1, m){
        int u, v, c; cin >> u >> v >> c;
        MF.addEdge(u - 1, v - 1, c);
    }
    cout << (fixed) << setprecision(9) << MF.binarySearch();
    return 0;
}
