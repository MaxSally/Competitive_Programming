//http://bigocoder.com/courses/ORANGE01/ORANGE01_LEC08/ORANGE_L08P02/statement
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

const int N = 9;
int a[N][N], res = 0;
bool hori[N], verti[N], mainD[2 * N], sub[2 * N];

void backtrack(int u, int v, vii &lst){
    hori[u] = verti[v] = mainD[u + v] = sub[7 + u - v] = 1;
    lst.pb(mp(u, v));
    if((int)lst.size() == 8){
        int ans = 0;
        foreach(b, lst){
            ans += a[b.first][b.second];
        }
        res = max(res, ans);
        hori[u] = verti[v] = mainD[u + v] = sub[7 + u - v] = 0;
        lst.pop_back();
        return;
    }
    rep(j, 0, 7){
        if(verti[j] || mainD[u + 1 + j] || sub[7 + u + 1 - j]) continue;
        backtrack(u + 1, j, lst);
    }
    hori[u] = verti[v] = mainD[u + v] = sub[7 + u - v] = 0;
    lst.pop_back();
 }

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int t; cin >> t;
    while(t--){
        res = 0;
        rep(i, 0, 7){
            rep(j, 0, 7){
                cin >> a[i][j];
            }
        }
        vii lst;
        rep(j, 0, 7){
            lst.clear();
            mem(hori, 0);
            mem(verti, 0);
            mem(mainD, 0);
            mem(sub, 0);
            backtrack(0, j, lst);
        }
        int cnt = 0;
        int res1 = res;
        while(res1 > 0){
            cnt++;
            res1 /= 10;
        }
        cnt = 5 - cnt;
        while(cnt--) cout << " ";
        cout << res << endl;
    }
    return 0;
}
