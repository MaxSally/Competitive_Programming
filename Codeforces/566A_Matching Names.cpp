//https://codeforces.com/problemset/problem/566/A
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

const int N = 100005;
const int K = 26;

struct Vertex{
    int next[K];
    vii leaf; // color 1 = blue 2 = red
    Vertex(){
        fill(next, next + K, -1);
    }
};

vector<Vertex> trie;
vii ans;
string a[N], b[N];

void insertString(string s, int turn, int color){
    int v = 0;
    foreach(u, s){
        int c = u - 'a';
        if(trie[v].next[c] == -1){
            trie[v].next[c] = (int)trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].leaf.pb(mp(turn, color));
}

vvi findLongestCommonString(int v){
    vvi res;
    res.resize(2);
    foreach(u, trie[v].leaf){
        if(u.ss == 1){
            res[0].pb(u.ff);
        }else{
            res[1].pb(u.ff);
        }
    }
    rep(i, 0, 25){
        if(trie[v].next[i] != -1){
            vvi temp = findLongestCommonString(trie[v].next[i]);
            rep(j, 0, 1){
                foreach(u, temp[j]){
                    res[j].pb(u);
                }
            }
        }
    }
    int i = 0;
    while(i < (int)res[0].size() && i < (int)res[1].size()){
        ans.pb(mp(res[0][i], res[1][i]));
        i++;
    }
    vvi temp;
    temp.resize(2);
    int ini = i;
    rep(j, 0, 1){
        i = ini;
        while(i < (int)res[j].size()){
            temp[j].pb(res[j][i]);
            i++;
        }
    }
    return temp;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    ll sum = 0;
    trie.emplace_back();
    rep(i, 0, n - 1){
        cin >> a[i];
        insertString(a[i], i, 1);
        //sum += a[i].length();
    }
    rep(i, 0, n - 1){
        cin >> b[i];
        insertString(b[i], i, 2);
        //sum += b[i].length();
    }
    vvi temp = findLongestCommonString(0);
    foreach(v, ans){
        int i = 0;
        string x = a[v.ff], y = b[v.ss];
        while(i < min(x.length(), y.length()) && (x[i] == y[i])){
            i++;
        }
        sum += i;
    }
    cout << sum << endl;
    foreach(v, ans){
        cout << v.ff + 1 << " " << v.ss + 1<< endl;
    }
    return 0;
}
