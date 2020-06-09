//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=614&page=show_problem&problem=525
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

struct triad{
    int a, b, c;
};


int main(){
    io
    freopen("bowling.txt","r",stdin);
    //freopen("input.txt","r",stdin);
    string s;
    while(getline(cin, s)){
        if(s == "Game Over") break;
        int pos = 0;
        vector<triad> game;
        rep(i, 1, 10){
            triad frame;
            frame.a = frame.b = frame.c = 0;
            if(i < 10){
                rep(j, 1, 2){
                    if(s[pos] == 'X'){
                        game.pb({11, -1, -1});
                        pos += 2;
                        break;
                    }else if(s[pos] == '/'){
                        frame.b = 10;
                        game.pb(frame);
                    }else{
                        if(j == 1){
                            frame.a = s[pos] - '0';
                        }else{
                            frame.b = s[pos] - '0';
                            game.pb(frame);
                        }

                    }
                    pos += 2;
                }
            }else{
                rep(j, 1, 3){
                    if(s[pos] == 'X'){
                        if(j == 1){
                            frame.a = 10;
                        }else if(j == 2){
                            frame.b = 10;
                        }else{
                            frame.c = 10;
                            game.pb(frame);
                        }
                        pos += 2;
                    }else if(s[pos] == '/'){
                        if(j == 2){
                            frame.b = 10;
                            pos += 2;
                        }else{
                            frame.c = 10;
                            game.pb(frame);
                        }

                    }else{
                        if(j == 1){
                            frame.a = s[pos] - '0';
                        }else if(j == 2){
                            frame.b = s[pos] - '0';
                            if(frame.a != 10){
                                game.pb(frame);
                                break;
                            }
                        }else{
                            frame.c = s[pos] - '0';
                            game.pb(frame);
                        }
                        pos += 2;
                    }
                }
            }
        }
        /*rep(i, 0, 9){
            cout << game[i].a << " " << game[i].b << " " << game[i].c << endl;
        }
        cout << endl;*/
        int point = 0;
        rep(i, 0, 8){
            triad frame = game[i];
            if(frame.a == 11){
                point += 10;
                if(game[i + 1].a == 11){
                    point += 10 + min(10, game[i + 2].a);
                }else{
                    if(i == 8 && game[i + 1].a == 10){
                        point += 10 + game[i + 1].b;
                    }else{
                        point += min(10, game[i + 1].a + game[i + 1].b);
                    }

                }
            }else{
                if(frame.b == 10){
                    point += 10 + min(10, game[i + 1].a);
                }else{
                    point += frame.a + frame.b;
                }
            }
            //debug(point);
        }
        triad frame = game[9];
        if(frame.a == 10){
            point += 10;
            if(frame.b == 10){
                point += 10 + frame.c;
            }else{
                point += min(10, frame.b + frame.c);
            }
        }else{
            point += min(10, frame.a + frame.b) + frame.c;
        }
        cout << point << endl;
    }
    return 0;
}
