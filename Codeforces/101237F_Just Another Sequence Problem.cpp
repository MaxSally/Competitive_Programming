//https://codeforces.com/gym/101237/problem/F
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
#define inf (long long) (1e18 + 7)
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

const int N = 2005;
ll dp[N][N], sum[N];
int n;

struct line{
    ll a, b;
};

ll get(const line &l, int x){
    return l.a * x + l.b;
}

double intersection(const line &line1, const line &line2){
    return 1.0 * (line2.b - line1.b)/(line1.a - line2.a);
}

bool conflict(const line &line1, const line &line2, const line &line3){
    if(line3.a == line2.a){
        return 1;
    }
    return intersection(line3, line2) <= intersection(line3, line1);
}

struct convexHull{
    deque<line> dq;

    void add(const line &line1){
        int k;
        while(((k = (int)dq.size()) > 1 && conflict(dq[k - 2], dq[k - 1], line1)) || ((k == 1) && dq[0].a == line1.a)){
            dq.pop_back();
        }
        dq.pb(line1);
    }

    ll query(const int &x){
        int l = -1, r = (int)dq.size() - 1;
        while(r - l > 1){
            int m = (l + r)/2;
            if(get(dq[m], x) <= get(dq[m + 1], x)){
                l = m;
            }else{
                r = m;
            }
        }
        if(r == -1) return 0;
        return get(dq[r], x);
    }
};

bool compare(const line &l1, const line &l2){
    if(l1.a == l2.a){
        return l1.b <= l2.b;
    }
    return l1.a < l2.a;
}

ll createDP(){
    ll maxN = -inf;
    rep(i, 1, n){
        convexHull hull;
        vector<line> point;
        rep(k, 0, i - 1){
            line newLine;
            newLine.a = sum[k];
            newLine.b = dp[k][i];
            point.pb(newLine);
        }
        sort(all(point), compare);
        foreach(l, point){
            hull.add(l);
        }
        rep(j, i, n){
            dp[i][j] = (sum[j] - sum[i]) * sum[i] + hull.query(sum[i] - sum[j]);
        }
        maxN = max(maxN, dp[i][n]);
    }
    return maxN;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n;
    rep(i, 1, n){
        int x; cin >> x;
        sum[i] = sum[i - 1] + x;
    }
    cout << createDP();
    return 0;
}
