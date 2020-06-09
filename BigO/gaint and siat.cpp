//http://www.bigocoder.com/courses/ORANGE01/ORANGE01_LEC14/ORANGE_L14P01/statement
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
int prefix[N];

void generatePrefix(){
    int n = (int) t.length();
    int i = 1, j = 0;
    prefix[0] = 0;
    while(i < n){
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

int cntSubString(){
    int i, j; i = j = 0;
    int n = (int)s.length(), m = (int)t.length();
    int cnt = 0;
    while(i < n){
        if(s[i] == ' '){
            i++;
            continue;
        }
        //debug(i); debug(j);
        if(s[i] == t[j]){
            j++;
            i++;
        }
        if(j == m){
            //debug(i);
            cnt++;
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
    return cnt;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int test; cin >> test;
    getline(cin , s);
    rep(ii, 1, test){
        mem(prefix, 0);
        getline(cin, s);
        getline(cin, t);
        string temp = "", subS = "";
        int ind = 0;
        while(ind < (int)s.length()){
            while(ind < (int)s.length() && s[ind] != ' '){
                subS += s[ind];
                ind++;
            }
            temp.append(subS);
            ind++;
            subS = "";
        }
        s = temp;
        //debug(s); debug(t);
        generatePrefix();
        //debuga1(prefix, 0, (int)t.length());
        cout << "Case " << ii << ": " << cntSubString() << endl;
    }

    return 0;
}

