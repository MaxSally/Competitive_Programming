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

vi graph[N];
int n, degree[N];

vi path;

void euclidPath(int start){
    while((int)graph[start].size()){
        int u = graph[start].back();
        graph[start].pop_back();
        euclidPath(u);
    }
    path.pb(start);
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n;
    rep(i, 1, n){
        string s; cin >> s;
        int source = s[0] * (1 << 8) + s[1];
        int endNode = s[1] * (1 << 8) + s[2];
        degree[source]++;
        degree[endNode]--;
        graph[source].pb(endNode);
    }
    int startP = 0, cnt = 0;
    rep(i, 0, N - 1){
        if(degree[i] >= 1){
            startP = i;
            cnt++;
        }
    }
    if(cnt > 1 || degree[startP] > 1){
        cout << "NO\n";
        return 0;
    }
    if(startP == 0){
        rep(i, 0, N - 1){
            if(graph[i].size() > 0){
                startP = i;
                break;
            }
        }
    }
    euclidPath(startP);
    reverse(all(path));
    if((int)path.size() != n + 1){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << (char)(startP / 256);
    foreach(node, path){
        cout << (char)(node % 256);
    }

    return 0;
}
