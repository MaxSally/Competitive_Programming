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
int n, m;
ll b[N], t[N];

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    rep(i, 0, n - 1){
        cin >> t[i];
    }
    rep(i, 0, m - 1){
        cin >> b[i];
    }
    int j = 0;
    ll ans = 0;
    for(int i = 0; i < n && j < m; i++){
        if(b[j] <= t[i]){
            ans += (t[i] - b[j]) * 2;
            while(j < m && b[j] <= t[i]){
                j++;
            }
        }
        if(i == n - 1){
            if(j < m){
                ans += (b[m - 1] - t[i]) * 2;
            }
        }else if (j < m && b[j] < t[i + 1]){
            ll minimumDist = (t[i + 1] - b[j]) * 2; // walk from the next tele to the next bonus.
            while(j < m && b[j] <= t[i + 1]){ // walk from this tele to some bonus x and from the next teleport to bonus x + 1.
                ll curDistance = (b[j] - t[i]) * 2;
                if(j < m - 1 && b[j + 1] <= t[i + 1]){
                    curDistance += (t[i + 1] - b[j + 1]) * 2;
                }
                j++;
                minimumDist = min(minimumDist, curDistance);
            }
            ans += min(minimumDist, t[i + 1] - t[i]); //walk all the way
        }
    }
    cout << ans;
    return 0;
}
