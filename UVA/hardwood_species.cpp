
//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1167

#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
#include<iomanip>
    using namespace std;

set<pair<string,int> > store;
string s;

void check(){
    set<pair<string,int> > :: iterator it;

    it=store.lower_bound(make_pair(s,0));
    if(it==store.end() || (*it).first!=s){

        store.insert(make_pair(s,1));
    }else{
        //cout<<"IN"<<endl;
        int temp=(*it).second+1;
        store.erase(it);
        store.insert(make_pair(s,temp));
    }

    //store.insert(make_pair(s,1));

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("hardwood_species.txt","r",stdin);
    int t;
    cin >> t;
    getline(cin,s);
    getline(cin,s);
    for(int ii=0;ii<t;ii++){
        //cout<<ii<<endl;
        store.clear();


        while(getline(cin,s )){
            if(s=="")
                break;
            //cout<<s<<endl;
            check();
            s ="";
        }
        int sum=0;
        set<pair<string,int> > :: iterator it;
        for(it=store.begin();it!=store.end();it++){
            sum+=(*it).second;
        }
        for(it=store.begin();it!=store.end();it++){
            cout << (*it).first << " " << fixed << setprecision(4) << (*it).second*1.0/sum*100 << endl;
        }
        if(ii!=t-1){
            cout << endl;
        }
    }
    return 0;
}
