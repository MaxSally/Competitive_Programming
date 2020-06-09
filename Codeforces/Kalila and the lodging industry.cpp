//https://codeforces.com/problemset/problem/319/C
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

const int N = 100005;

int n, a[N], b[N];
ll dp[N];

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
        while((int)q.size() > 1 && get(q[0], x) >= get(q[1], x)){
            q.pop_front();
        }
        return get(q[0], x);
    }

};

int main(){
    io
    freopen("input.txt","r",stdin);
    cin >> n;
    rep(i, 1, n){
        cin >> a[i];
    }
    rep(i, 1, n){
        cin >> b[i];
    }
    dp[1] = 0;
    convex_hull hull;
    hull.add({b[1], dp[1]});
    rep(i, 2, n){
        dp[i] = hull.query(a[i]);
        hull.add({b[i], dp[i]});
    }
    cout << dp[n];
    return 0;
}

