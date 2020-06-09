//https://codeforces.com/problemset/problem/282/E
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
const int K = 2;
const int MAXLEN = 40;
int n, maxLen;
ll a[N], prefixSum[N], suffixSum[N];

struct Vertex{
    int next[K];
    bool leaf;

    Vertex(){
        fill(next, next + K, -1);
        leaf = 0;
    }
};

vector<Vertex> trie;

string convert(ll a){
    string s = "";
    while(a > 0){
        s += (a & 1LL) + '0';
        a >>= 1;
    }
    //reverse(all(s));
    while((int)s.length() < MAXLEN){
        s += "0";
    }
    reverse(all(s));
    return s;
}

ll turnBack(string s){
    reverse(all(s));
    ll a = 0;
    ll p = 1;
    foreach(u, s){
        if(u == '1'){
            a += p;
        }
        p *= 2;
    }
    return a;
}

void insertNumber(ll a){
    string s = convert(a);
    //debug(a); debug(s);
    int v = 0;
    foreach(u, s){
        int c = u - '0';
        if(trie[v].next[c] == -1){
            trie[v].next[c] = (int)trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].leaf = 1;
}

ll searchTrie(ll a){
    string s = convert(a);
    string t = "";
    int v = 0;
    foreach(u, s){
        int c = u - '0';
        if(c == 1){
            if(trie[v].next[0] != -1 || (trie[v].next[0] == -1 && trie[v].next[1] == -1)){
                t += "0";
                v = trie[v].next[0];
            }else{
                t += "1";
                v = trie[v].next[1];
            }
        }else{//c = 0;
            if(trie[v].next[1] != -1){
                t += "1";
                v = trie[v].next[1];
            }else{
                t += "0";
                v = trie[v].next[0];
            }
        }
        //debug(t);
    }
    //debug(t); debug(s); debug(a);
    string ans = "";
    int len = max(s.length(), t.length());
    rep(i, 0, len - 1){
        if(s[i] == t[i]){
            ans += "0";
        }else{
            ans += "1";
        }
    }
    return max(turnBack(ans), a);
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n;
    trie.emplace_back();
    maxLen = 0;
    a[0] = 0;
    rep(i, 1, n){
        cin >> a[i];
    }
    insertNumber(0);
    rep(i, 1, n){
        prefixSum[i] = prefixSum[i - 1] ^ a[i];
        insertNumber(prefixSum[i]);
    }
    suffixSum[n] = a[n];
    ll ans = searchTrie(suffixSum[n]);
    rrep(i, n - 1, 1){
        suffixSum[i] = suffixSum[i + 1] ^ a[i];
        ans = max(ans, searchTrie(suffixSum[i]));
    }
    ans = max(ans, searchTrie(0));
    cout << ans;
    return 0;
}
