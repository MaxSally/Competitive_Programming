//https://codeforces.com/gym/100741/problem/A
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

const int N = 10005;
ll bitTree[15][N], a[N];
int n, m;

void update(int p, int x, int row){
    p++;
    for(int i = p; i <= n + 1; i += i & (-i)){
        bitTree[row][i] += x;
    }
}

ll querySum(int p, int row){
    p++;
    ll sum = 0;
    for(int i = p; i > 0; i -= i & (-i)){
        sum += bitTree[row][i];
    }
    return sum;
}

void initiate(){
    rep(i, 0, 14){
        fill(bitTree[i], bitTree[i] + n + 1, 0);
    }
    //fill(bitTree[0], bitTree[15], 0);
    rep(i, 0, n - 1){
        update(i, a[i], a[i] % m);
    }
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    mem(a, 0);
    rep(i, 0, n - 1){
        cin >> a[i];
    }
    //debuga1(a, 0, n - 1);
    initiate();
    //debuga1(a, 0, n - 1);
    int q; cin >> q;
    while(q--){
        char c; cin >> c;
        switch (c)
        {
            case '+':
                int x, y; cin >> x >> y;
                x--;
                update(x, a[x] + y, (a[x] + y) % m);
                update(x, -a[x], a[x] % m);
                a[x] += y;
                cout << a[x] << endl;
                break;
            case '-':
                cin >> x >> y;
                x--;
                if(a[x] < y){
                    cout << a[x] << endl;
                    break;
                }
                update(x, a[x] - y, (a[x] - y) % m);
                update(x, -a[x], a[x] % m);
                a[x] -= y;
                cout << a[x] << endl;
                break;
            case 's':
                int l, r, md; cin >> l >> r >> md;
                l--; r--;
                //debug(querySum(r, md));
                cout << (querySum(r, md) - querySum(l - 1, md)) << endl;
        }

    }
    return 0;
}
