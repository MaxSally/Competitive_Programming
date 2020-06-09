//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=623&page=show_problem&problem=3778
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
int s, b;
pii soldier[N];

int findSetLeft(int a){
    if(a == 0) return 0;
    return(soldier[a].first == a - 1? a - 1: soldier[a].first = findSetLeft(soldier[a].first));
}

int findSetRight(int a){
    if(a == s + 1) return a;
    return(soldier[a].second == a + 1? a + 1: soldier[a].second = findSetLeft(soldier[a].second));
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    while(true){
        cin >> s >> b;
        if(s == 0 && b == 0){
            return 0;
        }
        rep(i, 1, s){
            soldier[i].first = i - 1;
            soldier[i].second = i + 1;
        }
        while(b--){
            int left, right; cin >> left >> right;
            int lastLeft = soldier[left].first;
            int lastRight = soldier[right].second;
            rep(i, left, right){
                soldier[i].first = lastLeft;
                soldier[i].second = lastRight;
            }
            soldier[lastLeft].second = lastRight;
            soldier[lastRight].first = lastLeft;
            if(lastLeft == 0){
                cout << "* ";
            }else{
                cout << lastLeft << " ";
            }
            if(lastRight == s + 1){
                cout <<  "*" << endl;
            }else{
                cout << lastRight << endl;
            }
            /*Flag(0);
            rep(i, 1, s){
                cout << soldier[i].first << " " << soldier[i].second << endl;
            }
            Flag(1);*/
        }
        cout << '-' << endl;
    }
    return 0;
}
