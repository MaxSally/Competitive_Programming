//
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

const int N = 0;
char lst[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e'};

int main(){
    io;
    freopen("input.txt", "r", stdin);
    string s;
    int i = 0, j = 0, k = 0;
    while(cin >> s){
        cout << lst[i] << lst[j] << lst[k] << ": ";
        k++;
        if(k == 16){
            k = 0;
            j++;
            if(j == 16){
                j = 0;
                i++;
            }
        }
        string t = s.substr(1, 3);
        if(s[0] == 'a'){
            cout << "Clear\n";
            continue;
        }else if(s[0] == '5'){
            cout << "Input\n";
        }else if(s[0] == '6'){
            cout << "Output\n";
        }else if(s[0] == '7'){
            cout << "Halt\n";
        }else if(s[0] == '1'){
            cout << "Load " << t << "\n";
        }else if(s[0] == '2'){
            cout << "Store " << t << "\n";
        }else if(s[0] == '3'){
            cout << "Add " << t << "\n";
        }else if(s[0] == '4'){
            cout << "Subt " << t << "\n";
        }else if(s[0] == '8'){
            cout << "Skipcond " << t << "\n";
        }else if(s[0] == '9'){
            cout << "Jump " << t << "\n";
        }else if(s[0] == '0'){
            cout << "HEX " << s << "\n";
        }else if(s[0] == 'b'){
            cout << "AddI " << t << "\n";
        }else if(s[0] == 'c'){
            cout << "JumpI " << t << "\n";
        }else if(s[0] == 'e'){
            cout << "StoreI\n";
        }else if(s[0] == 'd'){
            cout << "LoadI\n";
        }else{
            cout << "ERROR " << t << "\n";
        }
    }
    return 0;
}

