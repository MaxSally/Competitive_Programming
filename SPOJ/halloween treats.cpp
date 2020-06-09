//https://www.spoj.com/problems/HALLOW/
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
int c, n;
int d[N], a[N];
vi cnt[N];

int main(){
    io;
    freopen("input.txt", "r", stdin);
    while(true){
        cin >> c >> n;
        if(c == 0 && n == 0) return 0;
        mem(d, 0);
        mem(cnt, 0);
        d[0] = 0;
        //debug(c); debug(n);
        rep(i, 1, n){
            cin >> a[i];
            d[i] = (d[i - 1] + a[i]) % c;
            cnt[d[i]].pb(i);
        }
        /*rep(i, 0, n - 1){
            rep(j, 0, (int)cnt[i].size() - 1){
                cout << cnt[i][j] << " ";
            }
            cout << endl;
        }*/
        if((int)cnt[0].size() > 0){
            int t = cnt[0][0];
            rep(j, 1, t){
                cout << j << " ";
            }
            cout << endl;
            continue;
        }
        rep(i, 1, n - 1){
            if((int)cnt[i].size() > 1){
                int s = cnt[i][0] + 1, t = cnt[i][1];
                //debug(s); debug(t);
                rep(j, s, t){
                    cout << j << " ";
                }
                cout << endl;
                break;
            }
        }
    }
    return 0;
}

