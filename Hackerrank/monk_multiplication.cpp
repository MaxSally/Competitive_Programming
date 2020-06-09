//https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-multiplication/
#include<stdio.h>
#include<iostream>
#include<vector>
    using namespace std;
//Max Heap

vector< long > vec;
int n;

void add(){
    int i=vec.size()-1;
    while(i>=0 && vec[i]>vec[(i-1)/2]){
        swap(vec[i],vec[(i-1)/2]);
        i=(i-1)/2;
    }


}




int main(){;
    freopen("monk_multiplication.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cout << -1 << endl << -1 << endl;
    long temp, temp1;
    cin >> temp >> temp1;
    vec.push_back(temp);
    vec.push_back(temp1);
    if(vec[0]<vec[1]){
        swap(vec[0],vec[1]);
    }
    for(int i=2;i<n;i++){
        int temp2;
        cin >> temp2;
        vec.push_back(temp2);
        add();

        long long res=vec[0];

        if(vec[1]>vec[2]){
            res*=vec[1];

            temp=vec[2];

            for(int j=1;j<=2;j++){
                if(2+j<vec.size() && temp<vec[2+j]){
                   temp=vec[2+j];

                }


            }

            res=res*temp;

        }else{

            res*=vec[2];
            temp=vec[1];

            for(int j=1;j<=2;j++){
                if(4+j<vec.size() && temp<vec[4+j]){
                    temp=vec[4+j];

                }

            }

            res=res*temp;
        }


        cout << res << endl;

    }
    return 0;
}
