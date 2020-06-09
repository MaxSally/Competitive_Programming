//https://hochiminh17.kattis.com/problems/barcode
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

const int N = 1000005;
int fibo[N], sieve[N], prime[N];
vi lst;

void era(){
    rep(i, 0, N - 1){
        sieve[i] = i;
    }
    rep(i, 2, N - 1){
        if(sieve[i] == i){
            lst.pb(i);
            for(ll j = 1LL * i * i; j < N; j += i){
                sieve[j] = min(sieve[j], i);
            }
        }
    }
}

ll power(ll base, int cap, int m){
    ll res = 1;
    while(cap){
        if(cap & 1){
            res = (res * base) % m;
        }
        base = (base * base) % m;
        cap >>= 1;
    }
    return res;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    era();
    int t; cin >> t;
    fibo[0] = 1;
    while(t--){
        int n, m; cin >> n >> m;
        fibo[1] = 2 % m;
        rep(i, 2, n){
            fibo[i] = (fibo[i - 1] + fibo[i - 2]) % m;
        }
        if(n & 1){
            cout << fibo[n] << endl;
            continue;
        }
        rep(i, 2, n){
            int temp = i;
            while(temp > 1){
                if(i <= n/2){
                    prime[sieve[temp]]--;
                }else{
                    prime[sieve[temp]]++;
                }
                temp /= sieve[temp];
            }
        }
        ll ans = 1;
        foreach(p, lst){
            ans = (ans * power(p, prime[p], m)) % m;
            prime[p] = 0;
        }
        ans = (ans + fibo[n]) % m;
        ans = (ans + 1LL * m * n - n/2 - 1) % m;
        cout << ans << endl;
    }
    return 0;
}
