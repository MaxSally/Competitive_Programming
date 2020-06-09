//https://codeforces.com/problemset/problem/1153/E
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

const int N = 100;
vi point;
int n;

bool query(int x1, int y1, int x2, int y2){
    printf("? %d %d %d %d\n", x1, y1, x2, y2);
    fflush(stdout);
    int ans; cin >> ans;
    return (ans & 1);
}

void binarySearch(int x, bool type){
    int l = 1, r = n;
    while(l < r){
        int mid = (l + r)/2;
        if(type){
            if(query(x, l, x, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }else{
            if(query(l, x, mid, x)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
    }
    if(type){
        point.pb(x);
        point.pb(l);
    }else{
        point.pb(l);
        point.pb(x);
    }
}

int main(){
    //io;
    //freopen("input.txt", "r", stdin);
    cin >> n;
    int i = 1;
    for(; i < n; i++){
        if(query(1, 1, n, i)){
            break;
        }
    }
    if(i == n){
        for(i = 1; i < n; i++){
            if(query(1, 1, i, n)){
                binarySearch(i, 1);
                break;
            }
        }
        rrep(j, n, i + 2){
            if(query(j, 1, n, n)){
                binarySearch(j, 1);
                break;
            }
        }
        if((int)point.size() == 2){
            binarySearch(i + 1, 1);
        }
    }else{
        binarySearch(i, 0);
        rrep(j, n, i + 2){
            if(query(1, j, n, n)){
                binarySearch(j, 0);
                break;
            }
        }
        if((int)point.size() == 2){
            binarySearch(i + 1, 0);
        }
    }
    printf("! ");
    foreach(u, point){
        printf("%d ", u);
    }
    printf("\n");
    fflush(stdout);
    return 0;
}
