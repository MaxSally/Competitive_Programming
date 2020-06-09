//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=615&page=show_problem&problem=2162
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

const int N = 0;
char square[105][105];

bool isPalindrome(string s){
    int left = 0, right = (int)s.length() - 1;
    while(left <= right){
        if(s[left] != s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int test; cin >> test;
    string s;
    getline(cin, s);
    rep(ii, 1, test){
        cout << "Case #" << ii << ":" << endl;
        getline(cin, s);
        string t = "";
        for(char c: s){
            if(isalpha(c)){
                t += tolower(c);
            }
        }
        s = t;
        int n = (int)s.length();
        int sqrtN = (int)sqrt(n);
        if(sqrtN * sqrtN != n){
            cout << "No magic :(" << endl;
            continue;
        }
        rep(i, 0, n - 1){
            int x = i/sqrtN;
            int y = i % sqrtN;
            square[x][y] = s[i];
        }
        /*rep(i, 0, sqrtN - 1){
            rep(j, 0, sqrtN - 1){
                cout << square[i][j] << " ";
            }
            cout << endl;
        }*/
        if(!isPalindrome(s)){
            cout << "No magic :(" << endl;
            //Flag(0);
            continue;
        }
        s = "";
        rep(i, 0, sqrtN - 1){
            rep(j, 0, sqrtN  - 1){
                s += square[j][i];
            }
        }
        //debug(s);
        if(!isPalindrome(s)){
            Flag(0);
            cout << "No magic :(" << endl;
            continue;
        }
        s = "";
        rrep(i, sqrtN - 1, 0){
            rrep(j, sqrtN  - 1, 0){
                s += square[j][i];
            }
        }
        if(!isPalindrome(s)){
            cout << "No magic :(" << endl;
            continue;
        }
        s = "";
        rrep(i, sqrtN - 1, 0){
            rrep(j, sqrtN  - 1, 0){
                s += square[i][j];
            }
        }
        if(!isPalindrome(s)){
            cout << "No magic :(" << endl;
            continue;
        }
        cout << sqrtN << endl;

    }
    return 0;
}

