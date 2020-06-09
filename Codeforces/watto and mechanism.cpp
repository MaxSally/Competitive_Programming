//https://codeforces.com/problemset/problem/514/C
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
#define mod1 1000000009
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

const int N = 300005;
const int p = 43;
set<pair<ll, ll> > unSet;
int n;
vector<string> ask, query;
vector<long long> power, power1;

void prepareData(){
    power.resize(n + 1, 0);
    power1.resize(n + 1, 0);
    power[0] = power1[0] = 1;
    rep(i, 0, n - 1){
        power[i + 1] = (power[i] * p) % mod;
    }
    rep(i, 0, n - 1){
        power1[i + 1] = (power1[i] * p) % mod1;
    }
    //debuga1(power, 0, n);
}

void insertString(string s){
    vector<ll> h(n + 1, 0), h1(n + 1, 0);
    int l = s.length();
    //Flag(1);
    rep(i, 0, l - 1){
        int c = s[i] - 'a' + 1;
        h[i + 1] = (((h[i] * p) % mod) + c) % mod;
        h1[i + 1] = (((h1[i] * p) % mod1) + c) % mod1;
        //debug(h[i + 1]);
    }
    //Flag(1);
    //debuga1(h, 0, l);
    rep(i, 0, l - 1){

        int c = s[i] - 'a' + 1;
        ll curH = (h[l] - ((power[l - 1 - i] * c) % mod) + mod) % mod;
        ll curH1 = (h1[l] - ((power1[l - 1 - i] * c) % mod1) + mod1) % mod1;
        //debug(h[l] + ((power[l - 1 - i] * c) % mod) + mod);
        //debug(curH);
        rep(j, 1, 3){
            if(j == c) continue;
            //cout << s << " " << i << " " << j << endl;
            ll temp = (curH + ((power[l - 1 - i] * j) % mod)) % mod;
            ll temp1 = (curH1 + ((power1[l - 1 - i] * j) % mod1)) % mod1;
            if(unSet.find(mp(temp, temp1)) == unSet.end()){
                unSet.insert(mp(temp, temp1));

            }
        }
    }
}

bool queryString(string s){
    vector<ll> h(n + 1, 0), h1(n + 1, 0);
    int l = s.length();
    rep(i, 0, l - 1){
        int c = s[i] - 'a' + 1;
        h[i + 1] = (((h[i] * p) % mod) + c) % mod;
        h1[i + 1] = (((h1[i] * p) % mod1) + c) % mod1;
        //debug(h[i + 1]);
    }
    //Flag(1);
    //debug(h[l]);
    if(unSet.find(mp(h[l], h1[l])) != unSet.end()){
        return true;
    }
    return false;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int m, q; cin >> m >> q;
    n = 0;
    rep(i, 1, m){
        string s; cin >> s;
        n = max(n, (int) s.length());
        ask.pb(s);
    }
    rep(i, 1, q){
        string s; cin >> s;
        n = max(n, (int)s.length());
        query.pb(s);
    }
    prepareData();
    rep(i, 0, m - 1){
        insertString(ask[i]);
        //debug(ask[i]);
    }
    //cout << endl;
    rep(i, 0, q - 1){
        string s = query[i];
        if(queryString(s)){
            cout << "YES";
        }else{
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}
