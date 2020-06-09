//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3146

#include<vector>
#include<functional>
#include<iostream>
#include<stdio.h>
#include<queue>
#include<stack>
    using namespace std;


bool s1,q1,pq1;



int main(){

    int n;

    while(cin>> n){
        s1=1;
        q1=1;
        pq1=1;
        int cnt=0;
        priority_queue<int> pq;
        queue<int> q;
        stack<int> s;


        for(int i=0;i<n;i++){
            int a,b;
            cin >> a >> b;
            if(a==1){

                q.push(b);
                s.push(b);
                pq.push(b);
            }else{

                if(s1==1){
                    if(s.empty()){
                        s1=0;
                        //cnt++;
                    }
                    else{
                        if(s.top()==b){
                            s.pop();
                        }
                        else{
                            s1=0;
                            //cnt++;
                        }
                    }
                }


                if(q1==1){
                    if(q.empty()){
                        q1=0;
                        //cnt++;
                    }
                    else{
                        if(q.front()==b){
                            q.pop();
                        }
                        else{
                            q1=0;
                            //cnt++;
                        }
                    }
                }

                if(pq1==1){
                    if(pq.empty()){
                        pq1=0;
                        //cnt++;
                    }
                    else{
                        if(pq.top()==b){
                            pq.pop();
                        }
                        else{
                            pq1=0;
                            //cnt++;
                        }
                    }
                }

            }


        }
        cnt = !s1 + !q1 + !pq1;
        //cout<<s1<<" "<<q1<<" "<<pq1<<endl;
        if(cnt==3){
            cout << "impossible" << endl;
        }else if(cnt==2){
            if(q1==1){
                cout << "queue" << endl;
            }else if(s1==1){
                cout << "stack" << endl;
            }else if(pq1==1){
                cout << "priority queue" << endl;
            }
        }else if(cnt<2){
            cout << "not sure" << endl;
        }

    }
    return 0;
}

/*
if (type == 1) {
                S.push(x);
                Q.push(x);
                PQ.push(x);
            }
            else {
                if (S.empty()) {
                    isStack = isQueue = isPQ = false;
                }
                else {
                    int tS = S.top();
                    int tQ = Q.front();
                    int tPQ = PQ.top();

                    S.pop(); Q.pop(); PQ.pop();

                    if (tS != x)
                        isStack = false;
                    if (tQ != x)
                        isQueue = false;
                    if (tPQ != x)
                        isPQ = false;
                }
            }
*/


