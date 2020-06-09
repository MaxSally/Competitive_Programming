//https://vietnam-national19.kattis.com/problems/gatheringinyorknew
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
int n;
ll sum[N];

ll count(vi &a){
    if((int)a.size() == 1){
        return 0;
    }
    mem(sum, 0);
    int n = (int)a.size();
    //debuga1(a, 1, n - 1);
    rep(i, 1, n - 1){
        sum[i] = sum[i - 1] + a[i];
    }
    int x = 0, y = 0;
    ll ans = (ll) 1e15;
    rep(i, 1, n - 1){
        ll cnt = 0;
        cnt += sum[n - 1] - sum[i] - 1LL * a[i] * (n - 1 - i);
        cnt += sum[x] - sum[0];
        cnt += 1LL* a[i] * y - (sum[x + y] - sum[x]);
        y++;
        while(y >= 0 && a[x + 1] < a[i + 1] - a[x + 1]){
            x++;
            y--;
        }
        //debug(cnt);
        ans = min(cnt, ans);
    }
    //ebug(ans);
    return ans;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n;
    vi a,b;
    a.pb(0);
    b.pb(0);
    ll sumA = 0, sumB = 0;
    rep(i, 1, n){
        int x; cin >> x;
        if(x > 0){
            a.pb(x);
            sumA += x;
        }else{
            b.pb(-x);
            sumB += -x;
        }
    }
    sort(all(a));
    sort(all(b));
    ll ans = min(count(a)  + sumB, count(b) + sumA);
    cout << ans;
    return 0;
}
