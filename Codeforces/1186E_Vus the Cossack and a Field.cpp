//https://codeforces.com/contest/1186/problem/E
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

const int N = 1005;
int n, m, q;
int a[N][N], sumH[N][N], sumV[N][N], totalSum[N][N];

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >>m >> q;
    ll sumLastH = 0, sumLastV = 0;
    rep(i, 1, n){
        rep(j, 1, m){
            char c; cin >> c;
            a[i][j] = c - '0';
            sumH[i][j] = sumH[i][j - 1] + a[i][j];
            sumV[i][j] = sumV[i - 1][j] + a[i][j];
            totalSum[i][j] = totalSum[i][j - 1] + sumV[i][j];
            if(i == n){
                sumLastV += sumV[i][j];
            }
        }
        sumLastH += sumH[i][m];

    }
    /*rep(i, 1, n){
        rep(j, 1, m){
            cout << totalSum[i][j] << " ";
        }
        cout << endl;
    }*/
    while(q--){
        int x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;
        int difX = x2 - x1, difY = y2 - y1;
        int even = 0, odd = 0;
        int blockX1 = (x1 + n - 1)/n, blockX2 = (x2 + n - 1)/n;
        int step = (x2 - x1 + 1) % n;
        int modX1 = x1 % n, modX2 = x2 % n, modY1 = y1 % m, modY2 = y2 % m;
        if(modX1 == 0){
            modX1 = n;
        }
        if(modX2 == 0){
            modX2 = n;
        }
        if(modY1 == 0){
            modY1 = m;
        }
        if(modY2 == 0){
            modY2 = m;
        }
        ll sum = 0;
        rep(i, 1, step){
            int tempX = modX1 + i;
            if(tempX > n){
                tempX -= n;
            }
            if(modY1 <= modY2){
                sum += sumH[tempX][modY2] - sumH[tempX][modY1];
            }else{
                sum += sumH[tempX][modY2] - sumH[tempX][0] + sumH[tempX][m] - sumH[tempX][modY1 - 1];
            }
        }
        sum += (x2 - x1 + 1)/n * sumLastH + (y2 - y1 + 1)/m * sumLastV;
        cout << sum << endl;
    }
    return 0;
}

