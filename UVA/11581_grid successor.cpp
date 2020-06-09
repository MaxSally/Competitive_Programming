//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=624&page=show_problem&problem=2628
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

const int N = 0;
bool mat[3][3], b[3][3];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int t; cin >> t;
    while(t--){
        rep(i, 0, 2){
            rep(j, 0, 2){
                char c; cin >> c;
                mat[i][j] = c - '0';
            }
        }
        int turn = -1;
        while(true){
            bool flag = 1;
            rep(i, 0, 2){
                rep(j, 0, 2){
                    if(mat[i][j]) flag = 0;
                }
            }
            if(flag){
                cout << turn << '\n';
                break;
            }
            turn++;
            rep(i, 0, 2){
                rep(j, 0, 2){
                    int cnt = 0;
                    rep(k, 0, 3){
                        int x1 = i + dx[k];
                        int y1 = j + dy[k];
                        if(x1 < 0 || x1 > 2 || y1 < 0 || y1 > 2) continue;
                        cnt += mat[x1][y1];
                    }
                    b[i][j] = cnt % 2;
                }
            }
            rep(i, 0, 2){
                rep(j, 0, 2){
                    mat[i][j] = b[i][j];
                }
            }
        }
    }
    return 0;
}
