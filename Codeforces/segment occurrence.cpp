//http://codeforces.com/contest/1016/problem/B

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

const int N = 1005;
VI a;

int main(){
    io
    //freopen("input.txt","r",stdin);
    int n, m, q;
    cin >> n >> m >> q;
    string s, t;
    cin >> s >> t;
    FOR(i, m - 1, n, 1){
        bool flag = true;
        FOR(j, i - m + 1, i + 1, 1){
            //cout << s[j] << " " << t[j - i + m - 1] << endl;
            if(s[j] != t[j - i + m - 1]){
                flag = false;
            }
        }
        if(flag){
            a.PB(i - m + 1);
        }

        //cout << a[i] << " ";
    }
    /*for(auto i : a){
        cout << i << " ";
    }
    cout << endl;*/
    while(q--){
        int b, c;
        cin >> b >> c;
        b--; c--;
        if(c - b + 1 < m){
            cout << 0 << endl;
            continue;
        }
        //cout << b << " " << c << endl;
        vector<int> :: iterator it1, it2;
        it1 = lower_bound(a.begin(), a.end(), b);
        it2 = upper_bound(a.begin(), a.end(), c - m + 1);
        //cout << it1 - a.begin() << " " << it2 - a.begin() << endl;
        //cout << *it1 << " " << *it2 << endl;
            cout << it2 - it1 << "\n";

    }
    return 0;
}
s
