//https://codeforces.com/contest/1181/problem/D
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

const int N = 500005;
int n, m, q, city[N];
vector<pair<ll, int> > a;
vi graph[N];
ll sum[N];

bool compare(pair<ll,int> b, pair<ll,int> c){
    if(b.first == c.first){
        return b.second < c.second;
    }
    return b.first < c.first;
}

int binarySearch(int left, int right, ll tar){
    int mid;
    int ans = -1;
    while(left <= right){
        mid = (left + right)/2;
        //debug(mid);
        if(sum[mid] <= tar){
            left = mid + 1;
            ans = mid;
        }else{
            right = mid - 1;
        }
    }
    return ans;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m >> q;
    mem(city, 0);
    mem(sum, 0);
    rep(i, 1, n){
        int x; cin >> x; city[x]++;
    }
    rep(i, 1, m){
        a.pb({city[i], i});
    }
    sort(a.begin(), a.end());
    vector<int> temp; temp.pb(a[0].second);
    graph[0] = temp;
    rep(i, 1, m - 1){
        sum[i] = sum[i - 1] + i*(a[i].first - a[i - 1].first);
        graph[i] = graph[i -1];
        graph[i].pb(a[i].second);
    }
    rep(i, 0, m){
        sort(graph[i].begin(), graph[i].end());
        /*rep(j, 0, (int)graph[i].size() - 1){
            cout << graph[i][j] << " ";
        }
        cout << endl;*/
    }
    //debuga1(sum, 1, m );
    while(q--){
        int x; cin >> x;
        x -= n;
        int b = binarySearch(0, m - 1, x);
        int c = x - sum[b];
        //debug(c);
        if(c == 0){
            cout << graph[b - 1][b - 1] << endl;
        }else{
            c--;
            int d = c % (b + 1);
            cout << graph[b][d] << endl;
        }
    }
    return 0;
}
