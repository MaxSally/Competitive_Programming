//https://atcoder.jp/contests/abc130/tasks/abc130_f
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

const int N = 0;

struct point{
    double inc, dec, cons;
};

point b[4];

int convert(char d){
    if(d == 'R') return 0;
    if(d == 'L') return 1;
    if(d == 'U') return 2;
    return 3;
}

double calculate(double a){
    double xMax = max(b[1].cons, max(b[1].inc + a, b[1].dec - a));
    double xMin = min(b[0].cons, min(b[0].inc + a, b[0].dec - a));
    double yMax = max(b[3].cons, max(b[3].inc + a, b[3].dec - a));
    double yMin = min(b[2].cons, min(b[2].inc + a, b[2].dec - a));
    return (xMax - xMin) * (yMax - yMin);
}

double ternarySearch(double left, double right){
    double res = -1;
    rep(ii, 1, 1000){
        double m1 = (left * 2.0 + right)/3.0, m2 = (left + right * 2.0)/3.0;
        double valueM1 = calculate(m1), valueM2 = calculate(m2);
        if(valueM1 - valueM2 > epsi){
            left = m1;
            res = m2;
        }
        if(valueM2 - valueM1 > epsi){
            right = m2;
            res = m1;
        }
    }
    return res;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    rep(i, 0, 3){
        if(i & 1){
            b[i].inc = b[i].dec = b[i].cons = -1.0 * inf;
        }else{
            b[i].inc = b[i].dec = b[i].cons = 1.0 * inf;
        }
    }
    rep(i, 1, n){
        double x, y;
        char c; cin >> x >> y >> c;
        int d = convert(c);
        if(d < 2){
            b[2].cons = min(b[2].cons, y);
            b[3].cons = max(b[3].cons, y);
            if(d == 0){
                b[1].inc = max(b[1].inc, x);
                b[0].inc = min(b[0].inc, x);
            }else{
                b[1].dec = max(b[1].dec, x);
                b[0].dec = min(b[0].dec, x);
            }
        }else{
            b[0].cons = min(b[0].cons, x);
            b[1].cons = max(b[1].cons, x);
            if(d == 2){
                b[3].inc = max(b[3].inc, y);
                b[2].inc = min(b[2].inc, y);
            }else{
                b[3].dec = max(b[3].dec, y);
                b[2].dec = min(b[2].dec, y);
            }
        }
    }
    double ans = ternarySearch(0, 500000000);
    cout << fixed << setprecision(11) << calculate(ans);
    return 0;
}
