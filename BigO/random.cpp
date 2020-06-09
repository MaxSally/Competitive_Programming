//http://www.bigocoder.com/courses/ORANGE01/ORANGE01_LEC14/ORANGE_L14P04/statement
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
#define inf (int) (1e9 + 9)
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

const int N = 1000005;
int prefix[N], suffix[N];

void generatePrefix(string s){
    int i = 1, j = 0, n = (int)s.length();
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

int findPreSuf(string t, string s, int minL){
    int cnt = 0;
    int n = (int)s.length();
    int m = (int)t.length();
    const int p = 263;
    vector<long long> pow(max(n,m));
    pow[0] = 1;
    rep(i, 1, n - 1){
        pow[i] = (pow[i - 1] * p) % mod;
    }
    vector<ll> h(n + 1, 0), h1(m + 1, 0);
    rep(i, 0, n - 1){
        h[i + 1] = (h[i] + s[i] * pow[i]) % mod;
    }
    rep(i, 0, m - 1){
        h1[i + 1] = (h1[i] + t[i] * pow[i]) % mod;
    }
    rrep(i, n - 1, minL + 1){
        ll curSuf = (h[n] + mod - h[n - i]) % mod;
        curSuf = (curSuf * pow[i - 1]) % mod;

        ll curPre = (h[i] + mod - h[0]) % mod;
        curPre = (curPre * pow[n - 1]) % mod;

        if(curSuf == curPre){
            ll tPre = (h1[i] + mod - h1[0]) % mod;
            tPre = (tPre * pow[n - 1]) % mod;
            if(curPre == tPre){
                return i;
            }
        }
    }
    return -1;
}


void solveObelisk(string s){
    int ans = inf;
    int n = (int) s.length();
    int ind = 1;
    rep(i, 0, n - 1){
        if(prefix[i] == 1){
            ind = i;
        }
    }
    int value = prefix[n - 1];
    if(value != 0 && (value % ind) == 0){
        rep(i, ind, n - 1 - ind){
            cout << s[i];
        }
        return;
    }else{
        int temp = 0, temp1 = 0;
        int upper = n - 1;
        while(upper >= 0 && prefix[upper] > 0){
            upper--;
        }
        rep(i, 1, upper){
            temp = max(temp, prefix[i]);
        }
        temp = min(temp, value);

        string s2 = s.substr(upper + 1, n - upper);
        //debug(s2);
        temp1 = findPreSuf(s, s2, temp);
        //debug(temp1);
        if(temp1 != -1){
            temp = temp1;
        }
        string s1 = s.substr(0, temp);
        s2 = s.substr(n - temp, temp);
        if(s1 != s2){
            ans = 0;
        }else{
            ans = temp;
        }
        if(ans == 0){
            /*if(s[0] == 'k'){
                s2 = s.substr(upper + 1, n - upper);
                s2.erase(s2.begin());
                //cout << s2;
                debug((int)s2.length());
                debug(upper);
                return;
            }*/
            cout << "Just a legend";
            return;
        }
        rep(i, 0, ans - 1){
            cout << s[i];
        }
        return;
    }
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    mem(prefix, 0);
    string s;
    cin >> s;
    generatePrefix(s);
    int n = (int) s.length();
    //debuga1(prefix, 1, n - 1);
    solveObelisk(s);
    return 0;
}
