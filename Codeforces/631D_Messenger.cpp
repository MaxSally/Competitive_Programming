//https://codeforces.com/problemset/problem/631/D
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
#define foreach(i, a) for(auto i: a)
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
#define ss second
#define ff first
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

const int N = 200005;
vector<pair<int, ll> > a, b;
int n, m, prefix[N];

pair<int, ll> processString(string s){
    int c = s.back() - 'a';
    s.pop_back(); s.pop_back();
    int num = 0;
    foreach(v, s){
        num *= 10;
        num += v - '0';
    }
    return {c, num};
}

void generatePrefix(){
    int i = 1, j = 0;
    mem(prefix, 0);
    prefix[0] = 0;
    while(i < m){
        if(b[i].ff == b[j].ff){
            j++;
            prefix[i] = j;
            i++;
        }else{
            if(j == 0){
                prefix[i] = 0;
                i++;
            }else{
                j = prefix[j - 1];
            }
        }
    }
}

int cntSubString(pair<int, ll> pre, pair<int, ll> post){
    int i = 0, j = 0, cnt = 0;
    //debug(n); debug(m);
    //debuga1(prefix, 0, m);
    //cout << a[7].ff << " " << a[7].ss << endl;
    while(i < n){
        //debug(i); debug(j); debug(cnt);
        if(a[i].ff == b[j].ff && a[i].ss == b[j].ss){
            i++;
            j++;
        }
        if(j == m){
            if(a[i - j - 1].ff == pre.ff && a[i - j - 1].ss >= pre.ss && a[i].ff == post.ff && a[i].ss >= post.ss){
                cnt++;
            }
            j = prefix[j - 1];

        }else if(i < n && (a[i].ff != b[j].ff) || a[i].ss != b[j].ss){
            if(j == 0){
                i++;
            }else{
                j = prefix[j - 1];
            }
        }
    }
    return cnt;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    int len = 0;
    rep(i, 0, n - 1){
        string s; cin >> s;
        pair<int, ll> temp = processString(s);
        if(len > 0 && a[len - 1].ff == temp.ff){
            a[len - 1].ss += temp.ss;
        }else{
            len++;
            a.pb(temp);
        }
    }
    n = len;
    len = 0;
    rep(i, 0, m - 1){
        string s; cin >> s;
        pair<int, ll> temp = processString(s);
        if(len > 0 && b[len - 1].ff == temp.ff){
            b[len - 1].ss += temp.ss;
        }else{
            len++;
            b.pb(temp);
        }
    }
    m = len;
    if(m == 1){
        ll ans = 0;
        rep(i, 0, n - 1){
            if(a[i].ff == b[0].ff && a[i].ss >= b[0].ss){
                ans += a[i].ss - b[0].ss + 1;
            }
        }
        cout << ans;
        return 0;
    }else if(m == 2){
        int ans = 0;
        rep(i, 0, n - 2){
            if(a[i].ff == b[0].ff && a[i].ss >= b[0].ss && a[i + 1].ff == b[1].ff && a[i + 1].ss >= b[1].ss){
                ans++;
            }
        }
        cout << ans;
        return 0;
    }
    pair<int, ll> pre = b[0], post = b[m - 1];
    m -= 2;
    b.erase(b.begin());
    b.erase(b.begin() + (int)b.size() - 1);
    generatePrefix();
    cout << cntSubString(pre, post);
    return 0;
}
