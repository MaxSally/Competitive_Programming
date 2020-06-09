//https://open.kattis.com/problems/brexitnegotiations
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

const int N = 400005;
vi g[N], ans;
int n, d, x, level[N], cost[N];

bool topological_sort_kahn(){
    priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int, int> > > pq;
    rep(i, 1, n){
        if(level[i] == 0) pq.push({cost[i], i});
    }
    //debuga1(level, 1, n);
    while(pq.size()){
        int u = pq.top().second; pq.pop();
        ans.pb(u);
        for(int a : g[u]){
            //debug(a);
            level[a]--;
            if(level[a] == 0) pq.push({cost[a], a});
        }
    }
    //debuga1(level, 1, n);
    rep(i, 1, n){
        if(level[i]) return false;
    }
    return true;
}


int main(){
    io
    freopen("input.txt","r",stdin);
    cin >> n;
    mem(level, 0);
    mem(cost, 0);
    rep(i, 1, n){
        cin >> cost[i] >> d;
        rep(j, 1, d){
            cin >> x;
            g[i].pb(x);
            level[x]++;
        }
    }
    if(topological_sort_kahn()){
        int maxTime = 0;
        reverse(ans.begin(), ans.end());
        //debuga1(ans, 0, ans.size() - 1);
        /*rep(i, 0, ans.size() - 1){
            cout << cost[ans[i]] << " ";
        }*/
        //cout << endl;
        rep(i, 0, ans.size() - 1){
            //debug(i + cost[ans[i]]);
            maxTime = max(maxTime, i + cost[ans[i]]);
        }
        cout << maxTime;
    }
    return 0;
}

