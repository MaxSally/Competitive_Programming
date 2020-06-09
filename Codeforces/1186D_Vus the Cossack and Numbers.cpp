//https://codeforces.com/contest/1186/problem/D
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

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int flag = true;
    int n; cin >> n;
    const ll p = 100000;
    ll totalD = 0;
    vector<pair<ll, int> > ans;
    rep(i,1 , n){
        double x; cin >> x;
        ll real = (ll)floor(x);
        int turn = ((abs(x - (int)x) < epsi)? 1: 0);
        totalD += real;
        //debug(real);
        //debug(deci); debug(real);debug(totalD); debug(turn);
        ans.pb(mp(real, turn));
    }
    //debug(totalD);
    //debug(turn);
    /*rep(i, 0, (int)ans.size() - 1){
        cout << ans[i].first << " " << ans[i].second << endl;
    }*/
    //debug(totalD);
    int ind = 0;
    for(int i = 0; i < abs(totalD); i++){
        while(ind < (int) ans.size() && ans[ind].second){
            ind++;
        }
        ans[ind].first++;
        ind++;
    }
    rep(i, 0, n - 1){
        cout << ans[i].first << endl;
    }
    return 0;
}
