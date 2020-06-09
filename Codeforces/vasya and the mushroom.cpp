//http://codeforces.com/contest/1016/problem/C

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

const int N = (int) 3*100000 + 5;
int a[N][2];
int n;


ll mushroom(ll day, int x, bool y){
    if(x == n - 1){
        return day*a[x][y] + (day + 1)*a[x][!y];
    }

        ll maxN = 0;
        ll day1 = day;
        FOR(i, x, n, 1){
            maxN += day*a[i][y];
            //cout << a[i][y] << " " << day << " " << maxN << endl;
            day++;
        }
        //cout << maxN << endl;
        RFOR(i, n - 1, x, 1){
            maxN += day*a[i][!y];
            day++;
        }
        //cout << x << " " << y << " " << maxN << endl;
        return  max(maxN,day1*a[x][y] + (day1 + 1) * a[x][!y] + mushroom(day1 + 2, x + 1, !y));
}

int main(){
    io
   // freopen("input.txt","r",stdin);
    //int n;
    cin >> n;
    FOR(i, 0, 2, 1){
        FOR(j, 0, n, 1){
            cin >> a[j][i];
            //cout << a[j][i] << " ";
            //b[j][i] = 0;
        }
        //cout << endl;
    }
    /*RFOR(i, n - 1, 0, 1){
        if(i == n - 1){
            b[i][n % 2] = (i)*a[i][n % 2] + a[i][!(n % 2)]*(i + 1);
            continue;
        }
        ll temp = i;
        int y = n % 2;
        b[i][y] = b[i + 2][y] + (temp)*a[i][y] + (temp + 1)*a[i][y] +
    }*/
    cout << mushroom(0, 0, 0);
    return 0;
}
