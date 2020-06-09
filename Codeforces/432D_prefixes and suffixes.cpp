//https://codeforces.com/problemset/problem/432/D
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

const int N = 100005;
string s;
int z[N];
int cnt[N];
int n;
vii ans;

void zAlgo(){
    int l, r, k; l = r = 0;
    rep(i, 1, n - 1){
        if(i > r){
            l = r = i;
            while(r < n && s[r - l] == s[r]){
                r++;
            }
            z[i] = r - l;
            r--;
        }else{
             k = i - l;
             if(z[k] < r - i + 1){
                z[i] = z[k];
             }else{
                l = i;
                while(r < n && s[r - l] == s[r]){
                    r++;
                }
                z[i] = r - l;
                r--;
             }
        }
    }
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    mem(cnt, 0);
    mem(z, 0);
    cin >> s;
    n = (int)s.length();
    zAlgo();
    z[0] = n;
    rep(i, 1, n - 1){
        cnt[z[i]]++;
    }
    cnt[n] = 1;
    rrep(i, n - 1, 0){
        cnt[i] += cnt[i + 1];
    }
    rep(i, 1, n){
        if(z[n - i] == i){
            ans.pb({i, cnt[i]});
        }
    }
    cout << (int)ans.size() << endl;
    for(pii a: ans){
        cout << a.first << " " << a.second << endl;
    }
    return 0;
}
