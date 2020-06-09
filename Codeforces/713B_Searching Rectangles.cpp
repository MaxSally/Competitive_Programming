//https://codeforces.com/problemset/problem/713/B
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

const int N = (1 << 16);
vi movement, s, S(4), res;

struct rectangle{
    int x1, y1, x2, y2;
};

int n;

void binarySearch(int left, int right, int found){
    while(left < right){
        int mid = (left + right)/2;
        rep(i, 0, 3){
            S[i] = s[i] + movement[i] * mid;
        }
        printf("? %d %d %d %d\n", S[0], S[1], S[2], S[3]);
        fflush(stdout);
        int ans; cin >> ans;
        if(found > 0){
            if(res[0] >= S[0] && res[1] >= S[1] && res[2] <= S[2] && res[3] <= S[3]){
                ans -= found;
            }
        }
        if(ans > 0){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    rep(i, 0, 3){
        s[i] += movement[i] * right;
    }
}


int main(){
    //io;
    //freopen("input.txt", "r", stdin);
    cin >> n;
    rep(i, 0, 1){
        s = {1, 1, n, 1};
        movement = {0, 0, 0, 1};
        binarySearch(0, n, i);
        s[1] = s[3];
        movement = {0, -1, 0, 0};
        binarySearch(0, s[1], i);
        s[2] = 1;
        movement = {0, 0, 1, 0};
        binarySearch(0, n, i);
        s[0] = s[2];
        movement = {-1, 0, 0, 0};
        binarySearch(0, s[0], i);
        res.insert(res.end(), s.begin(), s.end());
    }
    printf("!");
    foreach(u, res){
        printf(" %d", u);
    }
    printf("\n");
    fflush(stdout);
    return 0;
}

