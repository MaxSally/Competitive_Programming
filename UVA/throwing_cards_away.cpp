//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1876

#include<queue>
#include<iostream>
#include<stdio.h>
#include<vector>
    using namespace std;

int main(){
    //freopen("card.txt", "r", stdin);
    while(true){
        int n;
        cin >> n;
        if(n==0){
            break;
        }
        queue<int> a;
        vector<int> discardedCard; //b: discarded card
        for(int i=1;i<=n;i++){
            a.push(i);
        }
        while(a.size()>1){
            discardedCard.push_back(a.front());
            a.pop();
            if(a.size() == 0){
                break;
            }
            a.push(a.front());
            a.pop();

        }
        cout << "Discarded cards:";
        if(discardedCard.size() != 0){
           cout << " "<< discardedCard[0];
            for(int i=1;i<n-1;i++){
                cout << ", " << discardedCard[i];
            }

        }

        cout << endl;
        cout << "Remaining card: " << a.front() << endl;
    }
    return 0;
}

