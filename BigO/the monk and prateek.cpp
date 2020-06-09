//http://bigocoder.com/courses/ORANGE01/ORANGE01_LEC09/ORANGE_L09P01/statement
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

const int N = 20000005;

struct Node{
    int key, cnt;
};

Node hashTable[N];
int current_size = 0;

unsigned int polyHash(string keys){
    unsigned int hashValue = 0;
    unsigned int a = 37;
    rep(i, 0, (int)keys.size() - 1){
        hashValue = (keys[i] + a * hashValue);
    }
    return hashValue & 0x7FFFFFFF;
}

int prateekHash(int a){
    int sumDigi = 0, iniA = a;
    while(a > 0){
        sumDigi += (a % 10);
        a /= 10;
    }
    return (iniA ^ sumDigi);
}

void insertKey(int keys){
    int index = prateekHash(keys);
    if(hashTable[index].cnt == 0){
        hashTable[index].cnt = 1;
        hashTable[index].key = keys;
    }else{
        hashTable[index].cnt++;
    }
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    // hashTable = new Node[N];
    int n;
    cin >> n;
    rep(i, 1, n){
        int x; cin >> x;
        insertKey(x);
    }
    int numberCollision = 0, maxN = 0, minN = inf, maxCnt = 0;
    for(Node a: hashTable){
        if(a.cnt == 0)continue;
        if(maxCnt < a.cnt){
            maxCnt = a.cnt;
            minN =  prateekHash(a.key);
        }else if(maxCnt == a.cnt){
            maxN = max(maxN, prateekHash(a.key));
            minN = min(minN, prateekHash(a.key));
            //debug(prateekHash(a.key));
            //debug(a.key);
        }
        if(a.cnt > 1) numberCollision += a.cnt - 1;
    }
    if(maxCnt == 1){
        cout << maxN << " " << numberCollision;
    }else{
        cout << minN << " " << numberCollision;
    }
    return 0;
}

