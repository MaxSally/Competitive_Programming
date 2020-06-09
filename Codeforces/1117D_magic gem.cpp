//https://codeforces.com/problemset/problem/1117/D
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

struct Matrix{
    int n, m;
    vector<vector<ll> > mat;

    Matrix(int n, int m){
        this->n = n; this->m = m;
        mat.assign(n, vector<ll> (m, 0LL));
    }
};

Matrix multiplyMatrix(Matrix &a, Matrix &b){
    int n = a.n, m = b.m, k = a.n;
    Matrix ans(n, m);
    rep(i, 0, n - 1){
        rep(j, 0, m - 1){
            ll sum = 0LL;
            rep(kk, 0, k - 1){
                sum = (sum + (a.mat[i][kk] * b.mat[kk][j]) % mod) % mod;
            }
            ans.mat[i][j] = sum;
        }
    }
    return ans;
}

Matrix power(Matrix a, ll pow){
    int n = a.n, m = a.m;
    Matrix ans(n, m);
    rep(i, 0, n - 1){
        ans.mat[i][i] = 1;
    }
    while(pow > 0){
        if(pow % 2){
            ans = multiplyMatrix(ans, a);
        }
        a = multiplyMatrix(a, a);
        pow = pow/2LL;
    }
    return ans;
}

void printMatrix(Matrix &a){
    rep(i, 0, a.n - 1){
        rep(j, 0, a.m - 1){
            cout << a.mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    io
    freopen("input.txt","r",stdin);
    ll n, m;
    cin >> n >> m;
    Matrix primary(m, m);
    primary.mat[0][0] = primary.mat[0][m - 1] = 1LL;
    rep(i, 1, m - 1){
        primary.mat[i][i - 1] = 1LL;
    }
    Matrix f(m, 1);
    f.mat[0][0] = 2;
    rep(i, 1, m - 1){
        f.mat[i][0] = 1;
    }
    //printMatrix(f);
    if(n <= m){
        cout << f.mat[m - n][0];
    }else{
        Matrix temp = power(primary, n - m);
        //printMatrix(temp);
        Matrix ans = multiplyMatrix(temp, f);
        cout << ans.mat[0][0];
    }
    return 0;
}

