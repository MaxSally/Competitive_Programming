//https://vjudge.net/contest/333005#problem/B
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
#define foreach(i, a) for(auto i: a)
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
#define ss second
#define ff first
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

const int N = 400005;
int n;
vi a[3];
priority_queue<int> pq;

bool compare(int x, int y){
    return x > y;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n;
    ll cnt = 0, totalInfluence = 0;
    rep(i, 1, n){
        string x;
        int b; cin >> x >> b;
        if(x == "11"){
            cnt++;
            totalInfluence += b;
        }else if(x == "10" ){
            a[2].pb(b);
        }else if(x == "01"){
            a[1].pb(b);
        }else{
            pq.push(b);
        }
    }
    sort(all(a[1]), compare);
    sort(all(a[2]), compare);
    int len = min((int) a[1].size(), (int) a[2].size());
    rep(i, 0, len - 1){
        totalInfluence += a[1][i] + a[2][i];
    }
    rep(j, 1, 2){
        rep(i, len, (int) a[j].size() - 1){
            pq.push(a[j][i]);
        }
    }
    rep(i, 1, cnt){
        if(pq.empty()) break;
        totalInfluence += pq.top();
        pq.pop();
    }
    cout << totalInfluence;
    return 0;
}
