//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=614&page=show_problem&problem=1754
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

const int N = 80;
int mainD, supD, row[5], col[5];
pii num[N];

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    while(n--){
        rep(i, 1, 75){
            num[i].first = num[i].second = -1;
        }
        rep(i, 0, 4){
            row[i] = col[i] = 5;
        }
        mainD = supD = row[2] = col[2] = 4;
        rep(i, 0, 4){
            rep(j, 0, 4){
                if(i == 2 && j == 2) continue;
                int x; cin >> x;
                num[x] = {i, j};
            }
        }
        int ans = inf;
        rep(i, 1, 75){
            int x; cin >> x;
            int n = num[x].first;
            int m = num[x].second;
            if(n == -1 || m == -1) continue;
            row[n]--;
            col[m]--;
            if(n == m) mainD--;
            if(n + m == 4) supD--;
            if(row[n] == 0 || col[m] == 0 || mainD == 0 || supD == 0){
                ans = min(ans, i);
            }
        }
        cout << "BINGO after " << ans << " numbers announced" << endl;
    }
    return 0;
}

