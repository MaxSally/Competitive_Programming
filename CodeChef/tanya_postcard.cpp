//codeforces.com/problemset/problem/518/B

#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<string>
    using namespace std;

int y,w;
map<char,int> a,b;
string s,t;


void findYayAndWhoops(){
    for(int i=0;i<26;i++){
        int temp=min(a[char(i+65)],b[char(i+65)]);
        y+=temp;
        a[char(i+65)]-=temp;
        b[char(i+65)]-=temp;
    }
    for(int i=0;i<26;i++){
        int temp=min(a[char(i+97)],b[char(i+97)]);
        y+=temp;
        a[char(i+97)]-=temp;
        b[char(i+97)]-=temp;
    }
    for(int i=0;i<26;i++){
        w+=min(a[char(i+65)]+a[char(i+97)],b[char(i+65)]+b[char(i+97)]);
    }



}

int main(){
    freopen("input.txt","r",stdin);

    cin >> s;
    cin >> t;
    y=0;
    w=0;
    for(int i=0;i<26;i++){
        a[char(i+65)]=0;
        b[char(i+65)]=0;
    }
    for(int i=0;i<26;i++){
        a[char(i+97)]=0;
        b[char(i+97)]=0;
    }
    for(int i=0;i<s.length();i++){
        a[s[i]]++;
    }
    for(int i=0;i<t.length();i++){
        b[t[i]]++;
    }
    findYayAndWhoops();
    cout << y <<" "<< w;


    return 0;
}

