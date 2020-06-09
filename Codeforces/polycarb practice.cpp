//http://codeforces.com/contest/1006/problem/B

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

const int N = 2005;
VII a;

bool compare(PII b, PII c){
    if(b.first == c.first){
        return b.second > c.second;
    }
    return b.first > c.first;
}

priority_queue<int, vector<int>, greater<int> > pq;

int main(){
    io
    //freopen("input.txt","r",stdin);
    int n, k;
    cin >> n >> k;
    //cout << n << " " << k;
    FOR(i, 0, n, 1){
        int c;
        cin >> c;
        //cout << c << " ";
        a.PB(MP(c, i));
    }
    sort(a.begin(), a.end(), compare);
    /*for(auto i: a){
        cout << i.first << " " << i.second << endl;
    }*/
    int maxN = 0;
    FOR(i, 0, k ,1){
        pq.push(a[i].second);
        maxN += a[i].first;
    }
    int cur = -1;
    cout << maxN << endl;
    while(!pq.empty()){
        //cout << cur << endl;
        if(pq.size() == 1){
            cout << n - cur  - 1;
        }else{
            cout << pq.top() - cur << " ";
        }
        cur = pq.top();
        pq.pop();
    }
    return 0;
}
