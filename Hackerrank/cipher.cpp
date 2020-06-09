//https://www.hackerrank.com/challenges/cipher/problem
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

string cipher(int k, string s) {
    int n = (int) s.length() - k + 1;
    string t = "";
    queue<int> q;
    int next = -1, cnt1 = 0;
    for(int i = 0; i < n; i++){
        //cout << i << " " << next << endl;
        if(i == next){
            cnt1--;
            q.pop();
            if(q.size()){
                next = q.front();
            }else{
                next = -1;
            }
            //debug(next);
        }
        if(s[i] == '1'){
            if(cnt1 % 2){
                t += "0";
            }else{
                t += "1";
                if(next == -1){
                    next = i + k;
                }
                q.push(i + k);
                cnt1++;
            }
        }else{
            if(cnt1 % 2){
                t += "1";
                if(next == -1){
                    next = i + k;
                }
                q.push(i + k);
                cnt1++;
            }else{
                t += "0";
            }
        }
        //debug(cnt1);
        //debug(t);
    }
    return t;

}

int main(){
    io
    freopen("input.txt","r",stdin);
    int n, k; string s;
    cin >> n >> k >> s;
    cout << cipher(k, s);
    return 0;
}

