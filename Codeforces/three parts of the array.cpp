//http://codeforces.com/contest/1006/problem/C

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
#define tuyiuoi left
#define sakjdfhdks right
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

const int N = 200005;
ll a[N];

int main(){
    io
    //freopen("input.txt","r",stdin);
    int i, j;
    ll left, right;
    int n;
    cin >> n;
    FOR(i, 0, n, 1){
        cin >> a[i];
    }
    i = 0;
    j = n - 1;
    left = a[0];
    right = a[j];
    ll maxN = 0;
    i++;
    j--;
    while(i - 1 < j + 1){
        while(left < right && i < n){
            left += a[i];
            i++;
           // cout << left << " " << i << endl;
        }
        while(left > right && j >= 0){
            right += a[j];
            j--;
            //cout << right << " " << j << endl;
        }
        //cout << left << " " << right << " " << i <<" " << j << endl;
        if(left == right && i - 1 < j + 1){
            maxN = left;
            //cout << left << " " << right << " " << i <<" " << j << endl;
            left += a[i];
            i++;
            right += a[j];
            j--;
            //cout << left << " " << right << " " << i <<" " << j << endl;
        }
    }
    cout << maxN;

    return 0;
}
