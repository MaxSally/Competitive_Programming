//https://codeforces.com/contest/1167/problem/C
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

const int N = 500005;
int member[N], n, m;
pii group[N];

int findGroup(int u){
    return (u == group[u].ff? u: group[u].ff = findGroup(group[u].ff));
}

void unionGroup(int u, int v){
    int a = findGroup(u);
    int b = findGroup(v);
    if(a != b){
        group[b].ss += group[a].ss;
        group[a].ff = b;
    }
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    fill(member, member + n + 1, -1);
    rep(i, 1, m){
        group[i].ff = i;
        group[i].ss = 0;
    }
    rep(i, 1, m){
        int k; cin >> k;
        //group[i].ss = k;
        rep(j, 1, k){
            int x; cin >> x;
            if(member[x] != -1)
                unionGroup(member[x], i);
            else{
                int u = findGroup(i);
                //debug(i); debug(u); debug(x);
                group[u].ss++;
            }
            member[x] = i;
        }
    }
    rep(i, 1, n){
        if(member[i] == -1){
            cout << "1 ";
            continue;
        }
        int u = findGroup(member[i]);
        cout << group[u].ss << " ";
    }
    return 0;
}
