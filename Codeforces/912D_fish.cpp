//https://codeforces.com/contest/912/problem/D
/*
* Author : MaxSally
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
#define rep(i, j, k) for (int i = j ; i <= k ; ++i)
#define rrep(i, j, k) for (int i = j; i >= k; --i)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define forEach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define in(A, B, C) assert( B <= A && A <= C)
#define mp make_pair
#define pb push_back
#define inf (int) (1e9 + 7)
#define epsi 1e-9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
#define read(type) readInt<type>()
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define left tuyiuoi
#define right fgjhk
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) rep(i, l, r) cout << a[i] << " "; cout << endl
#define Flag(n) cout << "here " << n << endl
const double pi=acos(-1.0);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<ll, ll> pll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int N = 100005;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
priority_queue<pair<ll,pair<int,int> > > pq;
int n, m, k, r;
ll totalArrangement;

ll findSquare(ll x, ll y){

    if(x > n/2){
        x = n + 1- x;
    }
    if(y > m/2){
        y = m + 1- y;
    }
    //debug(x); debug(y);
    return min(min(x, 1ll*r), 1LL*n - r + 1) * min(min(y, 1LL*r), 1LL*m - r + 1);
}

double bfs(){
    totalArrangement = 1LL*(n - r + 1) * (m - r + 1);
    set<pii> s;
    int x = (n + 1)/2, y = (m + 1)/2;
    ll v = findSquare(x, y);
    s.insert({x, y});
    pq.push({v, {x, y}});
    int cntK = 0;
    ll sum = 0;
    while(cntK < k && (int)pq.size()){
        sum += pq.top().first;
        x = pq.top().second.first; y = pq.top().second.second;
        //debug(x); debug(y); debug(pq.top().first);
        pq.pop();
        cntK++;
        rep(i, 0, 3){
            int x1 = x + dx[i], y1 = y + dy[i];
            if(x1 < 1 || x1 > n || y1 < 1 || y1 > m) continue;
            if(s.find(mp(x1, y1)) == s.end()){
                v = findSquare(x1, y1);
                //debug(x1); debug(y1); debug(v);
                pq.push({v,{x1, y1}});
                s.insert({x1, y1});
            }
        }
    }
    //debug(sum); debug(totalArrangement);
    return (1.0*sum)/totalArrangement;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m >> r >> k;
    cout << fixed << setprecision(9) << bfs();
    return 0;
}

