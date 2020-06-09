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

ll gcd(int a, int b, ll &x, ll &y){
    if(a == 0){
        x = 0; y = 1;
        return b;
    }
    ll x1, y1; x1 = y1 = 0;
    ll g = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return g;
}

void shiftSolution(ll &x, ll &y, int a, int b, int cnt){
    x += cnt * b;
    y -= cnt * a;
}

bool diophantine(int a, int b, int c, ll &x, ll &y, ll &g){
    g = gcd(abs(a), abs(b), x, y);
    if(g == 0 || c % g > 0){
        return false;
    }
    x *= -c/g;
    y *= -c/g;
    if(a < 0) x = -x;
    if(b < 0) y = -y;
    return true;
}

ll cntSol(int a, int b, int c, int x1, int x2, int y1, int y2){

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
    ll x, y, g; x = y = 0; g = 1;
    if(!diophantine(a, b, c, x, y, g)){
        return 0;
    }
    if(g == 0) return 0;
    a /= g; b /= g;
    int signA = (a > 0? 1: -1);
    int signB = (b > 0? 1: -1);
    //debug(a); debug(b);
    shiftSolution(x, y, a, b, (x1 - x)/b);
    if(x < x1){
        shiftSolution(x, y, a, b, signB); // go over min
    }
    if(x > x2) return 0;
    ll lowerX = x;

    shiftSolution(x, y, a, b, (x2 - x)/b);
    if(x > x2) shiftSolution(x, y, a, b, -signB);
    ll upperX = x;

    shiftSolution(x, y, a, b, (y - y1)/a);
    if(y < y1) shiftSolution(x, y, a, b, -signA);
    if(y > y2) return 0;
    ll lowerY = x;

    shiftSolution(x, y, a, b, (y - y2)/a);
    if(y > y2) shiftSolution(x, y, a, b, signA);
    ll upperY = x;

    if(lowerY > upperY) swap(lowerY, upperY);
    ll l = max(lowerX, lowerY);
    ll r = min(upperX, upperY);
    //debug(l); debug(r);
    if(l > r) return 0;

    return 1ll*(1LL*r - l)/abs(b) + 1;

}

int main(){
    //io;
    freopen("input.txt", "r", stdin);
    int test; cin >> test;
    rep(ii, 1, test){
        int a, b, c, x1, y1, x2, y2; cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
        cout << "Case " << ii << ": " << cntSol(a, b, c, x1, x2, y1, y2) << '\n';
    }
    return 0;
}
