//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1202

#include<queue>
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;



int main(){
    freopen("ferry_loading.txt","r",stdin);
    int c;
    cin >> c;
    for(int z=0;z<c;z++){
        int n,t,m,ferry,boole;
        cin >> n>> t>> m;

        ferry=0;
        queue<int> left,right;
        for(int i=0;i<m;i++){
            string s;
            int j;
            cin >> j >> s;
            if(s=="left"){
                left.push(j);
            }else{
                right.push(j);
            }
        }

        boole =1; //boole=1 is left; 2 is right;
        while(left.empty()==false || right.empty()==false){
            if(left.front()<right.front()){
                if(ferry<left.front()){
                    ferry=left.front();
                }
                if(boole==2){
                    ferry=ferry+t;
                    boole=1;

                }


                cout << (ferry+t) << endl;
                left.pop();
                int ferrySum;
                ferrySum=1;

                while(left.front()<=ferry && ferrySum<=n && left.empty()==false){
                    cout << (ferry+t) << endl;
                    ferrySum=ferrySum+1;
                    left.pop();

                }
                ferry=ferry+t;
                boole=2;
            }else{
                if(ferry<right.front()){
                    ferry=right.front();
                }
                 if(boole==1){
                    ferry=ferry+t;
                    boole=2;
                }

                cout << ferry+t << endl;
                right.pop();
                int ferrySum;
                ferrySum=1;
                while(right.front()<=ferry && ferrySum<=n && right.empty()==false){
                    cout << ferry+t << endl;
                    ferrySum=ferrySum+1;
                    right.pop();
                }
                ferry=ferry+t;
                boole=1;
            }
        }
        cout << endl;
    }

    return 0;
}
