//https://codeforces.com/problemset/problem/958/E2
/*
* Author : Max Nguyen
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
#define fo(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define rfor(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define rep(i, j) fo(i, 0, j, 1)
#define rrep(i, j) rfor(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define forEach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define in(A, B, C) assert( B <= A && A <= C)
#define mp make_pair
#define pb push_back
#define inf (int)(1e9 + 7)
#define epsi 1e-9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
#define read(type) readInt<type>()
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define left tuyiuoi
#define right fgjhk
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fo(i, l, r, 1) cout << a[i] << " "; cout << endl
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

const int N = 500005;
const int K = 5005;
int k, n, x, ship[N];
pii secondShip[N];
ll dp[3][K][2];

bool compare(pii a, pii b){
    return a.second < b.second;
}

int process(){
    dp[1][0][0] = 0;
    dp[1][1][1] = 1ll*secondShip[0].first;
    fo(a, 2, min(3*k , n), 1){
        dp[2][1][0] = min(dp[1][1][0], dp[1][1][1]);
        dp[2][1][1] = 1ll*secondShip[a - 1].first;
        fo(b, 2, a + 1, 1){
            dp[2][b][0] = min(min(dp[1][b][0], dp[1][b][1]), min(dp[0][b][0], dp[0][b][1]));
            dp[2][b][1] = min(min(dp[0][b - 1][0], dp[0][b - 1][1]), dp[1][b - 1][0]);
            if((secondShip[a - 1].second - 1) != secondShip[a - 2].second){
                dp[2][b][1] = min(dp[2][b][1], dp[1][b - 1][1]);
            }
            dp[2][b][1] = dp[2][b][1] + secondShip[a - 1].first;
        }
        /*debug(a);
        rep(i, 3){
            rep(j, 2){
                rep(l, k + 1){
                    cout << dp[i][l][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }*/
        rep(i, 2){
            rep(j, a + 1){
                dp[i][j][0] = dp[i + 1][j][0];
                dp[i][j][1] = dp[i + 1][j][1];
            }
        }
    }
    return min(dp[1][k][0], dp[1][k][1]);
}

int main(){
    io
    freopen("input.txt","r",stdin);
    cin >> k >> n;
    rep(i, n){
        cin >> ship[i];
    }
    sort(ship, ship + n);
    rep(i, n){
        secondShip[i].first = ship[i + 1] - ship[i];
        secondShip[i].second = i + 1;
    }
    sort(secondShip, secondShip + n);
    sort(secondShip, secondShip + min(3*k - 1, n), compare);
    rep(i, min(3*k + 1, n)){
        cout << secondShip[i].first << " " << secondShip[i].second << endl;
    }
    fo(i, 0, 3, 1){
        fo(j, 0, k + 1, 1){
            dp[i][j][0] = dp[i][j][1] = inf;
        }
    }
    cout << process();
    return 0;
}
