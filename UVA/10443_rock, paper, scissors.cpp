//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=614&page=show_problem&problem=1384

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

const int N = 105;

pair<char,char> a[N][N];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1 , 0};

int winner(char c, char d){
    if(c == d){
        return 2;
    }
    if(c == 'R' && d == 'S'){
        return 1;
    }
    if(c == 'S' && d == 'P'){
        return 1;
    }
    if(c == 'P' && d == 'R'){
        return 1;
    }
    if(c == 'S' && d == 'R'){
        return 0;
    }
    if(c == 'R' && d == 'P'){
        return 0;
    }
    return 0;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int t; cin >> t;
    while(t--){
        int r, c, n;
        cin >> r >> c >> n;
        rep(i, 1, r){
            rep(j, 1, c){
                cin >> a[i][j].first;
                a[i][j].second = 'X';
            }
        }
        while(n--){
            rep(i, 1, r){
                rep(j, 1, c){
                    rep(k, 0, 3){
                        int x1 = i + dx[k];
                        int y1 = j + dy[k];
                        if(x1 <= 0 || x1 > r || y1 <= 0 || y1 > c) continue;
                        int res = winner(a[i][j].first, a[x1][y1].first);
                        //debug(x1); debug(y1); debug(res);

                        if(res == 1 && a[x1][y1].second == 'X'){
                            a[x1][y1].second = a[i][j].first;
                        }
                       /* rep(i, 1, r){
                            rep(j, 1, c){
                                cout <<  a[i][j].second;
                            }
                            cout << endl;
                        }
                        cout << endl;*/
                    }
                }
            }
            rep(i, 1, r){
                rep(j, 1, c){
                    if(a[i][j].second == 'X') continue;
                    a[i][j].first = a[i][j].second;
                    a[i][j].second = 'X';
                }
            }
            /*rep(i, 1, r){
                rep(j, 1, c){
                    cout <<  a[i][j].first;
                }
                cout << endl;
            }
            cout << endl;*/
        }
        rep(i, 1, r){
            rep(j, 1, c){
                cout <<  a[i][j].first;
            }
            cout << endl;
        }
        if(t > 0) cout << endl;
    }
    return 0;
}
