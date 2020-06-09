//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=623&page=show_problem&problem=696
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
int letter[30];

int main(){
    io
    freopen("input.txt","r",stdin);
    mem(letter, 0);
    int cur = 2, freq = 3;
    rep(i, 0, 25){
        if(i == 16 || i == 25) continue;
        letter[i] = cur;
        freq--;
        if(freq == 0){
            freq = 3;
            cur++;
        }
    }
    int t; cin >> t;
    rep(ii, 1, t){
        if(ii > 1) cout << endl;
        int n; cin >> n;
        string s;
        map<string,int> phoneBook;
        map<string,int>::iterator it;
        rep(i, 1, n){
            cin >> s;
            string number = "";
            rep(j, 0, (int)s.length() - 1){
                if(s[j] == '-')continue;
                if(isdigit(s[j])){
                    number += s[j];
                }else{
                    number += (char)(letter[s[j] - 'A'] + '0');
                }
            }
            if(phoneBook.find(number) != phoneBook.end()){
                phoneBook[number]++;
            }else{
                phoneBook[number] = 1;
            }
        }
        bool flag = 1;
        for(it = phoneBook.begin(); it != phoneBook.end(); it++){
            if(it->second > 1){
                flag = 0;
                string temp = it->first;
                temp.insert(3, "-");
                cout << temp << " " << it->second << endl;
            }
        }
        if(flag){
            cout << "No duplicates." << endl;
        }
    }

    return 0;
}

