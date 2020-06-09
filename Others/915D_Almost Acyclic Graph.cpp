//https://codeforces.com/problemset/problem/915/D
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

const int N = 100005;
int n, parent[N], m;
int visited[N];
vi graph[N];

pii dfs(int s, int u, int t){
    foreach(v, graph[s]){
        if(u == s && v == t) continue;
        if(visited[v] == 2){
            continue;
        }
        if(visited[v] == 1){
            return mp(s, v);
        }
        parent[v] = s;
        visited[v] = 1;
        pii ans = dfs(v, u, t);
        if(ans != mp(-1, -1)){
            return ans;
        }
    }
    visited[s] = 2;
    return mp(-1, -1);
}

pii checkCycle(int u, int v){
    pii ans = mp(-1, -1);
    rep(i, 1, n){
        if(visited[i] == 0){
            ans = dfs(i, u, v);
            if(ans != mp(-1, -1)){
                break;
            }
        }
    }
    return ans;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    rep(i, 1, m){
        int x, y; cin >> x >> y;
        graph[x].pb(y);
    }
    rep(i, 1, n){
        parent[i] = -1;
    }
    mem(visited, 0);
    pii check = checkCycle(-1, -1);

    if(check == mp(-1, -1)){
        cout << "YES\n";
        return 0;
    }
    stack<pii> st;
    int ind = check.ff;
    st.push(mp(check.ff, check.ss));

    do{
        st.push(mp(parent[ind], ind));
        ind = parent[ind];
    }while(ind != check.ss);

    while(!st.empty()){
        mem(visited, 0);
        int u = st.top().ff, v= st.top().ss;
        st.pop();
        pii ans = checkCycle(u, v);
        if(ans == mp(-1, -1)){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
