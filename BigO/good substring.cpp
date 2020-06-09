//http://bigocoder.com/courses/ORANGE01/ORANGE01_LEC09/ORANGE_L09P03/statement
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

const int N = 1505;
bool state[30];
vector<int> sum;
int k, n;

int findUniqueString(string s){
    int cnt = 0;
    const int p = 37;
    vector<ll> pow(n, 0LL);
    pow[0] = 1LL;
    rep(i, 1, n - 1){
        pow[i] = (pow[i - 1]*p) % mod;
    }
    vector<ll> h(n + 1, 0);
    rep(i, 0, n - 1){
        h[i + 1] = (h[i] + (s[i] - 'a' + 1)*pow[i]) % mod;
    }
    rep(l, 1, n){
        set<ll> hs;
        rep(i, 0, n - l){
            int j = l + i;
            int cntK = sum[j] - sum[i];
            if(cntK > k) continue;
            ll curH = (h[j] + mod - h[i]) % mod;
            curH = (curH * pow[n - i - 1]) % mod;
            if(hs.find(curH) == hs.end()){
                hs.insert(curH);
                //cout << i << " " << j << endl;
            }
            //debug(curH);
            //hs.insert(curH);
            //cout << i << " " << j << endl;
        }
        cnt += (int)hs.size();
        //debug(cnt);
    }
    return cnt;
}


int main(){
    io;
    freopen("input.txt", "r", stdin);
    string s, alpha;
    mem(state, 0);
    getline(cin, s);
    getline(cin, alpha);
    cin >> k;
    n = (int)s.length();
    sum.resize(n + 1, 0);
    rep(i, 1, n){
        sum[i] = sum[i - 1] + ((alpha[s[i - 1] - 'a'] - '0') == 0 ? 1:0);
    }
    //debuga1(sum, 0, n);
    int ans = findUniqueString(s);
    cout << ans << endl;
    return 0;
}
