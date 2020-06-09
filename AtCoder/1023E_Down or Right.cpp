//https://codeforces.com/problemset/problem/1023/E
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

const int N = 505;
int n;
bool a[N][N];
int dx[4] = {0, 1, -1,0};
int dy[4] = {1, 0, 0, -1};

void printPath(int x, int y){
    a[x][y] = 1;
    int iniX = x, iniY = y;
    while(x != n || y != n){
        printf("? %d %d %d %d\n", x + 1, y, n, n);
        fflush(stdout);
        string ans; cin >> ans;
        if(ans == "YES"){
            x++;
        }else{
            y++;
        }
        a[x][y] = 1;
    }
    x = iniX; y = iniY;
    while(x != 1 || y != 1){
        if(x == 1){
            a[x][y] = 1;
            y--;
            continue;
        }
        if(y == 1){
            a[x][y] = 1;
            x--;
            continue;
        }
        rep(i, 2, 3){
            printf("? %d %d %d %d\n", x + dx[i], y + dy[i], n, n);
            fflush(stdout);
            string ans; cin >> ans;
            if(ans == "YES"){
                x += dx[i];
                y += dy[i];
                a[x][y] = 1;
                break;
            }
        }
    }
    a[1][1] = a[n][n] = 1;
    string t = "! ";
    x = 1; y = 1;
    while(x != n || y != n){
        if(x == n || a[x][y + 1]){
            t += "R";
            y++;
            continue;
        }
        if(y == n || a[x + 1][y]){
            t += "D";
            x++;
            continue;
        }
    }
    printf("%s\n", t.c_str());
    fflush(stdout);
    return;
}

void fastPrintGraph(){
    int x, y; x = y = n;
    while(x - 1 + y - 1 - 1>= n - 1){
        printf("? 1 1 %d %d\n", x - 1, y);
        fflush(stdout);
        string ans; cin >> ans;
        if(ans == "YES"){
            x--;
        }else{
            y--;
        }
        a[x][y] = 1;
    }
    x = y = 1;
    while(n - x + n - y - 1>= n - 1){
        printf("? %d %d %d %d\n", x, y + 1, n, n);
        fflush(stdout);
        string ans; cin >> ans;
        if(ans == "YES"){
            y++;
        }else{
            x++;
        }
        a[x][y] = 1;
    }
    a[1][1] = a[n][n] = 1;
    string t = "! ";
    x = 1; y = 1;
    while(x != n || y != n){
        if(x == n || a[x][y + 1]){
            t += "R";
            y++;
            continue;
        }
        if(y == n || a[x + 1][y]){
            t += "D";
            x++;
            continue;
        }
    }
    printf("%s\n", t.c_str());
    fflush(stdout);
}


int main(){
    //io;
    //freopen("input.txt", "r", stdin);
    cin >> n;
    rep(i, 1, n){
        mem(a[i], 0);
    }
    /*rep(i, 1, n){
        printf("? 1 1 %d %d\n", i, n + 1 - i);
        fflush(stdout);
        string ans; cin >> ans;
        if(ans == "NO"){
            continue;
        }
        printf("? %d %d %d %d\n", i, n + 1 - i, n, n);
        fflush(stdout);
        cin >> ans;
        if(ans == "NO") continue;
        printFastGraphPath();
        break;
    }*/
    fastPrintGraph();
    return 0;
}
