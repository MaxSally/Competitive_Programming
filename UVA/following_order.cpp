//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=60
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

const int N = 30;
bool visited[N];
vi graph[N];
int level[N];
string t, subAns;
vector<string> ans;
int n;

void backTracking(int pos){
    if(pos == n){
        ans.pb(subAns);
        return;
    }
    rep(i, 0, n - 1){
        int c = t[i] - 'a';
        if(visited[i] || level[c] != 0) continue;
        visited[i] = 1;
        for(int j: graph[c]){
            level[j]--;
        }
        subAns.pb(t[i]);
        backTracking(pos + 1);
        visited[i] = 0;
        for(int j: graph[c]){
            level[j]++;
        }
        subAns.pop_back();
    }
}

int main(){
    io
    freopen("input.txt","r",stdin);
    string s;
    bool flag = 0;
    while(getline(cin, s)){
        if(flag) cout << endl;
        flag = 1;
        t = "";
        mem(level, 0);
        mem(visited, 0);
        rep(i, 0, 29) graph[i].clear();
        subAns = "";
        ans.clear();
        n = 0;
        for(int i = 0; i < s.length(); i += 2){
            t += s[i];
            n++;
        }
        //debug(t);
        getline(cin, s);
        for(int i = 0; i < s.length(); i += 4){
            int x = s[i] - 'a', y = s[i + 2] - 'a';
            graph[x].pb(y);
            level[y]++;
        }
        backTracking(0);
        sort(ans.begin(), ans.end());
        for(string a: ans){
            cout << a << endl;
        }
    }
    return 0;
}

