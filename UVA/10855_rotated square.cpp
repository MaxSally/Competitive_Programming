//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=624&page=show_problem&problem=1796
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
int n, m;

int cntSquare(vector<string> &a, vector<string> &b){
    int cnt = 0;
     rep(i, 0, m - n){
        rep(j, 0, m - n){
            bool flag = 1;
            rep(l, 0, n * n - 1){
                int k = l/n;
                int h = l % n;
                if(a[i + k][j + h] != b[k][h]){
                    flag = 0;
                    break;
                }
            }
            if(flag) cnt++;
        }
     }
     return cnt;
}

void printSquare(vector<string> &a){
    rep(i, 0, n - 1){
        cout << a[i] << endl;
    }
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    string s;
    while(true){
        cin >> m >> n;
        getline(cin, s);
        if(n == 0 && m == 0){
            return 0;
        }
        vector<string> a, b, c;
        rep(i, 1, m){
            getline(cin, s);
            a.pb(s);
        }
        s = "";
        rep(i, 1, n){
            string temp; cin >> temp; s+= temp;
            b.pb(temp);
        }
        rep(i, 0, n - 1){
            string temp = "";
            rrep(j, n - 1, 0){
                int x = n * j + i;
                temp += s[x];
            }
            c.pb(temp);
        }
        //printSquare(b);
        //printSquare(c);
        cout <<cntSquare(a, b) << " " <<  cntSquare(a, c) << " ";
        reverse(b.begin(), b.end()); reverse(c.begin(), c.end());
        rep(i, 0, n - 1){
            reverse(b[i].begin(), b[i].end());
            reverse(c[i].begin(), c[i].end());
        }
        cout << cntSquare(a, b) << " " << cntSquare(a, c) << endl;

    }
    return 0;
}

