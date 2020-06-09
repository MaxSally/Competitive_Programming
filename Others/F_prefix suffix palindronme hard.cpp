//https://vjudge.net/contest/363384#problem/F
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

const int N = 2000005;
int prefix[N];

void generatePrefix(string s){
    int i = 1, j = 0;
    int n = (int)s.length();
    while(i < n){
        if(s[i] == s[j]){
            j++;
            prefix[i] = j;
            i++;
        }else{
            if(j == 0){
                prefix[i] = 0;
                i++;
            }else{
                j = prefix[j - 1];
            }
        }
    }
}

string check(string s){
    int n = s.length();
    string t;
    fill(prefix, prefix + n + 1, 0);
    generatePrefix(s);
    t = s.substr(0, prefix[n - 1]);
    return t;
}


int main(){
    io;
    freopen("input.txt", "r", stdin);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.length();
        int ind = 0;
        while(s[ind] == s[n - 1 - ind] && ind <= n/2){
            ind++;
        }
        if(ind > n/2){
            cout << s << '\n';
            continue;
        }
        string t = s.substr(ind, n - ind * 2);
        reverse(all(t));
        string t1 = t;
        reverse(all(t));
        string checkStr = t + "#" + t1;
        string res = check(checkStr);
        checkStr = t1 + "#" + t;
        string res1 = check(checkStr);
        string head = s.substr(0, ind);
        reverse(all(head));
        string tail = head;
        reverse(all(head));
        cout << head + (res.length() > res1.length()? res: res1) + tail << '\n';
    }
    return 0;
}
