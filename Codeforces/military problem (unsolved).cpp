//http://codeforces.com/contest/1006/problem/E

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

int n, q;
VVI a, d;


bool compare(int a, int b){
    return a < b;
}

void addCommand(int y){
    d[y].PB(y);
    if(a[y].size() == 0){
        return;
    }
    FOR(i, 0, (int) a[y].size(), 1){
        int x = a[y][i];
        if(d[x].size() == 0){
            addCommand(x);
        }
        FOR(j, 0, (int) d[x].size(), 1){
            d[y].PB(d[x][j]);
        }

    }
}

void spreadCommand(){
    addCommand(1);
    /*FOR(i, 1, n + 1, 1){
        for(auto j: d[i]){
            cout << j << " ";
        }
        cout << endl;
    }*/
    while(q--){
        int x, y;
        cin >> x >> y;
        if( y <= d[x].size())
            cout << d[x][y - 1] << endl;
        else
            cout << -1 << endl;
    }
}

int main(){
    io
    //freopen("input.txt","r",stdin);
    cin >> n >> q;
    a.resize(n + 1);
    d.resize(n + 1);
    FOR(i, 2, n + 1, 1){
        int c;
        cin >> c;
        a[c].PB(i);
    }
    /*FOR(i, 1, n + 1, 1){
        for(auto j: a[i]){
            cout << j << " ";
        }
        cout << endl;
    }*/
    FOR(i, 1, n + 1, 1){
        sort(a[i].begin(), a[i].end(), compare);
    }
    spreadCommand();
    return 0;
}
