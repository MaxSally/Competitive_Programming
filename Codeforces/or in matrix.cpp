//http://codeforces.com/problemset/problem/486/B

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

bool a[105][105];
bool b[105][105];
int m, n;
bool c[105], d[105];



int main(){
    io
    //freopen("input.txt","r",stdin);
    MEM(c, 0);
    MEM(d, 0);
    cin >> m >> n;
    FOR(i, 0, m, 1){
        MEM(b[i], 0);
        FOR(j, 0, n, 1){
            cin >> a[i][j];
        }
    }
    int check1, check2;
    check1 = m;
    check2 = n;
    FOR(i, 0, m, 1){
        FOR(j, 0, n, 1){
            if(!a[i][j]){
                c[i] = 1;
                check1--;
                break;
            }
        }
    }
    FOR(i, 0, n, 1){
        FOR(j, 0, m, 1){
            if(!a[j][i]){
                d[i] = 1;
                check2--;
                break;
            }
        }
    }
    FOR(i, 0, m, 1){
        FOR(j, 0, n, 1){
            if(a[i][j]){
                //cout << i << "IJ" << j << endl;
                if(!c[i] || !d[j]){
                    continue;
                }else{
                    cout << "NO";
                    return 0;
                }
            }else{
                FOR(k, 0, m, 1){
                    b[k][j] = 1;
                }
                FOR(k, 0, n, 1){
                    b[i][k] = 1;
                }
            }
        }
    }
    //cout << check1<< " " << check2 << endl;
    if(check1 == 0 && check2 == 0){

    }else{
        if(check1 == 0 || check2 == 0){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    FOR(i, 0, m, 1){
        FOR(j, 0, n, 1){
            cout << !b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
