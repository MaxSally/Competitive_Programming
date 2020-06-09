//https://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&category=611&page=show_problem&problem=98
/*
* Author : MaxSally
*/
/********   All Required Header Files ********/
#include<bits/stdc++.h>
using namespace std;
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define LL long long
#define LD long double
#define vi vector<int>
#define vl vector<LL>
#define vs vector<string>
#define vb vector<bool>
#define ii pair<int, int>
#define vii vector<ii>
#define SET(v, i) (v | (1 << i))
#define TEST(v, i) (v & (1 << i))
#define TOGGLE(v, i) (v ^ (1 << i))

int main() {
    freopen("input.txt", "r", stdin);
  map<char, int> fcount;
  fcount['A'] = 4;
  fcount['K'] = 3;
  fcount['Q'] = 2;
  fcount['J'] = 1;
  while(true) {
    deque<char> p[2];
    string card;
    for (int i = 1; i <= 52; ++i) {
      cin >> card;
      if (card == "#")
        return 0;

      p[i % 2].push_front(card[1]);
    }

    deque<char> deck;
    int turn = 1;
    int last_face = -1;
    int cover_count = 0;
    while (true) {
      if (p[turn].empty())
        break;
      char card = p[turn].front();
      p[turn].pop_front();
      deck.push_front(card);

      if (fcount.count(card)) {
        last_face = turn;
        cover_count = fcount[card] + 1;
        turn = (turn + 1) % 2;
      }

      if (cover_count) {
        --cover_count;

        if (!cover_count) {
          while (!deck.empty()) {
            p[last_face].push_back(deck.back());
            deck.pop_back();
          }

          turn = last_face;
        }
      } else {
        turn = (turn + 1) % 2;
      }
    }

    int winner = (turn + 1) % 2;
    printf("%d%3d\n", winner + 1, sz(p[winner]));
  }
  return 0;
}
