//https://codeforces.com/gym/100212/attachments/download/1727/20042005-winter-petrozavodsk-camp-andrew-stankevich-contest-10-en.pdf

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
#define inf (long long) (1e18)
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

const int N = 2005;
int n, A[N][N];
ll dp[N][N], num[N], sum[N];
string ansS[N];

void process(){
    fo(len, 1, n + 1, 1){
        fo(l, 1, n - len + 2, 1){
            int r = l + len - 1;
            if(len < 2){
                dp[l][r] = 0;
                A[l][r] = r;
            }else{
                ll res, ans;
                res = ans = inf;
                fo(k, A[l][r - 1], min(A[l + 1][r], r - 1) + 1, 1){
                    ll temp = dp[l][k] + dp[k + 1][r] + (sum[r] - sum[l - 1]);
                    if(ans > temp){
                        ans = temp;
                        res = k;
                    }
                }
                dp[l][r] = ans;
                A[l][r] = res;
                /*debug(l); debug(r); debug(res);
                rep(i, n){
                    rep(j, n){
                        cout << dp[i][j] << " ";
                    }
                    cout << endl;
                }*/
            }
        }
    }
}

void printString(int l, int r){
    if(r - l < 1){
        return;
    }
    int k = A[l][r];
    //debug(l); debug(r);
    //debug(k);
    fo(i, l, k + 1, 1){
        ansS[i] = ansS[i] + "0";
    }
    fo(i, k + 1, r + 1, 1){
        ansS[i] = ansS[i] + "1";
    }
    printString(l, k);
    printString(k + 1, r);
}

int main(){
    io
    freopen("codes.in","r",stdin);
    freopen("codes.out","w",stdout);
    cin >> n;
    fo(i, 1, n + 1, 1){
        cin >> num[i];
    }
    sum[0] = 0;
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + num[i];
    }
    //debuga1(sum, 0, n);
    process();
    printString(1, n);
    fo(i, 1, n + 1, 1){
        cout << ansS[i] << endl;
    }
    return 0;
}


