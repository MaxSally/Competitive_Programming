//http://acm.timus.ru/problem.aspx?space=1&num=1196

#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
    using namespace std;

map<int,int> pro,stu;
map<int,int>::iterator itP,itS;
int ans=0;
int main(){
    freopen("history.txt","r",stdin);
    int n,m;
    cin >> n;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        pro[temp]=0;
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int temp;
        cin >> temp;
        if(stu.find(temp)!=stu.end()){
            stu[temp]++;
        }else{
            stu[temp]=1;
        }

    }
    for(itP=stu.begin();itP!=stu.end();itP++){
        if(pro.find(itP->first)!=pro.end()){
            ans+=itP->second;
        }
    }
    cout << ans;




}





