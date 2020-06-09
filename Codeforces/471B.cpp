#include<iostream>
#include<vector>
#include<stdio.h>
#include<functional>
#include<algorithm>
    using namespace std;

int n;
vector<int> visited;
vector<pair<int,int> > plan;


bool compare(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}

void swap(int a){
    pair<int,int> temp;
    temp=make_pair(plan[a].first,plan[a].second);
    plan[a].first=plan[a+1].first;
    plan[a].second=plan[a+1].second;
    plan[a+1].first=temp.first;
    plan[a+1].second=temp.second;
}

void print(){
    for(int i=0;i<n;i++){
        cout << plan[i].second << " ";
    }
    cout << endl;
}

int main(){
    freopen("471B.txt","r",stdin);

    cin >> n;


    //plan.resize(2005);
    for(int i=0;i<n;i++){
        int h;
        cin >> h;
        plan.push_back(make_pair(h,i));

    }
    sort(plan.begin(),plan.end(),compare);

    for(int i=0;i<n-1;i++){
        if(plan[i].first==plan[i+1].second){
            visited.push_back(i);
            if(visited.size()==2){
                break;
            }
        }
    }
    swap(visited[0]);
    print();
    swap(visited[0]);
    swap(visited[1]);
    print();
    swap(visited[0]);
    print();




    return 0;
}
