//http://acm.hdu.edu.cn/showproblem.php?pid=4135
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

const int N = 0;
vi prime;

ll cntCoPrime(ll a, ll b){
    int k = (int)prime.size();
    ll  mask = (1LL << k);
    ll ans = 0;
    //debug(mask);
    rep(i, 0, mask - 1){
        int turn;
        if(__builtin_popcount(i) % 2){
            turn = -1;
        }else{
            turn = 1;
        }
        int bitValue = 1;
        rep(j, 0, k - 1){
            if((i >> j) & 1){
                bitValue *= prime[j];
            }
        }
        //debug(bitValue);
        ll cntA = (a - 1)/bitValue, cntB = b/bitValue;
        ans += (1LL * turn * (cntB - cntA));
        //debug(ans);
    }
    return ans;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int test; cin >> test;
    rep(ii, 1, test){
        ll a, b, n; cin >> a >> b >> n;
        prime.clear();
        int sqrtN = sqrt(n);
        rep(i, 2, sqrtN){
            if(n % i == 0){
                prime.pb(i);
                while(n % i == 0){
                    n /= i;
                }
            }
        }
        if(n > 1) prime.pb(n);
        cout << "Case #" << ii << ": " << cntCoPrime(a, b) << endl;
    }
    return 0;
}

