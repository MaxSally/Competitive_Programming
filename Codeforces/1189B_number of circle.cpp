//https://codeforces.com/contest/1189/problem/B
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
int a[N];
deque<int> d;
priority_queue<int, vector<int>, greater<int> > pq;

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    rep(i, 0, n - 1){
        cin >> a[i];
        pq.push(a[i]);
    }
    //debug(pq.top());
    //sort(a, a + n);
    vi ans;
    int minN = pq.top(); pq.pop();
    vi fr, bk;
    bool turn = 0;
    while(pq.size()){
        if(turn){
            bk.pb(pq.top());
        }else{
            fr.pb(pq.top());
        }
        pq.pop();
        turn = !turn;
    }
    reverse(fr.begin(), fr.end());
    rep(i, 0, (int)fr.size() - 1){
        ans.pb(fr[i]);
    }
    ans.pb(minN);
    rep(i, 0, (int)bk.size() - 1){
        ans.pb(bk[i]);
    }
    bool flag = 1;
    rep(i, 0, n - 3){
        if(ans[i] + ans[i + 2] <= ans[i + 1]){
            flag = 0;
            break;
        }
    }
    if(ans[0] + ans[n - 2] <= ans[n - 1]) flag = 0;
    if(ans[1] + ans[n - 1] <= ans[0]) flag = 0;
    if(flag){
        cout << "YES" << endl;
        debuga1(ans, 0, n - 1);
    }else{
        cout << "NO";
    }
    /*rep(i, 3, n - 1){
        d.push_back(a[i]);
    }
    rep(i, 0, n - 1 - 3){
        if(i % 2 == 0){
            ans.push_back(d.back());
            d.pop_back();
        }else{
            ans.push_back(d.front());
            d.pop_front();
        }
    }
    bool flag = 1;
    rep(i, 0, n - 3){
        if(ans[i] + ans[i + 2] <= ans[i + 1]){
            flag = 0;
            break;
        }
    }
    if(ans[0] + ans[n - 2] <= ans[n - 1]) flag = 0;
    if(flag){
        cout << "YES" << endl;
        debuga1(ans, 0, n - 1);
    }else{
        cout << "NO";
    }*/

    return 0;
}
