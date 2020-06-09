//http://acm.timus.ru/problem.aspx?num=1585

#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
#include<algorithm>
    using namespace std;


struct classcomp {
  bool operator() (const string& lhs, const string& rhs) const
  {return lhs>rhs;}
};



map<string,int,classcomp> penguin;
string s;

void check(){
    map<string,int,classcomp>:: iterator it;
    it=penguin.find(s);
    if(it==penguin.end()){
        penguin.insert(make_pair(s,1));
    }else{
        penguin[s] ++;
    }
    //cout<<s<< " "<<penguin.size()<<endl;
}



int main(){
    freopen("penguins.txt","r",stdin);
    int n;
    cin >> n;
    getline(cin,s);
    for(int i=0;i<n;i++){
        getline(cin,s);
        check();
    }
    //cout<<penguin.size();
    map<string,int,classcomp>:: iterator it;
    it=penguin.begin();
    int maxN=0;
    string ans="";
    for(it=penguin.begin();it!=penguin.end();it++){
        if(it->second > maxN){
            maxN = it->second;
            ans = it->first;
        }
    }
    cout << ans;

    return 0;
}





