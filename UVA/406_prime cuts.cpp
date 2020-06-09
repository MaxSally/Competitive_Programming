//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=347
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

const int N = 1000005;
vi prime;
bool mark[N];

void sieve(){
    fill(mark, mark + N, 1);
    mark[0] = mark[1] = 0;
    prime.pb(1);
    for(int i = 2; i * i <= N; i++){
        if(!mark[i]) continue;
        prime.pb(i);
        for(int j = i * i; j <= N; j += i){
            mark[j] = 0;
        }
    }
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int n, c;
    sieve();
    bool flag = 0;
    while(cin >> n){
        if(flag) cout << '\n';
        flag = 1;
        cin >> c;
        vi::iterator it;
        it = upper_bound(prime.begin(), prime.end(), n);
        int ind = it - prime.begin();
        ind--;
        //debug(ind);
        int mid = (ind + 1)/2;
        cout << n << " " << c << ": ";
        /*if(ind & 1){
            rep(i, max(0, mid - c), min(ind, mid + c - 1)){
                cout << prime[i] << " ";
            }
        }else{
            rep(i, max(0, mid - c + 1), min(ind, mid + c - 1)){
                cout << prime[i] << " ";
            }
        }*/
        bool turn = 0;
        rep(i, max(0, mid - c + ((ind + 1) & 1)), min(ind, mid + c - 1)){
            if(turn) cout << " ";
            turn = 1;
            cout << prime[i];
        }
        cout << '\n';
    }
    return 0;
}
