//https://codeforces.com/contest/449/problem/D

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
#define MOD 1000000007
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

const int N = 20;
const int M = 1000005;
int n, ans = 0;
int F[M], a[M];

void calculateF(){
    rep(i, N){
        rrep(mask, M){
            if(mask & (1 << i)){
                (F[1 << i ^ mask] += F[mask]) %= MOD;
            }
        }
    }
    rrep(i,M){
        (ans += 1ll*(__builtin_popcount(i) % 2? -1:1)*(a[F[i]]-1)) %= MOD;
    }
}



int main(){
    io
    //freopen("input.txt","r",stdin);
    cin >> n;
    mem(F, 0);
    mem(a, 0);
    rep(i, n){
        int x;
        cin >> x;
        F[x]++;
    }
    a[0] = 1;
    rep(i, n + 1){
        if(i == 0) continue;
        a[i] = (a[i - 1] << 1) % MOD;
    }
    calculateF();
    cout << ((ans + MOD) % MOD);
    return 0;
}
