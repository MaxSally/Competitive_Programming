//http://codeforces.com/problemset/problem/698/A

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

int a[105][3];
int n;

int main(){
    io
    //freopen("input.txt","r",stdin);
    FOR(i, 0, 105, 1){
        a[i][0] = INF;  //rest
        a[i][1] = INF;  //contest
        a[i][2] = INF;  //gym
    }

    cin >> n;
    int b;
    int pre = -1;
    a[0][0] = a[0][1] = a[0][2] = 0;
    FOR(i, 1, n + 1, 1){
        cin >> b;
        a[i][0] = min(min(a[i - 1][0], a[i - 1][1]), a[i - 1][2]) + 1;
        if(b == 1 || b == 3){
            a[i][1] = min(a[i - 1][0], a[i - 1][2]);
        }
        if(b == 2 || b == 3){
            a[i][2] = min(a[i - 1][0], a[i - 1][1]);
        }
    }
//    FOR(i, 0, 3, 1){
//        FOR(j, 0, n + 1, 1){
//            cout << a[j][i] << " ";
//        }
//        cout << endl;
//    }

    cout << min(min(a[n][0], a[n][1]), a[n][2]);
    return 0;
}
