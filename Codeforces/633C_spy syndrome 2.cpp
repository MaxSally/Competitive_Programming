//https://codeforces.com/contest/633/problem/C
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

const int N = 1000005;

int a[N][30], n, m, suf[N], pr[N], pw[N];
string name[N], word, s;

int main() {
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> s >> m;
    int nn = 1;
    suf[1] = -1;
    mem(a, 0);
    rep(i, 0, m - 1) {
        cin >> word;
        name[i] = word;
        int t = 1;
        int len = (int)word.length();
        rep(j, 0, len - 1) {
            if(isupper(word[j])){
                word[j] = tolower(word[j]);
            }
            int c = word[j] - 'a';
            if (a[t][c] == 0) {
                nn++;
                suf[nn] = -1;
                a[t][c] = nn;
            }
            t = a[t][c];
        }
        suf[t] = i;
        //debuga1(suf, 0, n);
    }
    rep(i, 0, n - 1) {
        pr[i] = -1;
        pw[i] = -1;
    }
    pr[n] = 0;
    pw[n] = 0;

    rrep(i, n, 1) {
        if (pr[i] == -1) {
            continue;
        }
        int t = 1;
        rrep(j, i - 1, 0) {
            int c = s[j] - 'a';
            if (a[t][c] == 0) {
                break;
            }
            t = a[t][c];
            if (suf[t] != -1) {
                pr[j] = i;
                pw[j] = suf[t];
            }
        }
    }

    int id = 0;
    while (id < n) {

        if (id > 0) {
            cout << " ";
        }
        cout << name[pw[id]];
        id = pr[id];
    }
    cout << endl;
    return 0;
}
