//http://codeforces.com/contest/1015/problem/D

/*
* Author : Max Nguyen
* Handle: code_crack_01
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

int main(){
    io
    freopen("input.txt","r",stdin);
    ll n, k ,s;
    cin >> n >> k >> s;
    if(n == 2){
        if(k == s){
            cout << "YES" << endl;
            for(int i = 0; i < k; i++){
                if(i % 2){
                    cout << 1 << " ";
                }else{
                    cout << 2 << " ";
                }
            }
            return 0;
        }else{
            cout << "NO" << endl;;
            return 0;
        }
    }
    ll a, b;
    a = k;
    b = s/(n - 1);
    if(a < b || k > s){
        cout << "NO";
        return 0;
    }
    if(a == b){
        if(s % (n-1)){
            cout << "NO";
            return 0;
        }
    }

    bool flag = true;
    cout << "YES" << endl;
    ll temp = (s - k)/(n - 2);
    for(int i = 0; i < temp; i++){
        if(i % 2){
            cout << "1 ";
        }else{
            cout << n << " ";
        }
    }
    ll extra = ( s - k) % (n - 2);
    //cout << extra << endl;
    ll temp1 = k - temp;
    ll cnt = temp;
    while(temp1--){
        cnt++;
        if(temp % 2){
            if(flag)
                cout << (cnt == k? n - 1 - extra:n - 1) << " ";
            else
                cout << (cnt == k? n - extra:n) << " ";
            flag = !flag;
        }else{
            if(flag){
                //cout << cnt << "cnt ";
                cout << (cnt == k? 2 + extra:2) << " ";
            }else
                cout << (cnt == k? 1 + extra:1) << " ";
            flag = !flag;
        }
    }
    //queue<int> q;
    return 0;
}
