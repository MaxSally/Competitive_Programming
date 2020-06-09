//https://codeforces.com/problemset/problem/343/C
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
#define inf (long long) (1e11 + 7)
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

int n, m;
vector<ll> h, p;

int lastCheckPos(ll u, ll leftOver, int possibleCheck){
    while(possibleCheck < m && p[possibleCheck] - u <= leftOver){
        possibleCheck++;
    }
    return possibleCheck;
}

bool check(ll x){
    int lastCheck = 0;
    foreach(u, h){
        ll v = p[lastCheck];
        if(u < v){
            lastCheck = lastCheckPos(u, x, lastCheck);
            if(lastCheck == m) break;
            continue;
        }
        if((u - v) > x){
            return 0;
        }
        while(lastCheck < m && p[lastCheck] <= u){
            lastCheck++;
        }
        if(lastCheck == m) break;
        ll leftOver = x - (u - v) * 2;

        int check1 = lastCheckPos(u, leftOver, lastCheck);
        leftOver = (x - (u - v))/2;
        int check2 = lastCheckPos(u, leftOver, lastCheck);


        lastCheck = max(check1, check2);
        if(lastCheck == m) break;

    }
    return (lastCheck == m);
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    rep(i, 1, n){
        ll x; cin >> x;
        h.pb(x);
    }
    rep(i, 1, m){
        ll x; cin >> x;
        p.pb(x);
    }
    sort(all(h));
    sort(all(p));
    ll left = 0, right = inf, ans = inf;
    while(left <= right){
        ll mid = (left + right)/2LL;
        if(check(mid)){
            right = mid - 1;
            ans = mid;
        }else{
            left = mid + 1;
        }
    }
    cout << ans;
    return 0;
}
