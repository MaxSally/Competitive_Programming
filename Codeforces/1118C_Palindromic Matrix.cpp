//https://codeforces.com/problemset/problem/1118/C
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

const int N = 25;
int a[N][N], n, cnt[1005];

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n;
    rep(i, 1, n*n){
        int x; cin >> x;
        cnt[x]++;
    }
    if(n & 1){
        int x = 0,y = 0, col = 0, row = 0;
        bool flag = true;
        rep(i, 1, 1000){
            if(cnt[i] == 0) continue;
            while(cnt[i] >= 4 && y < n/2){
                a[x][y] = a[x][n - 1 - y] = a[n - 1 - x][y] = a[n - 1 - x][n - 1 - y] = i;
                x++;
                if(x == n/2){
                    x = 0;
                    y++;
                }
                cnt[i] -= 4;
                if(y == n/2) break;

            }
            while(cnt[i] >= 2){
                if(row < n/2){
                    a[n/2][row] = a[n/2][n - 1 - row] = i;
                    row++;
                }else if(col < n/2){
                    a[col][n/2] = a[n - 1 - col][n/2] = i;
                    col++;
                }else{
                    break;
                }
                cnt[i] -= 2;
            }
            if((cnt[i] & 1) && flag){
                flag = false;
                a[n/2][n/2] = i;
                cnt[i]--;
            }else if((cnt[i] & 1) && !flag){
                cout << "NO";
                return 0;
            }
            if(cnt[i] > 0){
                cout << "NO";
                return 0;
            }
        }
        if(row != n/2 || col != n/2){
            cout << "NO";
            return 0;
        }
    }else{
        int x = 0,y = 0;
        rep(i, 1, 1000){
            if(cnt[i] == 0) continue;
            if(cnt[i] % 4 != 0){
                cout << "NO";
                return 0;
            }else{
                while(cnt[i] > 0){
                    a[x][y] = a[x][n - 1 - y] = a[n - 1 - x][y] = a[n - 1 - x][n - 1 - y] = i;
                    x++;
                    if(x == n/2){
                        x = 0;
                        y++;
                    }
                    cnt[i] -= 4;
                }

            }
        }

    }
    cout << "YES\n";
    rep(i, 0, n - 1){
        rep(j, 0, n - 1){
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
