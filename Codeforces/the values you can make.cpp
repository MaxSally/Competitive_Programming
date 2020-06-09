//http://codeforces.com/contest/687/problem/C

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

//knap sack and generate using a list.

const int N = 505;
int n, k;
bool dp[2][N][N];

void print(){
    fo(i, 0, 2, 1){
        fo(j, 0, 20, 1){
            fo(h, 0, 20, 1){
                cout << dp[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}


int main(){
    io
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    dp[0][0][0] = 1;
    fo(i, 1, n + 1, 1){
        int a, cur, pre;
        cin >> a;
        cur = i % 2;
        pre = 1 - cur;
        fo(j, 0, k + 1, 1){
            fo(h, 0, j + 1, 1){
                dp[cur][j][h] = dp[pre][j][h];
                if(a <= j){
                    dp[cur][j][h] |= dp[pre][j - a][h];
                    if(a <= h){
                        dp[cur][j][h] |= dp[pre][j - a][h - a];
                    }
                }
            }
        }
        //print();
    }

    vector<int> ans;
    int cur = n % 2;
    fo(i, 0, k + 1, 1){
        if(dp[n % 2][k][i]){ // exists
            ans.pb(i);
        }
    }
    cout << ans.size() << "\n";
    forEach(it, ans){
        cout << *it  << " ";
    }
    return 0;
}

