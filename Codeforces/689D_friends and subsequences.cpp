//https://codeforces.com/contest/689/problem/D
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

const int N = 200005;
int n, a[N], b[N];

void createSparseTable(vector<vector<int> > &sparseTable, bool state){ //state true = max;
    int column = n;
    int row = (int) log2(n);
    rep(i, 1, row){
        column -= (1 << (i - 1));
        sparseTable[i].resize(column);
        rep(j, 0, column - 1){
            if(state)
                sparseTable[i][j] = max(sparseTable[i - 1][j], sparseTable[i - 1][j + (1 << (i - 1))]);
            else
                sparseTable[i][j] = min(sparseTable[i - 1][j], sparseTable[i - 1][j + (1 << (i - 1))]);
        }
    }
    /*column = n;
    rep(i, 0, row){
        rep(j, 0, column - 1){
            cout << sparseTable[i][j] << " ";
        }
        column -= (1 << i);
        cout << endl;
    }*/
}

ll binarySearch(int leftInital, int rightInitial, vvi &sparseTableA, vvi &sparseTableB){
    ll p1, p2; p1 = p2 = -1;
    int left = leftInital, right = rightInitial;
    while(left <= right){ //upper bound
        int mid = (right + left)/2;
        int k = (int)log2(mid - leftInital + 1);
        int maxN = max(sparseTableA[k][leftInital], sparseTableA[k][mid - (1 << k) + 1]);
        int minN = min(sparseTableB[k][leftInital], sparseTableB[k][mid - (1 << k) + 1]);
        if(maxN >= minN){
            right = mid - 1;
            p1 = mid;
        }else{
            left = mid + 1;
        }
    }
    if(p1 == -1) return 0;
    left = leftInital; right = rightInitial;
    while(left <= right){
        int mid = (right + left)/2;
        int k = (int)log2(mid - leftInital + 1);
        int maxN = max(sparseTableA[k][leftInital], sparseTableA[k][mid - (1 << k) + 1]);
        int minN = min(sparseTableB[k][leftInital], sparseTableB[k][mid - (1 << k) + 1]);
        if(maxN <= minN){
            left = mid + 1;
            p2 = mid;
        }else{
            right = mid - 1;
        }
    }
    if(p2 == -1) return 0;
    //debug(p1);
    //debug(p2);
    return p2 - p1 + 1;
}

int main(){
    io
    freopen("input.txt","r",stdin);
    mem(a, 0);
    mem(b, 0);
    cin >> n;
    rep(i, 0, n - 1){
        cin >> a[i];
    }
    rep(i, 0, n - 1){
        cin >> b[i];
    }
    vvi sparseTableA(n, vector<int>()), sparseTableB(n, vector<int>());
    sparseTableA[0].resize(n);
    sparseTableB[0].resize(n);
    rep(i, 0, n - 1){
        sparseTableA[0][i] = a[i];
        sparseTableB[0][i] = b[i];
    }
    createSparseTable(sparseTableA, 1);
    createSparseTable(sparseTableB, 0);
    ll ans = 0LL;
    rep(i, 0, n - 1){
        ans += binarySearch(i, n - 1, sparseTableA, sparseTableB);
    }
    cout << ans;
    return 0;
}

