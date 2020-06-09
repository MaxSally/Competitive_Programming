//http://codeforces.com/problemset/problem/706/C

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
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define INFF (long long) 1e18
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define left tuyiuoi
#define right fgjhkj
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int N = 100005;
ll a[N][2];
ll energy[N];
int n;

int main(){
    io
    //freopen("input.txt","r",stdin);
    cin >> n;
    FOR(i, 0, n, 1){
        cin >> energy[i];
    }
    string s, s2, t, t2;
    cin >> s;
    reverse(s.begin(), s.end());
    s2 = s;
    reverse(s.begin(), s.end());
    FOR(i, 0, n, 1){
        a[i][0] = INFF;
        a[i][1] = INFF;
    }
    a[0][0] = 0;
    a[0][1] = energy[0];

    FOR(i, 1, n, 1){
        cin >> t;
        reverse(t.begin(), t.end());
        t2 = t;
        reverse(t.begin(), t.end());
        int cnt = 0;
        if(s <= t){
            a[i][0] = min(a[i][0], a[i - 1][0]);
        }
        if(s <= t2){
            a[i][1] = min(a[i][1], a[i - 1][0] + energy[i]);
        }
        if(s2 <= t){
            a[i][0] = min(a[i][0], a[i - 1][1]);
        }
        if(s2 <= t2){
            a[i][1] = min(a[i][1], a[i - 1][1] + energy[i]);
        }

        s = t;
        s2 = t2;
    }
    if(a[n - 1][0] == INFF && a[n - 1][1] == INFF){
        cout << -1;
        return 0;
    }
    cout << min(a[n - 1][0], a[n - 1][1]);
    return 0;
}
