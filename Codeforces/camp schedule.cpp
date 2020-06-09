//https://codeforces.com/problemset/problem/1137/B
//http://bigocoder.com/courses/ORANGE01/ORANGE01_LEC09/ORANGE_L09P05/statement
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

const int N = 500005;

int findPreSuf(string s){
    unordered_set<int> unSet;
    int cnt = 0;
    int n = (int)s.length();
    const int p = 31;
    vector<long long> pow(n);
    pow[0] = 1;
    rep(i, 1, n - 1){
        pow[i] = (pow[i - 1] * p) % mod;
    }
    vector<ll> h(n + 1, 0);
    rep(i, 0, n - 1){
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * pow[i]) % mod;
        unSet.insert(h[i + 1]);
    }
    rrep(i, n - 1, 1){
        ll curSuf = (h[n] + mod - h[n - i]) % mod;
        curSuf = (curSuf * pow[i - 1]) % mod;

        ll curPre = (h[i] + mod - h[0]) % mod;
        curPre = (curPre * pow[n - 1]) % mod;

        if(curSuf == curPre){
            return i;
        }
    }
    return -1;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    string s, t;
    cin >> s >> t;
    int n = (int)s.length();
    int m = (int) t.length();
    if(n < m){
        cout << s;
        return 0;
    }
    int cntS1 = 0, cntT1 = 0, cntH1 = 0;
    rep(i, 0, n - 1){
        if(s[i] == '1') cntS1++;
    }
    rep(i, 0, m - 1){
        if(t[i] == '1') cntT1++;
    }
    int l = findPreSuf(t);
    string simiS = "";
    if(l != -1){
        rep(i, 0, m - 1 - l){
            simiS += t[i];
            if(t[i] == '1') cntH1++;
        }
    }
    int cntS0 = n - cntS1, cntT0 = m - cntT1, cntH0 = m - l - cntH1;
    if(l == -1){
        cntH0 = cntT0;
        cntH1 = cntT1;
        simiS = t;
    }
    if(cntT1 == 0){
        int time = cntS0/m;
        int cnt = 0;
        while(time--){
            cout << t;
            cnt += m;
        }
        int left0 = cntS0 % m;
        while(left0--){
            cout << "0";
            cnt++;
        }
        while(cnt < n){
            cout << "1";
            cnt++;
        }
        return 0;
    }
    int time = inf;
    if(cntH1 != 0){
        time = min(time, cntS1/cntH1);
    }
    if(cntH0 != 0){
        time = min(time, cntS0/cntH0);
    }
    //debug(time);
    while(time > 0){
        cout << simiS;
        cntS1 -= cntH1;
        cntS0 -= cntH0;
        time--;
    }
    rep(i, m - l, m - 1){
        if(cntS1 == 0 || cntS0 == 0) break;
        cout << t[i];
        if(t[i] == '1') cntS1--;
        else cntS0--;
    }
    while(cntS1 > 0){
        cout << "1";
        cntS1--;
    }
    while(cntS0 > 0){
        cout << "0";
        cntS0--;
    }

    return 0;
}

