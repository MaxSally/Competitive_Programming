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

const int N = 8005;

string s;
int x, y;
vi lst[2]; //0: y, 1: x
bool dp[2][N*2];

bool query(int turn, int x){
    if(lst[turn].empty()){
        return (x == 0);
    }
    x += 8000;
    rep(i, 0, 1){
        mem(dp[i], 0);
    }
    dp[0][8000 - lst[turn][0]] = dp[0][8000 + lst[turn][0]] = 1;
    rep(i, 1, lst[turn].size() - 1){
        int before = (i + 1) & 1;
        rep(j, 0, 8000){
            if(j - lst[turn][i] >= 0)
                dp[i & 1][j] = dp[before][j - lst[turn][i]];
            if(j + lst[turn][i] <= 16000)
                dp[i & 1][j] |= dp[before][j + lst[turn][i]];
        }
    }
    int n = lst[turn].size();
    return dp[(n - 1) & 1][x];
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> s >> x >> y;
    int ind = 0, n = s.length();
    while(ind < n && s[ind] == 'F'){
        ind++;
        x--;
    }
    ind++;
    int turn = 0;
    while(ind < n){
        int cnt = 0;
        while(ind < n && s[ind] == 'F'){
            cnt++;
            ind++;
        }
        ind++;
        if(cnt != 0)
            lst[turn].pb(cnt);
        turn = (turn == 1? 0: 1);
    }
    cout << (query(1, x) && query(0, y)? "Yes": "No");
    return 0;
}

