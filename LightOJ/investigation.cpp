//http://lightoj.com/volume_showproblem.php?problem=1068

/*
* Author : Max Nguyen
*/
/********   All Required Header Files ********/
#include<bits/stdc++.h>
using namespace std;
/*******  All Required define Pre-Processors and typedef Constants *******/
#define scd(t) scanf("%d",&t)
#define scld(t) scanf("%ld",&t)
#define sclld(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
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

const int N = (1 << 31);
int a, b, k;
int dp[11][2][85][85]; //dp[i][lo][sum of digits % k][number % k]; lo = so tao ra da nho hon han

int process(int x){
    rep(i, 11){
        rep(j, 2){
            rep(k, 85){
                mem(dp[i][j][k], 0);
            }
        }
    }
    stringstream ss;
    ss << x;
    string s = ss.str();
    int length = (int) s.length();
    rep(i, s[0] - '0' + 1){
        dp[0][i < (s[0] - '0')][i % k][i % k] += 1;
    }
    rep(i, length - 1){
        rep(lo, 2){
            rep(sum, k){
                rep(number, k){
                    int lim = (lo? 9: (s[i + 1] - '0'));
                    rep(li, lim + 1){
                        dp[i + 1][lo|(li < (s[i + 1] - '0'))][((sum + li) % k)][((number*10 + li) % k)] += dp[i][lo][sum][number];
                    }
                }
            }
        }
    }
    return dp[length - 1][0][0][0] + dp[length - 1][1][0][0];
}

int main(){
    io
    //freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    rep(ii, t){
        cin >> a >> b >> k;
        cout << "Case " << ii + 1 << ": ";
        if(k > 82){
            cout << "0" << endl;
        }else{
            int res = process(b);
            res -= process(a - 1);
            cout << res << endl;
        }
    }
    return 0;
}
