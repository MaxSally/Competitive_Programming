//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=615&page=show_problem&problem=342
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
char mirrorA[21] = {'A', 'E', 'H', 'I', 'J', 'L', 'M', 'O', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '5', '8'};
char mirrorB[21] = {'A', '3', 'H', 'I', 'L', 'J', 'M', 'O', '2', 'T', 'U', 'V', 'W', 'X', 'Y', '5', '1', 'S', 'E', 'Z', '8'};

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

bool isMirror(string s){
    int left = 0, right = (int)s.length() - 1;
    while(left <= right){
        char a = s[left], b = s[right];
        bool flag = false;
        rep(i, 0, 20){
            if(mirrorA[i] == a && mirrorB[i] == b){
                flag = true;
            }
        }
        if(!flag){
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
    string s;
    while(getline(cin, s)){
        bool palin = isPalindrome(s);
        bool mirror = isMirror(s);
        cout << s;
        if(palin && mirror){
            cout << " -- is a mirrored palindrome." << endl << endl;
        }else if(palin && !mirror){
            cout << " -- is a regular palindrome." << endl << endl;
        }else if(!palin && mirror){
            cout << " -- is a mirrored string." << endl << endl;
        }else{
            cout << " -- is not a palindrome." << endl << endl;
        }
    }
    return 0;
}
