//https://codeforces.com/contest/514/problem/D
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
int n, m, k, required[N][5];
vector<vector<vector<int> > > sparseTable;

void createSparseTable(){
    rep(ii, 0, m - 1){
        int row = (int)log2(n);
        int column = n;
        vector<vector<int> > tempSparse;
        tempSparse.resize(row + 1);
        tempSparse[0].resize(column);
        rep(i, 0, n - 1){
            tempSparse[0][i] = required[i][ii];
        }
        rep(i, 1, row){
            column -= (1 << (i - 1));
            tempSparse[i].resize(column);
            rep(j, 0, column - 1){
                tempSparse[i][j] = max(tempSparse[i - 1][j], tempSparse[i - 1][j + (1 << (i - 1))]);
            }
        }
        sparseTable.pb(tempSparse);
    }
}

void print(){
    rep(ii, 0, m - 1){
        rep(i, 0, sparseTable[ii].size() - 1){
            rep(j, 0, sparseTable[ii][i].size() - 1){
                cout << sparseTable[ii][i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}





int main(){
    io
    freopen("input.txt","r",stdin);
    cin >> n >> m >> k;
    rep(i, 0, n - 1){
        rep(j, 0, m - 1){
            cin >> required[i][j];
        }
    }
    createSparseTable();
    int left = 0, right = 0;
    int ansL = 0;
    int ansShot = 0;
    queue<int> q;
    while(right < n){
        //debug(left); debug(right);
        int totalShot = 0, tempL = right - left + 1;
        int length = log2(tempL);
        queue<int> tempQ;
        rep(ii, 0, m - 1){
            int temp = max(sparseTable[ii][length][left], sparseTable[ii][length][right - (1 << length) + 1]);
            totalShot += temp;
            tempQ.push(temp);
        }
        if(totalShot <= k){
            if(tempL > ansL){
                ansL = tempL;
                ansShot = totalShot;
                while(q.size()){
                    q.pop();
                }
                while(tempQ.size()){
                    q.push(tempQ.front());
                    tempQ.pop();
                }
            }
            right++;
        }else{
            left++;
            if(left > right){
                right = left;
            }
        }
    }
    //cout << ansShot << endl;
    if(q.empty()){
        rep(i, 0, m - 1){
            cout << "0 ";
        }
        return 0;
    }
    while(q.size()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
