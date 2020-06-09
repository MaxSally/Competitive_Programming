//https://codeforces.com/problemset/problem/722/E
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
ll fact[N*2], dp[M][21], inverseList[N*2];
ll n, m, k, s, res;

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

void process(){
    rep(i, k){
        ll sum = 0;
        ll total = ((fact[black[i].first + black[i].second - 2]*inverseList[black[i].first - 1] % mod) * inverseList[black[i].second - 1] % mod);
        rep(v, 20){
            res =  total;// # paths from 0 0 to i
            rep(j, v){
                res = (res - dp[i][j] + mod) % mod;
            }
            rep(j, i){
                if(compare(black[j], black[i])){
                    ll a = black[i].first - black[j].first;
                    ll b = black[i].second - black[j].second;
                    ll temp = ((fact[a + b] * inverseList[a] % mod) * inverseList[b] % mod); // # path between j and i
                    res = ((res - ((dp[j][v] * temp) % mod) + mod) % mod); // +mod in case negative; remove all impossible path between j and i
                   //cout << "x = " << res << endl;
                    //cout << i << " " << j << endl;
                }
            }
            //cout << "res = " << res << endl;
            dp[i][v] = res;
            sum = (sum + res) % mod ;
        }
        dp[i][20] = (total - sum + mod) % mod;
    }
}

int main(){
    io
    freopen("input.txt","r",stdin);
    fact[0] = 1ll;
    fo(i, 1, N*2, 1){
        fact[i] = (fact[i - 1]*i) % mod;
    }
    inverseList[N*2 - 1] = inverse(fact[N*2 - 1]);
    rrep(i, N*2 - 2){
        inverseList[i] = inverseList[i + 1]*(i + 1) % mod;
    }
    cin >> n >> m >> k >> s;
    rep(i, k){
        cin  >> black[i].first >> black[i].second;
    }
    black[k].first = n;
    black[k].second = m;
    k++;
    sort(black, black + k);
    process();
    /*rep(i, k){
        rep(j, 3){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    ll ans = 0;
    ll totalP = 0;
    rep(i, 21){
        ans = (ans + (dp[k - 1][i]*s) % mod) % mod;
        totalP = (totalP + dp[k - 1][i]) % mod;
        s = s - s/2;
        //cout << ans << " " << totalP << " " << s << endl;
    }
    cout << (int) ans*inverse(totalP) % mod;
    return 0;
}
