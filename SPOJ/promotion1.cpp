//http://www.spoj.com/problems/PRO/


#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
    using namespace std;
priority_queue<int> pqMax,pqMinRemove;
priority_queue<int, vector<int>, greater<int> > pqMin,pqMaxRemove;




int main(){
    freopen("promotion.txt","r",stdin);
    int day;
    long res=0;
    cin>> day;
    for(int ii=0;ii<day;ii++){
        int n;

        cin >>n;
        for(int i=0;i<n;i++){
            int temp;
            cin >> temp;
            pqMin.push(temp);
            pqMax.push(temp);
        }


        int a,b;
        while(true){
            a=pqMin.top();
            if( pqMaxRemove.empty() || a!=pqMaxRemove.top()){
                break;
            }else{
                pqMaxRemove.pop();
                pqMin.pop();
            }
        }

        while(true){
            b=pqMax.top();
            if(pqMinRemove.empty() || b!=pqMinRemove.top()){
                break;
            }else{
                pqMinRemove.pop();
                pqMax.pop();
            }
        }




        res+=b-a;
        cout << a << " "<<b << " " << res<< endl;


        pqMinRemove.push(a);
        pqMaxRemove.push(b);

        pqMin.pop();
        pqMax.pop();


    }
    cout << res;

    return 0;
}
