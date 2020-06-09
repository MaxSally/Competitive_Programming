//https://codeforces.com/contest/1182/problem/B
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

const int N = 505;
bool a[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;

bool check(){
    rep(i, 1, n){
        rep(j, 1, m){
            if(a[i][j]) return 0;
        }
    }
    return true;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    rep(i, 1, n){
        rep(j, 1, m){
            char c; cin >> c;
            a[i][j] = (c == '*');
        }
    }
    rep(i, 1, n){
        rep(j, 1, m){
            int cnt = a[i][j];
            rep(k, 0, 3){
                int x1 = i + dx[k], y1 = j + dy[k];
                if(x1 < 1 || y1 < 1 || x1 > n || y1 > m) continue;
                cnt += a[x1][y1];
            }
            if(cnt == 5){
                int x = i - 1, y = j - 1;
                while(x > 0 && a[x][j]){
                    a[x][j] = 0;
                    x--;
                }
                x = i + 1;
                while(x <= n && a[x][j]){
                    a[x][j] = 0;
                    x++;
                }
                while(y > 0 && a[i][y]){
                    a[i][y] = 0;
                    y--;
                }
                y = j + 1;
                while(y <= m && a[i][y]){
                    a[i][y] = 0;
                    y++;
                }
                a[i][j] = 0;
                if(check()){
                    cout << "YES";
                }else{
                    cout << "NO";
                }
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
