#include<string>
#include<iostream>
#include<stdio.h>

    using namespace std;

string organize(string s){
    string a;
    int z1;
    z1=s.length();
    for(int i=0;i<z1;i++){
        int res;
        res= isalpha(s[i]);
        if(res !=0){
            s[i]=tolower(s[i]);
            a.push_back(s[i]);
        }


    }


    return a;

}



int main(){
    freopen("61B.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a,b,c,d,e,f,g,h,j;
    int n;
    cin >> a >> b >> c >>n;

    int a1,b1,c1;

    a=organize(a);
    b=organize(b);
    c=organize(c);

    a1=a.length();
    b1=b.length();
    c1=c.length();

    d=a+b+c;
    e=a+c+b;
    f=b+a+c;
    g=b+c+a;
    h=c+a+b;
    j=c+b+a;



    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        int s1=s.length();
        s=organize(s);

        if(s.compare(d)==0){
            cout << "ACC"  << endl;
        }else if(s.compare(e)==0){
            cout << "ACC"  << endl;
        }else if(s.compare(f)==0){
            cout << "ACC"  << endl;
        }else if(s.compare(g)==0){
            cout << "ACC"  << endl;
        }else if(s.compare(h)==0){
            cout << "ACC"  << endl;
        }else if(s.compare(j)==0){
            cout << "ACC"  << endl;
        }else {
            cout << "WA"  << endl;
        }




    }
    return 0;
}
