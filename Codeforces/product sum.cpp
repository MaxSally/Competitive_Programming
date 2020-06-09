//https://codeforces.com/problemset/problem/631/E

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

struct line{
    ll a, b;
};

ll get(const line &l, ll x){
    return l.a * x + l.b;
}

ll intersection(const line &lin1, const line & lin2){ //find intersection x-coordinate
    return 1.0*(lin2.b - lin1.b)/(lin1.a - lin2.a);
}

bool conflict(const line &lin1, const line &lin2, const line &lin3){
    return intersection(lin3, lin2) <= intersection(lin3, lin1);
}

const int N = 200005;

int n, a[N];
ll dp[N], sum[N], ans, dif;

struct convex_hull{
    deque<line> q;

    void add(const line &l){//add line to deque
        int k;
        while((k = (int)q.size()) > 1 && conflict(q[k - 2], q[k - 1], l)){
            q.pop_back();
        }
        q.push_back(l);
    }

    ll query(const int &x){
        int l = -1; int r = (int)q.size() - 1;
        while(r - l > 1){
            int m = (l + r)/2;
            if(get(q[m], x) <= get(q[m + 1], x)){
                l = m;
            }else{
                r = m;
            }
        }
        return get(q[r], x);
    }
};

int main(){
    io
    freopen("input.txt","r",stdin);
    dif = ans = sum[0] = 0;
    cin >> n;
    rep(i, 1, n){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        ans += (ll) a[i]*i;
    }
    convex_hull hull, hull2;
    rrep(i, n - 1, 1){
        hull.add({-i - 1, - sum[i + 1]});
        dif = max(dif, hull.query(-a[i]) + sum[i] - (ll)a[i]*i);
    }
    rep(i, 2, n){
        hull2.add({i - 1, - sum[i - 2]});
        dif = max(dif, hull2.query(a[i]) + sum[i - 1] - (ll)a[i]*i);
    }
    cout << ans + dif;
    return 0;
}

