//http://codeforces.com/problemset/problem/560/E
//https://www.youtube.com/watch?v=OJBRB9Rtnzc
/*
* Author : Max Nguyen
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
#define fo(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define rfor(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define rep(i, j) fo(i, 0, j, 1)
#define rrep(i, j) rfor(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define forEach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define in(A, B, C) assert( B <= A && A <= C)
#define mp make_pair
#define pb push_back
#define inf (int)1e9
#define epsi 1e-9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
#define read(type) readInt<type>()
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define left tuyiuoi
#define right fgjhk
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
const int M = 2005;
pll black[M];
ll dp[N*2], fact[N*2];
ll h, w, n, res;

ll inverse(ll a){ //1/a
	ll ans = 1ll;
	ll b = mod - 2;
	while (b) {
		if (b & 1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans;
}

bool compare(pll a, pll b){
    if(a.first <= b.first && a.second <= b.second) return true;
    return false;
}

ll process(){
    rep(i, n){
        res = ((fact[black[i].first + black[i].second - 2]*inverse(fact[black[i].first - 1]) % mod) * inverse(fact[black[i].second - 1]) % mod); // # paths from 0 0 to i
        rep(j, n){
            if(compare(black[j], black[i])){
                ll a = black[i].first - black[j].first;
                ll b = black[i].second - black[j].second;
                ll temp = ((fact[a + b] * inverse(fact[a]) % mod) * inverse(fact[b]) % mod); // # path between j and i
                res = ((res - ((dp[j] * temp) % mod) + mod) % mod); // +mod in case negative; remove all impossible path between j and i
               //cout << "x = " << res << endl;
                //cout << i << " " << j << endl;
            }
        }
        //cout << "res = " << res << endl;
        dp[i] = res;
    }
    return res;
}

int main(){
    io
    freopen("input.txt","r",stdin);
    fact[0] = 1ll;
    fo(i, 1, N*2, 1){
        fact[i] = (fact[i - 1]*i) % mod;
    }
    cin >> h >> w >> n;
    rep(i, n){
        cin  >> black[i].first >> black[i].second;
    }
    black[n].first = h;
    black[n].second = w;
    n++;
    sort(black, black + n);
    mem(dp, 0);
    cout  << process();
    return 0;
}
