//https://codeforces.com/contest/1181/problem/B
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

string addS(string s, string t){
    int n = s.length();
    int m = t.length();
    if(n > m){
        swap(n, m);
        swap(s, t);
    }

    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    while(n < m){
        s += "0";
        n++;
    }
    string ans = "";
    int remember = 0;
    rep(i, 0, n - 1){
        int a = s[i] - '0';
        int b = t[i] - '0';
        int c = a + b + remember;
        remember = 0;
        if(c >= 10){
            remember = 1;
            c -= 10;
        }
        ans += to_string(c);
    }
    if(remember == 1){
        ans += "1";
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string min(string a, string b){
    if(a.length() < b.length()){
        return a;
    }else if(a.length() > b.length()){
        return b;
    }
    rep(i, 0, (int)a.length() - 1){
        if(a[i] < b[i]) return a;
        if(a[i] > b[i]) return b;
    }
    return a;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    string s; cin >> s;
    int mid = n/2;
    int left, right; left = right = mid;
    while(left >= 0 && s[left] == '0'){
        left--;
    }
    while(right < n && s[right] == '0'){
        right++;
    }
    int a = mid - left;
    int b = right - mid;
    string ans;
    if(a < b){
        string x, y;
        string s1, s2; x = y = s1 = s2 = "";
        int ind = 0;
        while(ind <= left - 1){
            x += s[ind]; ind++;
        }
        while(ind <= n - 1){
            y += s[ind]; ind++;
        }
        s1 = addS(x, y);
        if(s[left + 1] != '0'){
            x += s[left];
            y.erase(y.begin());
            s2 = addS(x, y);
        }
        if(s2 == ""){
            ans = s1;
        }else{
            ans = min(s1, s2);
        }
    }else if(a > b){
        string x, y;
        string s1, s2; x = y = s1 = s2 = "";
        int ind = 0;
        while(ind <= right - 1){
            x += s[ind]; ind++;
        }
        while(ind <= n - 1){
            y += s[ind]; ind++;
        }
        s1 = addS(x, y);
        x += s[right];
        y.erase(y.begin());
        s2 = addS(x, y);
        ans = min(s1, s2);
    }else{
        string x, y;
        string s1, s2; x = y = s1 = s2 = "";
        int ind = 0;
        while(ind <= left - 1){
            x += s[ind]; ind++;
        }
        while(ind <= n - 1){
            y += s[ind]; ind++;
        }
        s1 = addS(x, y);
        if(s[left + 1] != '0'){
            x += s[left];
            y.erase(y.begin());
            //debug(x); debug(y);
            s2 = addS(x, y);
        }
        if(s2 == ""){
            ans = s1;
        }else{
            ans = min(s1, s2);
        }
        //debug(ans);
        //debug(s1); debug(s2);
        x.clear();
        x = y = "";
        ind = 0;
        while(ind <= right - 1){
            x += s[ind]; ind++;
        }
        while(ind <= n - 1){
            y += s[ind]; ind++;
        }
        s1 = addS(x, y);
        x += s[right];
        y.erase(y.begin());
        s2 = addS(x, y);
        ans = min(ans, min(s1, s2));
    }
    cout << ans;
    return 0;
}
