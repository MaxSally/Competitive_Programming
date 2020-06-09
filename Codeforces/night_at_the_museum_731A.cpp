#include<string>
#include<iostream>
#include<stdio.h>
    using namespace std;

int min(int a, int b){

    if(a<b){
        return a;
    }else{
        return b;
    }
}

int main(){
    freopen("731A.txt","r",stdin);
    string s,b;
    cin >> s;
    b="abcdefghijklmnopqrstuvwxyz";
    int a,res;
    a=s.length();
    res=0;
    for(int i=0;i<a;i++){
        int pos=b.find(s[i]);
        int c=min(pos,26-pos);
        res=res+c;

            b.append(b,0,pos);
            b.erase(0,pos);

    }
    cout << res;
    return 0;
}
