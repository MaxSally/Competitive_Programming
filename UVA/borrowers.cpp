//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=623&page=show_problem&problem=166
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
vector<pair<string, string> > book;
map<string, int> mpBook;
vector<bool> borrowB, returnB, inShelve;

int main(){
    io
    freopen("input.txt","r",stdin);
    string s;
    while(true){
        getline(cin, s);
        if(s == "END") break;
        int pos = 1;
        string t = "";
        t += '"';
        while(s[pos] != '"'){
            t += s[pos];
            pos++;
        }
        t += s[pos];
        pos += 5;
        string author = "";
        rep(i, pos, (int)s.length() - 1){
            author += s[i];
        }
        book.pb({author, t});
        //cout << t << " " << author << endl;
    }
    int n = (int)book.size();
    sort(book.begin(), book.end());
    rep(i, 0, book.size() - 1){
        //cout << book[i].first << " " << book[i].second << endl;
        mpBook.insert(pair<string,int>(book[i].second, i));
    }
    map<string, int>::iterator it;
    /*for(it = mpBook.begin(); it != mpBook.end(); it++){
        cout << it->first <<  " " << it->second << endl;
    }*/
    borrowB.assign(n, 0);
    returnB.assign(n, 0);
    inShelve.assign(n, 1);
    while(true){
        cin >> s;
        if(s == "END") break;
        if(s == "SHELVE"){
            //debuga1(returnB, 0, n - 1);
            //debuga1(inShelve, 0, n - 1);
            rep(i, 0, n - 1){
                if(returnB[i]){
                    returnB[i] = 0;
                    int pos = i - 1;
                    while(pos >= 0 && !inShelve[pos]){
                        pos--;
                    }
                    //debug(i);
                    //debug(pos);
                    if(pos == -1){
                        cout << "Put " << book[i].second << " first" << endl;
                    }else{
                        cout << "Put " << book[i].second << " after " << book[pos].second << endl;
                    }
                    inShelve[i] = 1;
                }
            }
            cout << "END" << endl;
        }else{
            string t;
            getline(cin, t);
            t.erase(0, 1);
            //cout << t << endl;
            int ind = mpBook[t];
            if(s == "BORROW"){
                borrowB[ind] = 1;
                inShelve[ind] = 0;
                returnB[ind] = 0;
            }else{
                borrowB[ind] = 0;
                returnB[ind] = 1;
            }
        }
    }
    return 0;
}

