//https://codeforces.com/contest/430/problem/D

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
#define inf (int)1e9
#define epsi 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define left tuyiuoi
#define right fgjhkj
const double pi=acos(-1.0);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int N = 1005;
int n, m;
ll a[N][N];
ll b[4][N][N];

void maxi(){
    fo(i, 1, n + 1, 1){
        fo(j, 1, m + 1, 1){
            b[0][i][j] = max(b[0][i - 1][j], b[0][i][j - 1]) + a[i][j];
        }
    }
    rfor(i, n, 1, 1){
        fo(j, 1, m + 1, 1){
            b[1][i][j] = max(b[1][i + 1][j], b[1][i][j - 1]) + a[i][j];
        }
    }
    fo(i, 1, n + 1, 1){
        rfor(j, m, 1, 1){
            b[2][i][j] = max(b[2][i - 1][j], b[2][i][j + 1]) + a[i][j];
        }
    }
    rfor(i, n, 1, 1){
        rfor(j, m, 1, 1){
            b[3][i][j] = max(b[3][i + 1][j], b[3][i][j + 1]) + a[i][j];
        }
    }
//    fo(i, 0, 4, 1){
//        fo(j, 1, n + 1, 1){
//            fo(k, 1, m + 1, 1){
//                cout << b[i][j][k] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
}



ll workOut(){
    ll maxN = 0;
    fo(i, 2, n, 1){
        fo(j, 2, m, 1){
            maxN = max(max(maxN, b[0][i - 1][j] + b[1][i][j - 1] + b[2][i][j + 1] + b[3][i + 1][j]), b[0][i][j - 1] + b[1][i + 1][j] + b[2][i - 1][j] + b[3][i][j + 1]);
        }
    }
    return maxN;
}

int main(){
    io
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    fo(i, 1, n + 1, 1){
        fo(j, 1, m + 1, 1){
            cin >> a[i][j];
        }
    }
    maxi();
    cout << workOut();
    return 0;
}
