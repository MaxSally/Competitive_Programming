//http://www.lightoj.com/volume_showproblem.php?problem=1306
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

const int N = 100000005;
ll x, y, d;

void extendedEuclid(ll a, ll b){
    if(b == 0){
        x = 1;
        y = 0;
        d = a;
        return;
    }
    extendedEuclid(b, a % b);
    x = x - (a/b) * y;
    swap(x, y);
}

ll cntSol(int a, int b, int c, ll x1, ll x2, ll y1, ll y2){
    //debug(a); debug(b); debug(c);
    extendedEuclid(a, b);
    if(!a && !b)
        if(c == 0) return 1LL*(1LL*x2 - x1 + 1) * (1LL*y2 - y1 + 1);
        else return 0;
    if(!a){
        if(c % b != 0) return 0;
        c = -c / b;
        if(y1 <= c && c <= y2) return x2 - x1 + 1;
        return 0;
    }else if(!b){
        if(c % a != 0) return 0;
        c = -c / a;
        if(x1 <= c && c <= x2) return y2 - y1 + 1;
        return 0;
    }

    if(c % d == 0){
        x *= (-c/d);
        y *= (-c/d);
        a /= d; b /= d;
        double p = (x1 - x)/(double)b, q = (x2 - x)/(double)b;
        //debug(p); debug(q);
        if(p > q) swap(p, q);
        x1 = (ll)ceil(p);
        x2 = (ll)floor(q);

        p = (y - y1)/(double)a;
        q = (y - y2)/(double)a;
        if(p > q) swap(p, q);
        y1 = (ll)ceil(p);
        y2 = (ll)floor(q);

        x1 = max(x1, y1);
        x2 = min(x2, y2);
        //debug(x1); debug(x2);
        return max(0LL, x2 - x1 + 1);
    }
    return 0;
}

int main(){
    //io;
    freopen("input.txt", "r", stdin);
    int test;
    cin >> test;
    //scanf("%d", &test);
    rep(ii, 1, test){
        int a, b, c, x1, y1, x2, y2;
        cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
        //printf("%d%d%d%d%d%d%d", &a, &b, &c, &x1, &x2, &y1, &y1);
        //printf("Case %d: %lld\n", ii, cntSol(a, b, c, x1, x2, y1, y2));
        cout << "Case " << ii << ": " << cntSol(a, b, c, x1, x2, y1, y2) << '\n';
    }
    return 0;
}
