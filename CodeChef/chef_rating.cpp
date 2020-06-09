//https://www.codechef.com/problems/RRATING

#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
    using namespace std;

priority_queue<int> pq;
queue<int> q;

int main(){
    freopen("chef_rating.txt","r",stdin);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        if(a==1){
            int b;
            cin >> b;
            pq.push(b);
        }else{
            if(pq.size()>=3){

                int temp=pq.size()/3;
                for(int i=0;i<temp;i++){
                    q.push(pq.top());
                    pq.pop();

                }
                cout << q.back() << endl;
                while(!q.empty()){
                    pq.push(q.front());
                    q.pop();

                }
            }else{
                cout << "No reviews yet" << endl;
            }
        }

    }
    return 0;
}



