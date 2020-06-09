//https://www.spoj.com/problems/SPP/
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
ll mod;

struct Matrix{
    int n, m;
    vector<vector<ll> > mat;
    Matrix(int n, int m){
        this->n = n;
        this->m = m;
        mat.assign(n, vector<ll>(m, 0LL));
    }
};

void printMatrix(Matrix &a){
    rep(i, 0, a.n - 1){
        rep(j, 0, a.m - 1){
            cout << a.mat[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix multiplyMatrix(Matrix &a, Matrix &b){
    int n = a.n;
    int m = b.m;
    Matrix ans(n, m);
    rep(i, 0, n - 1){
        rep(j, 0, m - 1){
            ll sum = 0LL;
            rep(k, 0, a.m - 1){
                sum += (a.mat[i][k] * b.mat[k][j]) % mod;
                sum = sum % mod;
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
        ans.mat[i][i] = 1LL;
    }
    //Matrix temp = a;
    while(pow > 0LL){
        if(pow % 2LL){
            //temp = multiplyMatrix(temp, a);
            ans = multiplyMatrix(ans, a);
            //temp = a;
        }
        a = multiplyMatrix(a, a);
        //temp = multiplyMatrix(temp, temp);
        pow /= 2LL;
    }
    //printMatrix(ans);
    return ans;
}

ll findNth(ll n, Matrix &a, Matrix &f){
    Matrix ans(f.n, 1);
    ans = power(a, n);
    ans = multiplyMatrix(ans, f);
    //printMatrix(ans);
    return (ans.mat[f.n - 1][0] % mod);
}

ll checkK(ll n, ll k, vector<ll> &cntB, Matrix &a, Matrix &f){
    if(n <= k){
        return cntB[n];
    }
    return findNth(n - k, a, f);
}

int main(){
    io
    freopen("input.txt","r",stdin);
    int test; cin >> test;
    while(test--){
        ll k, n, m; cin >> k;
        vector<ll> b(k + 1), c(k + 1), cntB(k + 1);
        cntB[0] = 0LL;
        rep(i, 1, k){
            cin >> b[i];
        }
        rep(i, 1, k){
            cin >> c[i];
        }
        cin >> m >> n >> mod;
        rep(i, 1, k){
            cntB[i] = (cntB[i - 1] + b[i]) % mod;
        }
        //debuga1(cntB, 1, k);
        Matrix a(k + 1, k + 1);
        rep(i, 0, k - 1){
            a.mat[0][i] = c[i + 1] % mod;
            a.mat[i + 1][i] = 1LL;
            a.mat[k][i] = c[i + 1] % mod;
        }
        a.mat[k][k] = 1LL;
        Matrix f(k + 1, 1);
        rep(i, 0, k - 1){
            f.mat[i][0] = b[k - i] % mod;
        }
        f.mat[k][0] = cntB[k];
        //cout << "This is a" << endl;
        //printMatrix(a);
        //cout << "This is f" << endl;
        //printMatrix(f);
        ll mValue, nValue;
        if(m == 0)
            mValue = 0;
        else
            mValue = checkK(m - 1, k, cntB, a, f);
        nValue = checkK(n, k, cntB, a, f);
        //debug(nValue);
        cout << ((nValue - mValue + mod) % mod) << endl;
    }
    return 0;
}

