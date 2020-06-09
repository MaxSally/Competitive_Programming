#include<vector>
#include<iostream>
#include<string.h>
#include<cstdio>
#include<stack>
    using namespace std;

int compare(char c){
    if(c=='+' || c=='-'){
        return 1;
    }else if(c=='*' || c=='/'){
        return 2;
    }else if(c=='^'){
        return 3;
    }else{
        return 0;
    }

}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("polish_notation.txt", "r", stdin);
    int n;
    cin >> n;
    //cin.ignore();
    char s[405];
    for(int j=0;j<n;j++){

        cin >>s;
        int a1=strlen(s);
        stack<char> c;
        for(int i=0;i<a1;i++){
            int a=compare(s[i]);
            if(s[i]=='('){
                c.push(s[i]);
            }else if( s[i]==')'){
                while(c.top()!='(' && c.empty()==false){
                    cout << c.top();
                    c.pop();
                }
                c.pop();
            }else if (a==0){
                cout << s[i];
            }else if (a!=0){
                while(c.empty()==false && c.top() !='(' && compare(c.top())>=a){
                    cout << c.top();
                    c.pop();
                }
                c.push(s[i]);
            }
        }

        cout << endl;
    }
    return 0;
}
