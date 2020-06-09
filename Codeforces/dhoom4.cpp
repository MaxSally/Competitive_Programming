#include<vector>
#include<iostream>
#include<stdio.h>
#include<queue>
    using namespace std;

vector<long> a,visited;

queue<long> b;

long BFS(int f){
    long zA=a.size();
    int cnt=1;
    while(true){
        long zB=b.size();

        for(int i=0;i<zB;i++){
            int s=b.front();

            b.pop();
            for(int j=0;j<zA;j++){
                if(a[j]!=s){
                    long z1=(s*a[j])%100000;

                    if(z1!=f){
                        if(visited[z1]==0){
                            visited[z1]=1;
                            b.push(z1);
                        }


                    }else{
                        return cnt;
                    }
                }
            }

        }
        cnt++;
        if(b.empty()==true){
            return -1;
        }
    }

}


int main(){
    freopen("dhoom4.txt","r",stdin);
    visited.resize(100001,0);

    int s,f,n;
    long cnt;
    cnt=0;
    cin >> s >> f >> n;
    b.push(s);
    visited[s]=1;
    for(int i=0;i<n;i++){
        long z;
        cin >> z;

        a.push_back(z);
        visited[z]=1;


    }
    cnt=BFS(f);
    cout << cnt;
    return 0;
}
