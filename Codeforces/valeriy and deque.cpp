//https://codeforces.com/contest/1180/problem/C
/** Author : MaxSally
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
int maxB[N], b[N];
vector<int> c;
deque<int> d;
int n, q;

int main(){
    io;
    freopen("input.txt", "r", stdin);
    mem(maxB, 0);
    mem(b, 0);
    cin >> n >> q >> b[0];
    int maxN = b[0], ind = 0;
    maxB[0] = b[0];
    d.pb(b[0]);
    rep(i, 1, n - 1){
        cin >> b[i];
        d.push_back(b[i]);
        maxB[i] = max(maxB[i - 1], b[i]);
        if(maxB[i] > maxN){
            maxN = maxB[i];
            ind = i;
        }
    }
    rep(ii, 1, ind){
        int x = d.front();
        d.pop_front();
        int y = d.front();
        d.pop_front();
        if(x > y){
            d.push_front(x);
            d.push_back(y);
        }else{
            d.push_front(y);
            d.push_back(x);
        }
    }
    d.pop_front();
    while(d.size()){
        c.pb(d.front());
        d.pop_front();
    }
    //debuga1(c, 0, n - 2);
    while(q--){
        ll m; cin >> m;
        //rep(m, 1, temp){
        if(m <= max(1, ind)){
            cout << maxB[m - 1] << " " << b[m] << endl;
        }else{
            cout << maxN << " ";
            int k = (m - 1 - ind) % (n - 1);
            cout << c[k] << endl;
            //debug(k);
        }

    }
    return 0;
}
