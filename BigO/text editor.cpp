//http://www.bigocoder.com/courses/ORANGE01/ORANGE01_LEC14/ORANGE_L14P02/statement
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
string s, t;
int k;
int cnt[N], prefix[N];

void generatePrefix(){
    int i = 1, j = 0, n = (int)t.length();
    while(i < n){
        //debug(i);
        if(t[i] == t[j]){
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

void cntSubString(){
    int i, j; i = j = 0;
    int n = (int)s.length(), m = t.length();
    while(i < n){
        if(s[i] == t[j]){
            cnt[j]++;
            i++;
            j++;
        }
        if(j == m){
            j = prefix[j - 1];
        }
        if(i < n && s[i] != t[j]){
            if(j == 0){
                i++;
            }else{
                j = prefix[j - 1];
            }
        }
    }
    int ind = -1;
    rrep(i, m - 1, 1){
        cnt[i - 1] += cnt[i];
    }
    rep(i, 0, m - 1){
        if(cnt[i] >= k){
            ind = i;
        }
    }
    //debuga1(cnt, 0, m - 1);
    if(ind == -1){
        cout << "IMPOSSIBLE";
        return;
    }
    rep(i, 0, ind){
        cout << t[i];
    }
}

string removeSpace(string s){
    string temp = "", subS = "";
    int ind = 0;
    int n = s.length();
    while(ind < n){
        while(ind < n && s[ind] != ' '){
            subS += s[ind];
            ind++;
        }
        temp += subS;
        subS = "";
        ind++;
    }
    return temp;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    getline(cin, s);
    getline(cin, t);
    s = removeSpace(s);
    t = removeSpace(t);
    //debug(s); debug(t);
    cin >> k;
    mem(cnt, 0);
    mem(prefix, 0);
    generatePrefix();
    //Flag(1);
    cntSubString();
    return 0;
}

