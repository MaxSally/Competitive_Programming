//http://codeforces.com/contest/1006/problem/D

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

bool a[26];

int main(){
    io
    //freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int res = 0;
    int temp =  (int) n/2;
    FOR(i, 0, temp, 1){
        int cnt = 0;

        if(s[i] == s[n - i - 1]){
            if(t[n - i - 1] == t[i]){
                cnt = 0;
            }else{
                if(s[i] != t[i] && s[i] != t[n - i - 1]){
                    cnt = 2;
                }else{
                    cnt = 1;
                }
            }
        }else{
            if(t[n - i - 1] == t[i]){
                cnt = 1;
            }else{
                if(s[i] != t[i] && s[i] != t[n - i - 1]){
                    cnt++;
                }
                if(s[n - i - 1] != t[i] && s[n - i - 1] != t[n - i - 1]){
                    cnt++;
                }
            }
        }
        //cout << cnt << endl;
        res += cnt;
    }
    if(n % 2){
        res += (s[n/2] != t[n/2]? 1:0);
    }
    cout << res;
    return  0;
}
/*
for(auto j : a){
            cout << j << " ";
        }
        cout << endl;
*/
