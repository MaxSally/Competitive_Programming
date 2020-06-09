//https://atcoder.jp/contests/dp/tasks/dp_r
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

const int N = 55;
int graph[N][N];

struct Matrix{
    int n, m;
    vector<vector<ll> > mat;
    Matrix(int n, int m){
        this->n = n; this->m = m;
        mat.assign(n, vector<ll>(m, 0LL));
    }
};

Matrix multiplyMatrix(Matrix &a, Matrix &b){
    int n = a.n, m = b.m, k = a.m;
    Matrix ans(n, m);
    rep(i, 0, n - 1){
        rep(j, 0, m - 1){
            rep(kk, 0, k - 1){
                ans.mat[i][j] = (ans.mat[i][j] + ((1LL*a.mat[i][kk] * b.mat[kk][j]) % mod)) % mod;
            }
        }
    }
    return ans;
}

Matrix power(Matrix a, ll pow){
    Matrix ans(a.n, a.n);
    rep(i, 0, a.n - 1){
        ans.mat[i][i] = 1LL;
    }
    while(pow > 0){
        //debug(pow);
        if(pow % 2){
            ans = multiplyMatrix(ans, a);
        }
        a = multiplyMatrix(a, a);
        //Flag(0);
        pow /= 2LL;
    }
    return ans;
}



int main(){
    io
    freopen("input.txt","r",stdin);
    int n;
    ll k;
    cin >> n >> k;
    rep(i, 0, n - 1){
        rep(j, 0, n - 1){
            cin >> graph[i][j];
        }
    }
    Matrix primary(n, n);
    rep(j, 0, n - 1){
        rep(i, 0, n - 1){
            primary.mat[j][i] = 1LL*graph[i][j];
        }
    }
    Matrix f(n, 1);
    rep(i, 0, n - 1){
        f.mat[i][0] = 1LL;
    }
    Matrix temp = power(primary, k);
    //Flag(1);
    Matrix ans = multiplyMatrix(temp, f);
    ll totalPath = 0LL;
    rep(i, 0, n - 1){
        totalPath += ans.mat[i][0];
        totalPath %= mod;
    }
    cout << totalPath;
    return 0;
}

