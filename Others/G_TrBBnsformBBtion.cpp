///https://vjudge.net/contest/363384#problem/G
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

const int N = 100005;
int sumA1[N], sumA2[N], sumB1[N], sumB2[N];

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int q;
    string s, t; cin >> s >> t >> q;
    int n = max(s.length(), t.length());
    s = "#" + s;
    t = "#" + t;
    rep(i, 1, (int)s.length() - 1){
        if(s[i] == 'A'){
            sumA1[i] = sumA1[i - 1] + 1;
            sumB1[i] = sumB1[i - 1];
        }else{
            sumB1[i] = sumB1[i - 1] + 1;
            sumA1[i] = sumA1[i - 1];
        }
    }
    rep(i, 1, (int)t.length() - 1){
        if(t[i] == 'A'){
            sumA2[i] = sumA2[i - 1] + 1;
            sumB2[i] = sumB2[i - 1];
        }else{
            sumB2[i] = sumB2[i - 1] + 1;
            sumA2[i] = sumA2[i - 1];
        }
    }
    while(q--){
        int a, b, c, d; cin >> a >> b >> c >> d;
        a--; c--;
        int differenceS = (sumA1[b] - sumA1[a]) - (sumB1[b] - sumB1[a]);
        int differenceT = (sumA2[d] - sumA2[c]) - (sumB2[d] - sumB2[c]);
        if((differenceS - differenceT + 12 * n) % 3 == 0){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}
