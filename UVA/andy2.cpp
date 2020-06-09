
//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1756
#include<vector>
#include<stdio.h>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
    using namespace std;


string t;
set<string> dict;



void standardized(string &s){
    while(s.empty()==false && isalpha(s[0])==0){
        s.erase(s.begin()+0);
    }
    while(s.empty()==false && isalpha(s[s.size()-1])==0){
        s.erase(s.begin()+s.size()-1);
    }
}


int main(){
    freopen("andy_dict.txt","r",stdin);
    string temp;
    while(cin >> t){
        for(int i=0;i<t.size();i++){
            if(t[i]!='-' || (t[i]=='-' && i!=t.size()-1)){
                if(isalpha(t[i])==0 && t[i]!='-'){
                    temp.push_back(' ');
                }else{
                    t[i] = tolower(t[i]);
                    temp.push_back((t[i]));
                }
            }
        }
        if(t[t.size()-1]!='-'){
            temp.push_back(' ');
        }
    }

    //cout<<temp<<endl;
    stringstream ss(temp);
    while(ss>>temp){
        dict.insert(temp);
    }
    set<string>:: iterator it;
    for(it=dict.begin();it!=dict.end();it++){
        cout << *it << endl;
    }
    cout << dict.size();

    return 0;
}
