#include <iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<functional>
using namespace std;
priority_queue<int> pqMin, pqMaxRemove;
priority_queue<int, vector<int>, greater<int> > pqMax, pqMinRemove;
vector<int> all;

bool findN(int f){

    for(int i=0;i<all.size();i++){
        if(all[i]==f){
            swap(all[i],all[all.size()-1]);
            all.pop_back();
            return 1;
        }
    }
    return 0;


}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("temp.txt", "r",stdin);
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int a;
        cin >> a;
        if(a==1){
            int b;
            cin >> b;

            pqMax.push(b);
            pqMin.push(b);
            all.push_back(b);
        }else if(a==2){
            int b;
            cin >> b;
            if(findN(b)==0){
                cout << -1 << endl;
            }else{
                //cout << b << " 2"<< endl;
                pqMaxRemove.push(b);
                pqMinRemove.push(b);
            }

        }else if (a==4){


            while(!pqMinRemove.empty() && pqMax.top()==pqMinRemove.top()){
                //cout << pqMax.top() << " 1"<<endl;
                pqMax.pop();
                pqMinRemove.pop();
            }
            if(pqMax.empty()){
                cout << -1 << endl;
            }else{
                cout << pqMax.top() << endl;
            }

        }else if(a==3){
            while(!pqMaxRemove.empty() && pqMin.top()==pqMaxRemove.top()){
                pqMin.pop();
                pqMaxRemove.pop();
            }
            if(pqMin.empty()){
                cout << -1 << endl;
            }else{
                cout << pqMin.top() << endl;
            }

        }
    }
    return 0;
}
