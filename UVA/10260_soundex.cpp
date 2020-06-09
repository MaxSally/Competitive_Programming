//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=623&page=show_problem&problem=1201
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
int soundex[N];

int main(){
    io
    freopen("input.txt","r",stdin);
    rep(i, 1, 26){
        if(i == 2 || i == 6 || i == 16 || i == 22){
            soundex[i] = 1;
        }else if(i == 3 || i == 7 || i == 10 || i == 11 || i == 17 || i == 19 || i == 24 || i == 26){
            soundex[i] = 2;
        }else if(i == 4 || i == 20){
            soundex[i] = 3;
        }else if(i == 12){
            soundex[i] = 4;
        }else if(i == 13 || i == 14){
            soundex[i] = 5;
        }else if(i == 18){
            soundex[i] = 6;
        }else{
            soundex[i] = 0;
        }
    }
    string s;
    while(getline(cin, s)){
        //mem(check, 0);
        //check[0] = 1;
        string ans = "";
        int pre = -1;
        rep(i, 0, (int)s.length() - 1){
            int a = s[i] - 'A' + 1;
            if(soundex[a] == 0){
                pre = -1;
                continue;
            }
            if(pre == soundex[a]) continue;
            char c = (char)(soundex[a] + '0');
            ans += c;
            pre = soundex[a];
        }
        cout << ans << endl;
    }
    return 0;
}

